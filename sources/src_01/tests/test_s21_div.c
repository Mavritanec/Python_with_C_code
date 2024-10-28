#include "test_s21_decimal.h"

START_TEST(test_s21_div_01) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_02) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_03) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_04) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_05) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_power(&val_1, 1);
  set_power(&val_ans, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_06) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{70}};
  s21_decimal val_res;

  set_power(&val_2, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_07) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_power(&val_1, 1);
  set_power(&val_2, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_08) {
  s21_decimal val_1 = {{3}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{15}};
  s21_decimal val_res;

  set_power(&val_ans, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_09) {
  s21_decimal val_1 = {{2}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{178956971, 695075222, 361400724, 0}};
  s21_decimal val_res;

  set_power(&val_ans, 28);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_10) {
  s21_decimal val_1 = {{7}};
  s21_decimal val_2 = {{4}};
  s21_decimal val_ans = {{175}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  set_power(&val_1, 1);
  set_power(&val_ans, 3);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_11) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{11}};
  s21_decimal val_ans = {{2245096541, 746944245, 591383003, 0}};
  s21_decimal val_res;

  set_power(&val_ans, 28);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

Suite* suite_s21_div() {
  Suite* s = suite_create("s21_div");
  TCase* tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, test_s21_div_01);
  tcase_add_test(tc, test_s21_div_02);
  tcase_add_test(tc, test_s21_div_03);
  tcase_add_test(tc, test_s21_div_04);
  tcase_add_test(tc, test_s21_div_05);
  tcase_add_test(tc, test_s21_div_06);
  tcase_add_test(tc, test_s21_div_07);
  tcase_add_test(tc, test_s21_div_08);
  tcase_add_test(tc, test_s21_div_09);
  tcase_add_test(tc, test_s21_div_10);
  tcase_add_test(tc, test_s21_div_11);

  suite_add_tcase(s, tc);
  return s;
}
