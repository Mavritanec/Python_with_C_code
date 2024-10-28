#include "test_s21_decimal.h"

START_TEST(test_s21_from_int_to_decimal_01) {
  int val = 2142;
  s21_decimal *val_res = NULL;

  int res = s21_from_int_to_decimal(val, val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_02) {
  int val = 2142;
  s21_decimal val_ans = {{2142}};
  s21_decimal val_res;

  int res = s21_from_int_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_03) {
  int val = -2142;
  s21_decimal val_ans = {{2142}};
  s21_decimal val_res;

  set_sign(&val_ans);

  int res = s21_from_int_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_from_int_to_decimal_04) {
  int val = -0;
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_from_int_to_decimal(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

Suite *suite_s21_from_int_to_decimal(void) {
  Suite *s = suite_create("s21_from_int_to_decimal");
  TCase *tc = tcase_create("s21_from_int_to_decimal_tc");

  tcase_add_test(tc, test_s21_from_int_to_decimal_01);
  tcase_add_test(tc, test_s21_from_int_to_decimal_02);
  tcase_add_test(tc, test_s21_from_int_to_decimal_03);
  tcase_add_test(tc, test_s21_from_int_to_decimal_04);

  suite_add_tcase(s, tc);
  return s;
}
