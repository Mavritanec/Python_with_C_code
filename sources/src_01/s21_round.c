#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal* result) {
  int status = SUCCESS;
  if (result == NULL) {
    status = FAIL;
  } else {
    uint8_t sign = get_sign(value);
    s21_double_decimal val_d = {0};
    from_decimal_to_double_decimal(value, &val_d);
    s21_double_decimal mod = {{10}};
    s21_double_decimal tmp = {0};
    for (int i = 0; i < get_power(value); i++)
      tmp = division(val_d, mod, &val_d);
    if (tmp.bits[0] >= 5) plus_one(val_d, &val_d);
    from_double_decimal_to_decimal(val_d, 0, sign, result);
  }
  return status;
}
