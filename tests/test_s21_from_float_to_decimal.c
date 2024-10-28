#include "test_s21_decimal.h"

START_TEST(test_s21_from_float_to_decimal_01) {
  float val = 1.125;
  s21_decimal *val_res = NULL;

  int res = s21_from_float_to_decimal(val, val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_02) {
  float val = 1.135;
  s21_decimal val_ans = {{1135}};
  s21_decimal val_res;

  set_power(&val_ans, 3);

  int res = s21_from_float_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_03) {
  float val = -1.125;
  s21_decimal val_ans = {{1125}};
  s21_decimal val_res;

  set_sign(&val_ans);

  set_power(&val_ans, 3);

  int res = s21_from_float_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_04) {
  float val = -0.0;
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_power(&val_ans, 3);

  int res = s21_from_float_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_05) {
  float val = 5232.13;
  s21_decimal val_ans = {{523213}};
  s21_decimal val_res;

  set_power(&val_ans, 2);

  int res = s21_from_float_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_06) {
  float val = 10.03125;
  s21_decimal val_ans = {{1003125}};
  s21_decimal val_res;

  set_power(&val_ans, 5);

  int res = s21_from_float_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_from_float_to_decimal_07) {
  float val = 10.03125;
  s21_decimal *val_res = NULL;

  int res = s21_from_float_to_decimal(val, val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

Suite *suite_s21_from_float_to_decimal(void) {
  Suite *s = suite_create("s21_from_float_to_decimal");
  TCase *tc = tcase_create("s21_from_float_to_decimal_tc");

  tcase_add_test(tc, test_s21_from_float_to_decimal_01);
  tcase_add_test(tc, test_s21_from_float_to_decimal_02);
  tcase_add_test(tc, test_s21_from_float_to_decimal_03);
  tcase_add_test(tc, test_s21_from_float_to_decimal_04);
  tcase_add_test(tc, test_s21_from_float_to_decimal_05);
  tcase_add_test(tc, test_s21_from_float_to_decimal_06);
  tcase_add_test(tc, test_s21_from_float_to_decimal_07);

  suite_add_tcase(s, tc);
  return s;
}
