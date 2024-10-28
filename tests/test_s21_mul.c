#include "test_s21_decimal.h"

START_TEST(test_s21_mul_01) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_2, i, 1);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, POSITIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_02) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_2, i, 1);

  set_sign(&val_1);
  set_sign(&val_2);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, POSITIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_03) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_2, i, 1);

  set_sign(&val_1);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, NEGATIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_04) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_2, i, 1);

  set_sign(&val_2);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, NEGATIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_05) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{25}};
  s21_decimal val_res;

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_06) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{25}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_07) {
  s21_decimal val_1 = {{55}};
  s21_decimal val_2 = {{55}};
  s21_decimal val_ans = {{3025}};
  s21_decimal val_res;

  set_power(&val_1, 1);
  set_power(&val_2, 1);
  set_power(&val_ans, 2);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_08) {
  s21_decimal val_1 = {{55}};
  s21_decimal val_2 = {{55}};
  s21_decimal val_ans = {{3025}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  set_power(&val_1, 1);
  set_power(&val_2, 1);
  set_power(&val_ans, 2);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_09) {
  s21_decimal val_1 = {{125}};
  s21_decimal val_2 = {{4}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  set_power(&val_1, 2);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_10) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{1}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_ans, i, 1);

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mul_11) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {{874819695, 3955400582, 340282366, 0}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_2, i, 1);

  set_power(&val_1, 20);
  set_power(&val_2, 20);
  set_power(&val_ans, 10);

  int res = s21_mul(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

Suite* suite_s21_mul() {
  Suite* s = suite_create("s21_mul");
  TCase* tc = tcase_create("s21_mul_tc");

  tcase_add_test(tc, test_s21_mul_01);
  tcase_add_test(tc, test_s21_mul_02);
  tcase_add_test(tc, test_s21_mul_03);
  tcase_add_test(tc, test_s21_mul_04);
  tcase_add_test(tc, test_s21_mul_05);
  tcase_add_test(tc, test_s21_mul_06);
  tcase_add_test(tc, test_s21_mul_07);
  tcase_add_test(tc, test_s21_mul_08);
  tcase_add_test(tc, test_s21_mul_09);
  tcase_add_test(tc, test_s21_mul_10);
  tcase_add_test(tc, test_s21_mul_11);

  suite_add_tcase(s, tc);
  return s;
}
