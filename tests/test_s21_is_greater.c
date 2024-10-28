#include "test_s21_decimal.h"

START_TEST(test_s21_is_greater_01) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{10}};

  ck_assert_int_eq(s21_is_greater(val_1, val_2), FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_02) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {{5}};

  ck_assert_int_eq(s21_is_greater(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_03) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{10}};

  set_sign(&val_1);

  ck_assert_int_eq(s21_is_greater(val_1, val_2), FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_04) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{10}};

  set_sign(&val_2);

  ck_assert_int_eq(s21_is_greater(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_05) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{10}};

  set_sign(&val_1);
  set_sign(&val_2);

  ck_assert_int_eq(s21_is_greater(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_06) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{15}};

  set_power(&val_2, 1);

  ck_assert_int_eq(s21_is_greater(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_greater_07) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{15}};

  set_sign(&val_1);
  set_power(&val_2, 1);

  ck_assert_int_eq(s21_is_greater(val_1, val_2), FALSE);
}
END_TEST

START_TEST(test_s21_is_greater_08) {
  s21_decimal val_1 = {{15}};
  s21_decimal val_2 = {{15}};

  ck_assert_int_eq(s21_is_greater(val_1, val_2), FALSE);
}
END_TEST

Suite *suite_s21_is_greater() {
  Suite *s = suite_create("s21_is_greater");
  TCase *tc = tcase_create("s21_is_greater_tc");

  tcase_add_test(tc, test_s21_is_greater_01);
  tcase_add_test(tc, test_s21_is_greater_02);
  tcase_add_test(tc, test_s21_is_greater_03);
  tcase_add_test(tc, test_s21_is_greater_04);
  tcase_add_test(tc, test_s21_is_greater_05);
  tcase_add_test(tc, test_s21_is_greater_06);
  tcase_add_test(tc, test_s21_is_greater_07);
  tcase_add_test(tc, test_s21_is_greater_08);

  suite_add_tcase(s, tc);
  return s;
}
