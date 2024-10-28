#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  init_decimal(result);
  int status = OK;
  if (is_zero(value_2)) {
    status = S21_NAN;
  } else {
    uint8_t sign_1 = get_sign(value_1);
    uint8_t sign_2 = get_sign(value_2);
    uint8_t sign = 0;
    uint8_t pow_1 = get_power(value_1);
    uint8_t pow_2 = get_power(value_2);
    uint8_t pow = (pow_1 > pow_2) ? pow_1 : pow_2;
    s21_double_decimal d_value_1 = {0};
    s21_double_decimal d_value_2 = {0};
    from_decimal_to_double_decimal(value_1, &d_value_1);
    from_decimal_to_double_decimal(value_2, &d_value_2);
    normalization(&d_value_1, pow_1, &d_value_2, pow_2);
    s21_double_decimal tmp = {0};
    s21_double_decimal d_result = {0};
    d_result = division(d_value_1, d_value_2, &tmp);
    if (sign_1 && sign_2) {
      sign = 1;
    } else if (!sign_1 && sign_2) {
      subtraction(d_value_2, d_result, &d_result);
      sign = 1;
    } else if (sign_1 && !sign_2) {
      subtraction(d_value_2, d_result, &d_result);
    }
    status = from_double_decimal_to_decimal(d_result, pow, sign, result);
    if (!status) reduce_power(result);
  }
  return status;
}
