#include "test_s21_decimal.h"

START_TEST(test_s21_from_decimal_to_int_01) {
  s21_decimal val = {{6543218}};
  int val_ans = -6543;
  int val_res;

  set_sign(&val);

  set_power(&val, 3);

  int res = s21_from_decimal_to_int(val, &val_res);

  ck_assert_int_eq(val_res, val_ans);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_02) {
  s21_decimal val = {{6543218, 465465, 0, 0}};
  int val_res;

  int res = s21_from_decimal_to_int(val, &val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_03) {
  s21_decimal val = {{4294967295}};
  int val_res;

  int res = s21_from_decimal_to_int(val, &val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_04) {
  s21_decimal val = {{2147483647}};
  int val_ans = 2147483647;
  int val_res;

  int res = s21_from_decimal_to_int(val, &val_res);

  ck_assert_int_eq(val_res, val_ans);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_05) {
  s21_decimal val = {{4294967295}};
  int val_ans = 42949;
  int val_res;

  set_power(&val, 5);

  int res = s21_from_decimal_to_int(val, &val_res);

  ck_assert_int_eq(val_res, val_ans);
  ck_assert_int_eq(res, SUCCESS);
}
END_TEST

START_TEST(test_s21_from_decimal_to_int_06) {
  s21_decimal val = {{5}};
  int* val_res = NULL;

  int res = s21_from_decimal_to_int(val, val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

Suite* suite_s21_from_decimal_to_int() {
  Suite* s = suite_create("s21_from_decimal_to_int");
  TCase* tc = tcase_create("s21_from_decimal_to_int_tc");

  tcase_add_test(tc, test_s21_from_decimal_to_int_01);
  tcase_add_test(tc, test_s21_from_decimal_to_int_02);
  tcase_add_test(tc, test_s21_from_decimal_to_int_03);
  tcase_add_test(tc, test_s21_from_decimal_to_int_04);
  tcase_add_test(tc, test_s21_from_decimal_to_int_05);
  tcase_add_test(tc, test_s21_from_decimal_to_int_06);

  suite_add_tcase(s, tc);
  return s;
}
