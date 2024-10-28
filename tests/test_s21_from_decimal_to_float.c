#include "test_s21_decimal.h"

START_TEST(test_s21_from_decimal_to_float_01) {
  s21_decimal val = {{6543218}};
  float val_ans = -6543.218;
  float val_res;

  set_sign(&val);

  set_power(&val, 3);

  int res = s21_from_decimal_to_float(val, &val_res);

  ck_assert_int_eq(val_res, val_ans);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_02) {
  s21_decimal val = {{2147483647}};
  float val_ans = 2147483647;
  float val_res;

  int res = s21_from_decimal_to_float(val, &val_res);

  ck_assert_int_eq(val_res, val_ans);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_03) {
  s21_decimal val = {{5}};
  float val_ans = -0.0005;
  float val_res;

  set_sign(&val);

  set_power(&val, 4);

  int res = s21_from_decimal_to_float(val, &val_res);

  ck_assert_int_eq(val_res, val_ans);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_s21_from_decimal_to_float_04) {
  s21_decimal val = {{5}};
  float *val_res = NULL;

  int res = s21_from_decimal_to_float(val, val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

Suite *suite_s21_from_decimal_to_float(void) {
  Suite *s = suite_create("s21_from_decimal_to_float");
  TCase *tc = tcase_create("s21_from_decimal_to_float_tc");

  tcase_add_test(tc, test_s21_from_decimal_to_float_01);
  tcase_add_test(tc, test_s21_from_decimal_to_float_02);
  tcase_add_test(tc, test_s21_from_decimal_to_float_03);
  tcase_add_test(tc, test_s21_from_decimal_to_float_04);

  suite_add_tcase(s, tc);
  return s;
}
