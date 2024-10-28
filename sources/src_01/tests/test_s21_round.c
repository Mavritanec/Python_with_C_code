#include "test_s21_decimal.h"

START_TEST(test_s21_round_01) {
  s21_decimal val = {{6543218}};
  s21_decimal val_ans = {{6543}};
  s21_decimal val_res;

  set_sign(&val);
  set_sign(&val_ans);

  set_power(&val, 3);

  int res = s21_round(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_round_02) {
  s21_decimal val = {{6543218}};
  s21_decimal val_ans = {{6543}};
  s21_decimal val_res;

  set_power(&val, 3);

  int res = s21_round(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_round_03) {
  s21_decimal val = {{6543618}};
  s21_decimal val_ans = {{6544}};
  s21_decimal val_res;

  set_sign(&val);
  set_sign(&val_ans);

  set_power(&val, 3);

  int res = s21_round(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_round_04) {
  s21_decimal val = {{6543518}};
  s21_decimal val_ans = {{6544}};
  s21_decimal val_res;

  set_power(&val, 3);

  int res = s21_round(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_round_05) {
  s21_decimal val = {{6543518}};
  s21_decimal* val_res = NULL;

  int res = s21_round(val, val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

Suite* suite_s21_round() {
  Suite* s = suite_create("s21_round");
  TCase* tc = tcase_create("s21_round_tc");

  tcase_add_test(tc, test_s21_round_01);
  tcase_add_test(tc, test_s21_round_02);
  tcase_add_test(tc, test_s21_round_03);
  tcase_add_test(tc, test_s21_round_04);
  tcase_add_test(tc, test_s21_round_05);

  suite_add_tcase(s, tc);
  return s;
}
