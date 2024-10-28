#include "s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int status;
  uint8_t zero_1 = is_zero(value_1);
  uint8_t zero_2 = is_zero(value_2);
  if (zero_1 && zero_2) {
    status = TRUE;
  } else {
    reduce_power(&value_1);
    reduce_power(&value_2);
    uint8_t is_equal_sign = get_sign(value_1) == get_sign(value_2);
    uint8_t is_equal_power = get_power(value_1) == get_power(value_2);
    status = is_equal(value_1, value_2) && is_equal_sign && is_equal_power;
  }
  return status;
}
