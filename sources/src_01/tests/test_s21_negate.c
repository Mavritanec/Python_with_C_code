#include "test_s21_decimal.h"

START_TEST(test_s21_negate_01) {
  s21_decimal val = {{4221}};
  s21_decimal val_ans = {{4221}};
  s21_decimal val_res;

  set_sign(&val_ans);

  int res = s21_negate(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_negate_02) {
  s21_decimal val = {{4221}};
  s21_decimal val_ans = {{4221}};
  s21_decimal val_res;

  set_sign(&val);

  int res = s21_negate(val, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, SUCCESS);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_negate_03) {
  s21_decimal val = {{4221}};
  s21_decimal *val_res = NULL;

  int res = s21_negate(val, val_res);

  ck_assert_int_eq(res, FAIL);
}
END_TEST

Suite *suite_s21_negate() {
  Suite *s = suite_create("s21_negate");
  TCase *tc = tcase_create("s21_negate_tc");

  tcase_add_test(tc, test_s21_negate_01);
  tcase_add_test(tc, test_s21_negate_02);
  tcase_add_test(tc, test_s21_negate_03);

  suite_add_tcase(s, tc);
  return s;
}