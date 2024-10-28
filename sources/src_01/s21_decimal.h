#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdint.h>
#include <stdio.h>

#define START_POWER 16
#define END_POWER 23
#define SIGN 31

typedef enum { OK, POSITIVE_INF, NEGATIVE_INF, S21_NAN } arithmetic;
typedef enum { FALSE, TRUE } comparasion;
typedef enum { SUCCESS, FAIL } result;

typedef struct {
  uint32_t bits[4];
} s21_decimal;

typedef struct {
  uint32_t bits[6];
} s21_double_decimal;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);

int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);

uint8_t get_bit(s21_decimal number, uint8_t index);
uint8_t get_double_bit(s21_double_decimal number, uint8_t index);
void set_bit(s21_decimal* number, uint8_t index, uint8_t value);
void set_double_bit(s21_double_decimal* number, uint8_t index, uint8_t value);
uint8_t get_sign(s21_decimal number);
void set_sign(s21_decimal* number);
void delete_sign(s21_decimal* number);
uint8_t get_power(s21_decimal number);
void set_power(s21_decimal* number, uint8_t power);
void shift_left_double(s21_double_decimal* number);
void shift_right_double(s21_double_decimal* number);
void shift_count_double(s21_double_decimal* number, uint8_t count);

void init_decimal(s21_decimal* number);
void init_double_decimal(s21_double_decimal* number);
void from_decimal_to_double_decimal(s21_decimal number,
                                    s21_double_decimal* result);
uint8_t from_double_decimal_to_decimal(s21_double_decimal number, uint8_t pow,
                                       uint8_t sign, s21_decimal* result);
uint8_t is_zero(s21_decimal number);
uint8_t is_zero_double(s21_double_decimal number);
uint8_t is_equal(s21_decimal a, s21_decimal b);
uint8_t is_less_double(s21_double_decimal a, s21_double_decimal b);
uint8_t is_greater_double(s21_double_decimal a, s21_double_decimal b);
uint8_t is_greater_or_equal_double(s21_double_decimal a, s21_double_decimal b);
uint8_t significant_bit_double(s21_double_decimal* number);
void plus_one(s21_double_decimal number, s21_double_decimal* result);
void summation(s21_double_decimal a, s21_double_decimal b,
               s21_double_decimal* result);
void subtraction(s21_double_decimal a, s21_double_decimal b,
                 s21_double_decimal* result);
void multiplication(s21_double_decimal a, s21_double_decimal b,
                    s21_double_decimal* result);
s21_double_decimal division(s21_double_decimal a, s21_double_decimal b,
                            s21_double_decimal* result);
void normalization(s21_double_decimal* a, uint8_t pow_a, s21_double_decimal* b,
                   uint8_t pow_b);
void normalization_simple(s21_double_decimal* number, uint8_t diff_pow);
void reduce_power(s21_decimal* value);
uint8_t check_reduce_power(s21_decimal value);

#endif  //  SRC_S21_DECIMAL_H_
