#include "s21_decimal.h"

uint8_t get_bit(s21_decimal number, uint8_t index) {
  return (number.bits[index / 32] >> (index % 32)) & 1u;
}

uint8_t get_double_bit(s21_double_decimal number, uint8_t index) {
  return (number.bits[index / 32] >> (index % 32)) & 1u;
}

void set_bit(s21_decimal* number, uint8_t index, uint8_t value) {
  if (value == 1) {
    number->bits[index / 32] = number->bits[index / 32] | (1u << index % 32);
  } else if (value == 0) {
    number->bits[index / 32] = number->bits[index / 32] & ~(1u << index % 32);
  }
}

void set_double_bit(s21_double_decimal* number, uint8_t index, uint8_t value) {
  if (value == 1) {
    number->bits[index / 32] = number->bits[index / 32] | (1u << index % 32);
  } else if (value == 0) {
    number->bits[index / 32] = number->bits[index / 32] & ~(1u << index % 32);
  }
}

uint8_t get_sign(s21_decimal number) { return get_bit(number, 96 + SIGN); }

void set_sign(s21_decimal* number) {
  uint32_t mask = 1u << SIGN;
  number->bits[3] |= mask;
}

void delete_sign(s21_decimal* number) {
  uint32_t mask = ~(1u << SIGN);
  number->bits[3] &= mask;
}

uint8_t get_power(s21_decimal number) {
  uint8_t res = 0;
  for (int i = 0; i < END_POWER - START_POWER; i++) {
    res += (1u << i) * get_bit(number, 96 + START_POWER + i);
  }
  return res;
}

void set_power(s21_decimal* number, uint8_t power) {
  for (int i = START_POWER; i <= END_POWER; i++, power /= 2) {
    if (power > 0 && power % 2 == 1) {
      number->bits[3] = number->bits[3] | (1u << i);
    } else {
      number->bits[3] = number->bits[3] & ~(1u << i);
    }
  }
}

void shift_left_double(s21_double_decimal* number) {
  number->bits[5] <<= 1u;
  if (get_double_bit(*number, 159)) set_double_bit(number, 160, 1);
  number->bits[4] <<= 1u;
  if (get_double_bit(*number, 127)) set_double_bit(number, 128, 1);
  number->bits[3] <<= 1u;
  if (get_double_bit(*number, 95)) set_double_bit(number, 96, 1);
  number->bits[2] <<= 1u;
  if (get_double_bit(*number, 63)) set_double_bit(number, 64, 1);
  number->bits[1] <<= 1u;
  if (get_double_bit(*number, 31)) set_double_bit(number, 32, 1);
  number->bits[0] <<= 1u;
}

void shift_right_double(s21_double_decimal* number) {
  number->bits[0] >>= 1u;
  if (get_double_bit(*number, 32)) set_double_bit(number, 31, 1);
  number->bits[1] >>= 1u;
  if (get_double_bit(*number, 64)) set_double_bit(number, 63, 1);
  number->bits[2] >>= 1u;
  if (get_double_bit(*number, 96)) set_double_bit(number, 95, 1);
  number->bits[3] >>= 1u;
  if (get_double_bit(*number, 128)) set_double_bit(number, 127, 1);
  number->bits[4] >>= 1u;
  if (get_double_bit(*number, 160)) set_double_bit(number, 159, 1);
  number->bits[5] >>= 1u;
}

void shift_count_double(s21_double_decimal* number, uint8_t count) {
  for (int i = 0; i < count; i++) shift_left_double(number);
}
