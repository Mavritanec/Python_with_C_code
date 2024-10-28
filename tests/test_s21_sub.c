#include "test_s21_decimal.h"

START_TEST(test_s21_sub_01) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_bit(&val_1, 95, 1);
  set_bit(&val_1, 94, 1);
  set_bit(&val_2, 95, 1);
  set_bit(&val_2, 94, 1);

  set_sign(&val_2);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, POSITIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_02) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_bit(&val_1, 95, 1);
  set_bit(&val_1, 94, 1);
  set_bit(&val_2, 95, 1);
  set_bit(&val_2, 94, 1);

  set_sign(&val_1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, NEGATIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_03) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{10}};
  s21_decimal val_res;

  set_sign(&val_2);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_04) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{10}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_05) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_06) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_07) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_08) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  set_sign(&val_ans);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_09) {
  s21_decimal val_1 = {{55}};
  s21_decimal val_2 = {{55}};
  s21_decimal val_ans = {{11}};
  s21_decimal val_res;

  set_sign(&val_2);

  set_power(&val_1, 1);
  set_power(&val_2, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_10) {
  s21_decimal val_1 = {{55}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{155}};
  s21_decimal val_res;

  set_sign(&val_2);

  set_power(&val_1, 1);
  set_power(&val_ans, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_11) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {{55}};
  s21_decimal val_ans = {{155}};
  s21_decimal val_res;

  set_sign(&val_2);

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_12) {
  s21_decimal val_1 = {{55}};
  s21_decimal val_2 = {{55}};
  s21_decimal val_ans = {{11}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  set_power(&val_1, 1);
  set_power(&val_2, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_13) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {{55}};
  s21_decimal val_ans = {{155}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_14) {
  s21_decimal val_1 = {{55}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{155}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  set_power(&val_1, 1);
  set_power(&val_ans, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_15) {
  s21_decimal val_1 = {{6125}};
  s21_decimal val_2 = {{59}};
  s21_decimal val_ans = {{12025}};
  s21_decimal val_res;

  set_sign(&val_2);

  set_power(&val_1, 3);
  set_power(&val_2, 1);
  set_power(&val_ans, 3);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_16) {
  s21_decimal val_1 = {{12125}};
  s21_decimal val_2 = {{5005}};
  s21_decimal val_ans = {{712}};
  s21_decimal val_res;

  set_power(&val_1, 3);
  set_power(&val_2, 3);
  set_power(&val_ans, 2);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_17) {
  s21_decimal val_1 = {{1552125}};
  s21_decimal val_2 = {{2125}};
  s21_decimal val_ans = {{155}};
  s21_decimal val_res;

  set_power(&val_1, 5);
  set_power(&val_2, 5);
  set_power(&val_ans, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_18) {
  s21_decimal val_1 = {{1552125}};
  s21_decimal val_2 = {{47875}};
  s21_decimal val_ans = {{16}};
  s21_decimal val_res;

  set_sign(&val_2);

  set_power(&val_1, 5);
  set_power(&val_2, 5);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_19) {
  s21_decimal val_1 = {{0}};
  s21_decimal val_2 = {{6}};
  s21_decimal val_ans = {{0}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 1; i < 96; i++) set_bit(&val_ans, i, 1);

  set_power(&val_2, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_20) {
  s21_decimal val_1 = {{0}};
  s21_decimal val_2 = {{6}};
  s21_decimal val_ans = {{0}};
  s21_decimal val_res;

  for (int i = 1; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_ans, i, 1);

  set_sign(&val_2);

  set_power(&val_2, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_21) {
  s21_decimal val_1 = {{0}};
  s21_decimal val_2 = {{0}};
  s21_decimal val_ans = {{858993459, 858993459, 858993459, 0}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_2, i, 1);

  set_sign(&val_2);

  set_power(&val_1, 2);
  set_power(&val_2, 2);
  set_power(&val_ans, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_22) {
  s21_decimal val_1 = {{0}};
  s21_decimal val_2 = {{4}};
  s21_decimal val_ans = {{0}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_ans, i, 1);

  set_power(&val_2, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_sub_23) {
  s21_decimal val_1 = {{0}};
  s21_decimal val_2 = {{4}};
  s21_decimal val_ans = {{0}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_ans, i, 1);

  set_sign(&val_2);

  set_power(&val_2, 1);

  int res = s21_sub(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

Suite* suite_s21_sub() {
  Suite* s = suite_create("s21_sub");
  TCase* tc = tcase_create("s21_sub_tc");

  tcase_add_test(tc, test_s21_sub_01);
  tcase_add_test(tc, test_s21_sub_02);
  tcase_add_test(tc, test_s21_sub_03);
  tcase_add_test(tc, test_s21_sub_04);
  tcase_add_test(tc, test_s21_sub_05);
  tcase_add_test(tc, test_s21_sub_06);
  tcase_add_test(tc, test_s21_sub_07);
  tcase_add_test(tc, test_s21_sub_08);
  tcase_add_test(tc, test_s21_sub_09);
  tcase_add_test(tc, test_s21_sub_10);
  tcase_add_test(tc, test_s21_sub_11);
  tcase_add_test(tc, test_s21_sub_12);
  tcase_add_test(tc, test_s21_sub_13);
  tcase_add_test(tc, test_s21_sub_14);
  tcase_add_test(tc, test_s21_sub_15);
  tcase_add_test(tc, test_s21_sub_16);
  tcase_add_test(tc, test_s21_sub_17);
  tcase_add_test(tc, test_s21_sub_18);
  tcase_add_test(tc, test_s21_sub_19);
  tcase_add_test(tc, test_s21_sub_20);
  tcase_add_test(tc, test_s21_sub_21);
  tcase_add_test(tc, test_s21_sub_22);
  tcase_add_test(tc, test_s21_sub_23);

  suite_add_tcase(s, tc);
  return s;
}
