#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal* result) {
  int status = SUCCESS;
  if (result == NULL) {
    status = FAIL;
  } else {
    *result = value;
    if (get_sign(value)) {
      delete_sign(result);
    } else {
      set_sign(result);
    }
  }
  return status;
}
