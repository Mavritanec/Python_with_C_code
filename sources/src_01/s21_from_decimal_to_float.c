#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float* dst) {
  int status = SUCCESS;
  if (dst == NULL) {
    status = FAIL;
  } else {
    long double num = 0;
    for (int i = 0; i < 96; i++)
      if (get_bit(src, i)) num += pow(2, i);
    num = num / pow(10, get_power(src));
    if (get_sign(src)) num *= -1;
    *dst = (float)num;
  }
  return status;
}
