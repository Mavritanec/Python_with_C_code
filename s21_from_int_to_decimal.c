#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int status = SUCCESS;
  if (dst == NULL /*|| isinf(src) || isnan(src)*/) {
    status = FAIL;
  } else {
    init_decimal(dst);
    uint8_t sign = (src < 0) ? 1 : 0;
    if (sign) src *= -1;
    dst->bits[0] = src;
    if (sign) set_sign(dst);
  }
  return status;
}
