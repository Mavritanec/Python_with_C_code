#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int status;
  uint8_t sign_1 = get_sign(value_1);
  uint8_t sign_2 = get_sign(value_2);
  uint8_t pow_1 = get_power(value_1);
  uint8_t pow_2 = get_power(value_2);
  s21_double_decimal d_value_1 = {0};
  s21_double_decimal d_value_2 = {0};
  from_decimal_to_double_decimal(value_1, &d_value_1);
  from_decimal_to_double_decimal(value_2, &d_value_2);
  normalization(&d_value_1, pow_1, &d_value_2, pow_2);
  if (sign_1 && sign_2) {
    status = is_less_double(d_value_2, d_value_1);
  } else if (!sign_1 && !sign_2) {
    status = is_less_double(d_value_1, d_value_2);
  } else {
    status = (sign_1) ? TRUE : FALSE;
  }
  return status;
}
