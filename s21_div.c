#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  init_decimal(result);
  int status = OK;
  if (is_zero(value_2)) {
    status = S21_NAN;
  } else {
    uint8_t sign = 0;
    if (get_sign(value_1) ^ get_sign(value_2)) sign = 1;
    uint8_t pow_1 = get_power(value_1);
    uint8_t pow_2 = get_power(value_2);
    uint8_t pow_d = 0;
    s21_double_decimal d_value_1 = {0};
    s21_double_decimal d_value_2 = {0};
    from_decimal_to_double_decimal(value_1, &d_value_1);
    from_decimal_to_double_decimal(value_2, &d_value_2);
    s21_double_decimal d_result = {0};
    s21_double_decimal mod = division(d_value_1, d_value_2, &d_result);
    uint8_t current_bit = significant_bit_double(&d_result);
    s21_double_decimal ten = {{10}};
    s21_double_decimal res = {0};
    while (!is_zero_double(mod) && current_bit < 188) {
      multiplication(mod, ten, &mod);
      mod = division(mod, d_value_2, &res);
      multiplication(d_result, ten, &d_result);
      summation(d_result, res, &d_result);
      current_bit = significant_bit_double(&d_result);
      pow_d++;
    }
    if (pow_1 + pow_d <= pow_2) {
      for (int i = 0; i < pow_2; i++) multiplication(d_result, ten, &d_result);
      status =
          from_double_decimal_to_decimal(d_result, pow_1 + pow_d, sign, result);
    } else {
      status = from_double_decimal_to_decimal(d_result, pow_1 + pow_d - pow_2,
                                              sign, result);
    }
    if (!status) reduce_power(result);
  }
  return status;
}
