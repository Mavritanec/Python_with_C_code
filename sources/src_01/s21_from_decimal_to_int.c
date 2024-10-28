#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int* dst) {
  int status = SUCCESS;
  if (dst == NULL) {
    status = FAIL;
  } else {
    *dst = 0;
    s21_double_decimal src_d = {0};
    s21_double_decimal mod = {{pow(10, get_power(src))}};
    from_decimal_to_double_decimal(src, &src_d);
    division(src_d, mod, &src_d);
    if (significant_bit_double(&src_d) > 30) {
      status = FAIL;
    } else {
      for (int i = 0; i < 31; i++) {
        if (get_double_bit(src_d, i)) *dst += pow(2, i);
      }
      if (get_sign(src)) *dst *= -1;
    }
  }
  return status;
}
