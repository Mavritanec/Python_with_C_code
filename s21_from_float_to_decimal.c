#include "s21_decimal.h"

typedef union {
  uint32_t like_int;
  float like_float;
} number;

int16_t get_bin_power(number src);
void convert_float_to_decimal(uint8_t sign, uint8_t dec_pow, int16_t bin_pow,
                              number value, s21_decimal* dst);

int s21_from_float_to_decimal(float src, s21_decimal* dst) {
  int status = SUCCESS;
  if (dst == NULL || isinf(src) || isnan(src)) {
    status = FAIL;
  } else {
    init_decimal(dst);
    number value;
    value.like_float = src;
    int16_t src_pow = get_bin_power(value);
    if (src != 0.0) {
      double src_d = (double)src;
      uint8_t dst_pow = 0;
      while (!((int)(src_d / 1E7))) {
        src_d *= 10;
        dst_pow++;
      }
      while (!fmod(src_d, 10.0) && dst_pow > 0) {
        src_d /= 10;
        dst_pow--;
      }
      if (dst_pow <= 28 && (src_pow > -95 && src_pow <= 95)) {
        value.like_float = src_d;
        src_pow = get_bin_power(value);
        uint8_t sign = (src < 0) ? 1 : 0;
        convert_float_to_decimal(sign, dst_pow, src_pow, value, dst);
        reduce_power(dst);
      } else {
        status = FAIL;
      }
    }
  }
  return status;
}

int16_t get_bin_power(number src) {
  int16_t result = 0;
  for (int i = 30; i > 22; i--) {
    if (src.like_int & (1u << i)) result += pow(2, i - 23);
  }
  return result - 127;
}

void convert_float_to_decimal(uint8_t sign, uint8_t dec_pow, int16_t bin_pow,
                              number value, s21_decimal* dst) {
  set_bit(dst, bin_pow, 1);
  for (int i = 22; i >= 0; i--) {
    bin_pow--;
    if (value.like_int & (1u << i)) set_bit(dst, bin_pow, 1);
  }
  set_power(dst, dec_pow);
  if (sign) set_sign(dst);
}
