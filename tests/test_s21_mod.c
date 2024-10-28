#include "test_s21_decimal.h"

START_TEST(test_s21_mod_01) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_02) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_03) {
  s21_decimal val_1 = {{5}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_04) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_05) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_sign(&val_1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_06) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_07) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{5}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_08) {
  s21_decimal val_1 = {{11}};
  s21_decimal val_2 = {{4}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_09) {
  s21_decimal val_1 = {{11}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{0}};
  s21_decimal val_res;

  set_power(&val_2, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_10) {
  s21_decimal val_1 = {{11}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{2}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);
  set_sign(&val_ans);

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_11) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);
  for (int i = 0; i < 96; i++) set_bit(&val_2, i, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_12) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{1}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_13) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{429496729}};
  s21_decimal val_ans = {{215}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_14) {
  s21_decimal val_1 = {{4294967295}};
  s21_decimal val_2 = {{523467}};
  s21_decimal val_ans = {{222906}};
  s21_decimal val_res;

  set_power(&val_2, 4);
  set_power(&val_ans, 4);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_15) {
  s21_decimal val_1 = {{523467}};
  s21_decimal val_2 = {{4294967295}};
  s21_decimal val_ans = {{523467}};
  s21_decimal val_res;

  set_power(&val_1, 4);
  set_power(&val_ans, 4);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_16) {
  s21_decimal val_1 = {{523467}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_17) {
  s21_decimal val_1 = {{523467}};
  s21_decimal val_2 = {{4294967295}};
  s21_decimal val_ans = {{4294433829, 9999}};
  s21_decimal val_res;

  set_sign(&val_1);

  set_power(&val_1, 4);
  set_power(&val_ans, 4);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_18) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{523467}};
  s21_decimal val_ans = {{228501}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);

  set_power(&val_2, 10);
  set_power(&val_ans, 10);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_19) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{523467}};
  s21_decimal val_ans = {{291438}};
  s21_decimal val_res;

  for (int i = 0; i < 96; i++) set_bit(&val_1, i, 1);

  set_power(&val_2, 1);
  set_power(&val_ans, 1);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_20) {
  s21_decimal val_1 = {{100, 0, 0, 0x80010000}};
  s21_decimal val_2 = {{2147483647, 2147483647, 2147483647, 0x801C0000}};
  s21_decimal val_ans = {{2684354562, 1836193739, 1126043567, 0x801C0000}};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_21) {
  s21_decimal val_1 = {{2147483647, 2147483647, 2147483647, 0x801C0000}};
  s21_decimal val_2 = {{1513252461, 1236723423, 0, 0x80140000}};
  s21_decimal val_ans = {{686341631, 1980154442, 16675028, 0x801C0000}};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_22) {
  s21_decimal val_1 = {{1513252461, 1236723423, 0, 0x80140000}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_23) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{125617186, 1231257813, 124416171, 0x1C0000}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_24) {
  s21_decimal val_1 = {{125617186, 1231257813, 124416171, 0x1C0000}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{3878032285, 552622510, 12441617, 0x1B0000}};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_25) {
  s21_decimal val_1 = {{100}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_mod_26) {
  s21_decimal val_1 = {{1268735185, 1267123232, 2092316572}};
  s21_decimal val_2 = {{1660905039, 1838546767, 0}};
  s21_decimal val_ans = {{1268735185, 1267123232, 2092316572}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);
  set_sign(&val_ans);

  set_power(&val_1, 23);
  set_power(&val_2, 11);
  set_power(&val_ans, 23);

  int res = s21_mod(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

Suite* suite_s21_mod() {
  Suite* s = suite_create("s21_mod");
  TCase* tc = tcase_create("s21_mod_tc");

  tcase_add_test(tc, test_s21_mod_01);
  tcase_add_test(tc, test_s21_mod_02);
  tcase_add_test(tc, test_s21_mod_03);
  tcase_add_test(tc, test_s21_mod_04);
  tcase_add_test(tc, test_s21_mod_05);
  tcase_add_test(tc, test_s21_mod_06);
  tcase_add_test(tc, test_s21_mod_07);
  tcase_add_test(tc, test_s21_mod_08);
  tcase_add_test(tc, test_s21_mod_09);
  tcase_add_test(tc, test_s21_mod_10);
  tcase_add_test(tc, test_s21_mod_11);
  tcase_add_test(tc, test_s21_mod_12);
  tcase_add_test(tc, test_s21_mod_13);
  tcase_add_test(tc, test_s21_mod_14);
  tcase_add_test(tc, test_s21_mod_15);
  tcase_add_test(tc, test_s21_mod_16);
  tcase_add_test(tc, test_s21_mod_17);
  tcase_add_test(tc, test_s21_mod_18);
  tcase_add_test(tc, test_s21_mod_19);
  tcase_add_test(tc, test_s21_mod_20);
  tcase_add_test(tc, test_s21_mod_21);
  tcase_add_test(tc, test_s21_mod_22);
  tcase_add_test(tc, test_s21_mod_23);
  tcase_add_test(tc, test_s21_mod_24);
  tcase_add_test(tc, test_s21_mod_25);
  tcase_add_test(tc, test_s21_mod_26);

  suite_add_tcase(s, tc);
  return s;
}
