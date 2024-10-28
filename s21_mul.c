#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  init_decimal(result);
  int status = OK;
  uint8_t sign = 0;
  if (get_sign(value_1) ^ get_sign(value_2)) sign = 1;
  uint8_t pow = get_power(value_1) + get_power(value_2);
  s21_double_decimal d_value_1 = {0};
  s21_double_decimal d_value_2 = {0};
  from_decimal_to_double_decimal(value_1, &d_value_1);
  from_decimal_to_double_decimal(value_2, &d_value_2);
  s21_double_decimal d_result = {0};
  multiplication(d_value_1, d_value_2, &d_result);
  status = from_double_decimal_to_decimal(d_result, pow, sign, result);
  if (!status) reduce_power(result);
  return status;
}
