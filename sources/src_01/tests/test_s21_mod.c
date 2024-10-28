#include "test_s21_decimal.h"

START_TEST(test_s21_mod_01) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_02) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_03) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_04) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_05) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_sign(&val_1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_06) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_07) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_08) {
  s21_decimal val_1 = {{11}};
  s21_decimal val_2 = {{4}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_09) {
  s21_decimal val_1 = {{11}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{0}};
  s21_decimal val_res;

  set_power(&val_2, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_10) {
  s21_decimal val_1 = {{11}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);
  set_sign(&val_ans);

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

Suite* suite_s21_mod() {
  Suite* s = suite_create("s21_mod");
  TCase* tc = tcase_create("s21_mod_tc");

  tcase_add_test(tc, test_s21_mod_01);
  tcase_add_test(tc, test_s21_mod_02);
  tcase_add_test(tc, test_s21_mod_03);
  tcase_add_test(tc, test_s21_mod_04);
  tcase_add_test(tc, test_s21_mod_05);
  tcase_add_test(tc, test_s21_mod_06);
  tcase_add_test(tc, test_s21_mod_07);
  tcase_add_test(tc, test_s21_mod_08);
  tcase_add_test(tc, test_s21_mod_09);
  tcase_add_test(tc, test_s21_mod_10);

  suite_add_tcase(s, tc);
  return s;
}
