#include "s21_decimal.h"

void init_decimal(s21_decimal* number) {
  number->bits[0] = 0;
  number->bits[1] = 0;
  number->bits[2] = 0;
  number->bits[3] = 0;
}

void init_double_decimal(s21_double_decimal* number) {
  number->bits[0] = 0;
  number->bits[1] = 0;
  number->bits[2] = 0;
  number->bits[3] = 0;
  number->bits[4] = 0;
  number->bits[5] = 0;
}

void from_decimal_to_double_decimal(s21_decimal number,
                                    s21_double_decimal* result) {
  result->bits[0] = number.bits[0];
  result->bits[1] = number.bits[1];
  result->bits[2] = number.bits[2];
}

uint8_t from_double_decimal_to_decimal(s21_double_decimal number, uint8_t pow,
                                       uint8_t sign, s21_decimal* result) {
  init_decimal(result);
  uint8_t status = OK;
  uint8_t over_pow = 0;
  s21_double_decimal mod = {0};
  s21_double_decimal ten = {{10}};
  while (significant_bit_double(&number) > 95) {
    mod = division(number, ten, &number);
    over_pow++;
  }
  int8_t res_pow = (int8_t)pow - (int8_t)over_pow;

  while (res_pow > 28) {
    mod = division(number, ten, &number);
    res_pow--;
  }
  if (res_pow < 0) {
    if (sign) {
      status = NEGATIVE_INF;
    } else {
      status = POSITIVE_INF;
    }
  } else {
    uint32_t val = mod.bits[0];
    if (val >= 5) plus_one(number, &number);
    result->bits[0] = number.bits[0];
    result->bits[1] = number.bits[1];
    result->bits[2] = number.bits[2];
    if (sign) set_sign(result);
    set_power(result, res_pow);
  }
  return status;
}

uint8_t is_zero(s21_decimal number) {
  return (!number.bits[0] && !number.bits[1] && !number.bits[2]);
}

uint8_t is_zero_double(s21_double_decimal number) {
  return (!number.bits[0] && !number.bits[1] && !number.bits[2] &&
          !number.bits[3] && !number.bits[4] && !number.bits[5]);
}

uint8_t is_equal(s21_decimal a, s21_decimal b) {
  uint8_t flag = TRUE;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(a, i) ^ get_bit(b, i)) {
      flag = FALSE;
      break;
    }
  }
  return flag;
}

uint8_t is_less_double(s21_double_decimal a, s21_double_decimal b) {
  uint8_t status = FALSE;
  for (int i = 191; i >= 0; i--) {
    if (get_double_bit(a, i) ^ get_double_bit(b, i)) {
      status = get_double_bit(b, i);
      break;
    }
  }
  return status;
}

uint8_t is_greater_double(s21_double_decimal a, s21_double_decimal b) {
  uint8_t status = FALSE;
  for (int i = 191; i >= 0; i--) {
    if (get_double_bit(a, i) ^ get_double_bit(b, i)) {
      status = get_double_bit(a, i);
      break;
    }
  }
  return status;
}

uint8_t is_greater_or_equal_double(s21_double_decimal a, s21_double_decimal b) {
  return !is_less_double(a, b);
}

uint8_t significant_bit_double(s21_double_decimal* number) {
  uint8_t count = 191;
  while (!get_double_bit(*number, count) && count > 0) count--;
  return count;
}

void plus_one(s21_double_decimal number, s21_double_decimal* result) {
  s21_double_decimal tmp = {{1}};
  summation(number, tmp, result);
}

void summation(s21_double_decimal a, s21_double_decimal b,
               s21_double_decimal* result) {
  init_double_decimal(result);
  uint8_t over = 0;
  for (int i = 0; i < 192; i++) {
    uint8_t bit_a = get_double_bit(a, i);
    uint8_t bit_b = get_double_bit(b, i);
    uint8_t compare = bit_a || bit_b;
    if (bit_a && bit_b) {
      if (over) set_double_bit(result, i, 1);
      over = 1;
    } else if (!over && compare) {
      set_double_bit(result, i, 1);
    } else if (over && !compare) {
      set_double_bit(result, i, 1);
      over = 0;
    }
  }
}

void subtraction(s21_double_decimal a, s21_double_decimal b,
                 s21_double_decimal* result) {
  init_double_decimal(result);
  uint8_t over = 0;
  for (int i = 0; i < 192; i++) {
    uint8_t bit_a = get_double_bit(a, i);
    uint8_t bit_b = get_double_bit(b, i);
    int8_t tmp = bit_a - bit_b - over;
    set_double_bit(result, i, (tmp + 2) % 2);
    over = (tmp < 0) ? 1 : 0;
  }
}

void multiplication(s21_double_decimal a, s21_double_decimal b,
                    s21_double_decimal* result) {
  init_double_decimal(result);
  for (int i = 0; !is_zero_double(b); i++) {
    s21_double_decimal tmp = {0};
    uint8_t bit_b = get_double_bit(b, 0);
    shift_right_double(&b);
    if (bit_b) {
      for (int j = 0; j < 192; j++) {
        uint8_t bit_a = get_double_bit(a, j);
        if (bit_a) set_double_bit(&tmp, j, 1);
      }
      shift_count_double(&tmp, i);
      summation(*result, tmp, result);
    }
  }
}

s21_double_decimal division(s21_double_decimal a, s21_double_decimal b,
                            s21_double_decimal* result) {
  init_double_decimal(result);
  uint8_t diff = significant_bit_double(&a) - significant_bit_double(&b);
  shift_count_double(&b, diff);
  for (int i = 0; i <= diff; i++) {
    shift_left_double(result);
    if (is_greater_or_equal_double(a, b)) {
      subtraction(a, b, &a);
      result->bits[0] += 1u;
    }
    shift_right_double(&b);
  }
  return a;
}

void normalization(s21_double_decimal* a, uint8_t pow_a, s21_double_decimal* b,
                   uint8_t pow_b) {
  if (pow_a > pow_b) {
    normalization_simple(b, pow_a - pow_b);
  } else if (pow_a < pow_b) {
    normalization_simple(a, pow_b - pow_a);
  }
}

void normalization_simple(s21_double_decimal* number, uint8_t diff_pow) {
  s21_double_decimal ten = {{10}};
  while (diff_pow > 0) {
    multiplication(*number, ten, number);
    diff_pow--;
  }
}

void reduce_power(s21_decimal* value) {
  uint8_t pow = get_power(*value);
  uint8_t sign = get_sign(*value);
  s21_double_decimal ten = {{10}};
  s21_double_decimal d_value = {0};
  from_decimal_to_double_decimal(*value, &d_value);
  while (check_reduce_power(*value) && pow) {
    pow--;
    division(d_value, ten, &d_value);
    from_double_decimal_to_decimal(d_value, pow, sign, value);
  }
}

uint8_t check_reduce_power(s21_decimal value) {
  uint8_t check = FALSE;
  if (!get_bit(value, 0)) {
    uint8_t res = 0;
    for (int i = 0; i < 96; i += 4) {
      uint8_t tetrad_res = 0;
      for (int j = 0; j < 4; j++)
        tetrad_res += (1u << j) * get_bit(value, i + j);
      res += tetrad_res;
    }
    if (res % 5 == 0) check = TRUE;
  }
  return check;
}
