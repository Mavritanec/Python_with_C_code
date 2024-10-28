#include "test_s21_decimal.h"

START_TEST(test_s21_is_equal_01) {
  s21_decimal val_1 = {{42}};
  s21_decimal val_2 = {{42}};

  ck_assert_int_eq(s21_is_equal(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_equal_02) {
  s21_decimal val_1 = {{42}};
  s21_decimal val_2 = {{42}};

  set_sign(&val_1);

  ck_assert_int_eq(s21_is_equal(val_1, val_2), FALSE);
}
END_TEST

START_TEST(test_s21_is_equal_03) {
  s21_decimal val_1 = {{42}};
  s21_decimal val_2 = {{42}};

  set_power(&val_2, 1);

  ck_assert_int_eq(s21_is_equal(val_1, val_2), FALSE);
}
END_TEST

START_TEST(test_s21_is_equal_04) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{42}};

  ck_assert_int_eq(s21_is_equal(val_1, val_2), FALSE);
}
END_TEST

START_TEST(test_s21_is_equal_05) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};

  ck_assert_int_eq(s21_is_equal(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_equal_06) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};

  set_sign(&val_2);

  ck_assert_int_eq(s21_is_equal(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_equal_07) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};

  set_power(&val_1, 1);

  ck_assert_int_eq(s21_is_equal(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_equal_08) {
  s21_decimal val_1 = {{2100}};
  s21_decimal val_2 = {{21}};

  set_power(&val_1, 2);

  ck_assert_int_eq(s21_is_equal(val_1, val_2), TRUE);
}
END_TEST

START_TEST(test_s21_is_equal_09) {
  s21_decimal val_1 = {{712}};
  s21_decimal val_2 = {{7120}};

  set_power(&val_1, 2);
  set_power(&val_2, 3);

  ck_assert_int_eq(s21_is_equal(val_1, val_2), TRUE);
}
END_TEST

Suite *suite_s21_is_equal() {
  Suite *s = suite_create("s21_is_equal");
  TCase *tc = tcase_create("s21_is_equal_tc");

  tcase_add_test(tc, test_s21_is_equal_01);
  tcase_add_test(tc, test_s21_is_equal_02);
  tcase_add_test(tc, test_s21_is_equal_03);
  tcase_add_test(tc, test_s21_is_equal_04);
  tcase_add_test(tc, test_s21_is_equal_05);
  tcase_add_test(tc, test_s21_is_equal_06);
  tcase_add_test(tc, test_s21_is_equal_07);
  tcase_add_test(tc, test_s21_is_equal_08);
  tcase_add_test(tc, test_s21_is_equal_09);

  suite_add_tcase(s, tc);
  return s;
}
