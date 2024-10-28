#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal* result) {
  int status = SUCCESS;
  if (result == NULL) {
    status = FAIL;
  } else {
    uint8_t sign = get_sign(value);
    s21_double_decimal val_d = {0};
    s21_double_decimal mod = {{pow(10, get_power(value))}};
    from_decimal_to_double_decimal(value, &val_d);
    division(val_d, mod, &val_d);
    if (sign) plus_one(val_d, &val_d);
    from_double_decimal_to_decimal(val_d, 0, sign, result);
  }
  return status;
}
