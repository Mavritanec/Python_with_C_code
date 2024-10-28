#include "test_s21_decimal.h"

START_TEST(test_s21_div_01) {
  s21_decimal val_1 = {{10}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_02) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_03) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_04) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_05) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_power(&val_1, 1);
  set_power(&val_ans, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_06) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{70}};
  s21_decimal val_res;

  set_power(&val_2, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_07) {
  s21_decimal val_1 = {{21}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{7}};
  s21_decimal val_res;

  set_power(&val_1, 1);
  set_power(&val_2, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_08) {
  s21_decimal val_1 = {{3}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{15}};
  s21_decimal val_res;

  set_power(&val_ans, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_09) {
  s21_decimal val_1 = {{2}};
  s21_decimal val_2 = {{3}};
  s21_decimal val_ans = {{178956971, 695075222, 361400724}};
  s21_decimal val_res;

  set_power(&val_ans, 28);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_10) {
  s21_decimal val_1 = {{7}};
  s21_decimal val_2 = {{4}};
  s21_decimal val_ans = {{175}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_ans);

  set_power(&val_1, 1);
  set_power(&val_ans, 3);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_11) {
  s21_decimal val_1 = {{12}};
  s21_decimal val_2 = {{11}};
  s21_decimal val_ans = {{2245096541, 746944245, 591383003}};
  s21_decimal val_res;

  set_power(&val_ans, 28);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_12) {
  s21_decimal val_1 = {{150}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{15}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_13) {
  s21_decimal val_1 = {{4294967295}};
  s21_decimal val_2 = {{123478698}};
  s21_decimal val_ans = {{1735072912, 1745269190, 1885593607}};
  s21_decimal val_res;

  set_power(&val_2, 5);
  set_power(&val_ans, 22);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_14) {
  s21_decimal val_1 = {{4294967294, 1, 0, 0}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{4294967295}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_15) {
  s21_decimal val_1 = {{150}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{750}};
  s21_decimal val_res;

  set_power(&val_2, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_16) {
  s21_decimal val_1 = {{150}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_17) {
  s21_decimal val_1 = {{150}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_sign(&val_2);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_18) {
  s21_decimal val_1 = {{547}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{1094}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  set_power(&val_ans, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_19) {
  s21_decimal val_1 = {{20}};
  s21_decimal val_2 = {{5}};
  s21_decimal val_ans = {{4}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_20) {
  s21_decimal val_1 = {{22}};
  s21_decimal val_2 = {{7}};
  s21_decimal val_ans = {{3297921317, 208949406, 1703746271}};
  s21_decimal val_res;

  set_power(&val_ans, 28);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_21) {
  s21_decimal val_1 = {{4294967295}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {{4294967291, 4}};
  s21_decimal val_res;

  set_power(&val_ans, 1);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_22) {
  s21_decimal val_1 = {{3333388888}};
  s21_decimal val_2 = {{4294967295, 4294967295}};
  s21_decimal val_ans = {{1409956271, 4207}};
  s21_decimal val_res;

  set_power(&val_1, 5);
  set_power(&val_ans, 28);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_23) {
  s21_decimal val_1 = {{3333388888}};
  s21_decimal val_2 = {{22647}};
  s21_decimal val_ans = {{3777176791, 1197098455, 797913073}};
  s21_decimal val_res;

  set_power(&val_1, 5);
  set_power(&val_2, 3);
  set_power(&val_ans, 25);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_24) {
  s21_decimal val_1 = {{291}};
  s21_decimal val_2 = {{123}};
  s21_decimal val_ans = {{425568406, 790584587, 1282531838}};
  s21_decimal val_res;

  set_power(&val_ans, 28);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_25) {
  s21_decimal val_1 = {{4294967295, 4294967295, 4294967295}};
  s21_decimal val_2 = {{4294967295, 4294967295, 4294967295}};
  s21_decimal val_ans = {{1}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_26) {
  s21_decimal val_1 = {{4294967295, 4294967295, 4294967295}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_power(&val_2, 5);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, POSITIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_27) {
  s21_decimal val_1 = {{4294967295, 4294967295, 4294967295}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);

  set_power(&val_2, 5);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, POSITIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_28) {
  s21_decimal val_1 = {{4294967295, 4294967295, 4294967295}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_sign(&val_1);

  set_power(&val_2, 5);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, NEGATIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_29) {
  s21_decimal val_1 = {{4294967295, 4294967295, 4294967295}};
  s21_decimal val_2 = {{2}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  set_sign(&val_2);

  set_power(&val_2, 5);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, NEGATIVE_INF);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_30) {
  s21_decimal val_1 = {{745}};
  s21_decimal val_2 = {{1}};
  s21_decimal val_ans = {{745}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_31) {
  s21_decimal val_1 = {{745}};
  s21_decimal val_2 = {{1}};
  s21_decimal val_ans = {{745}};
  s21_decimal val_res;

  set_sign(&val_2);
  set_sign(&val_ans);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_32) {
  s21_decimal val_1 = {{4294967295, 4294967295, 4294967295}};
  s21_decimal val_2 = {{112}};
  s21_decimal val_ans = {{1227133512, 2454267026, 3834792228}};
  s21_decimal val_res;

  set_power(&val_ans, 2);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_33) {
  s21_decimal val_1 = {{100, 0, 0, 0x80010000}};
  s21_decimal val_2 = {{2147483647, 2147483647, 2147483647, 0x801C0000}};
  s21_decimal val_ans = {{206689382, 3804578896, 1368455531, 0x1C0000}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_34) {
  s21_decimal val_1 = {{2147483647, 2147483647, 2147483647, 0x801C0000}};
  s21_decimal val_2 = {{1513252461, 1236723423, 0, 0x80140000}};
  s21_decimal val_ans = {{0x7B62BECC, 0x56F786DB, 0xF0FA62CD, 0x1B0000}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_35) {
  s21_decimal val_1 = {{1513252461, 1236723423, 0, 0x80140000}};
  s21_decimal val_2 = {0};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, S21_NAN);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_36) {
  s21_decimal val_1 = {0};
  s21_decimal val_2 = {{125617186, 1231257813, 124416171, 0x1C0000}};
  s21_decimal val_ans = {0};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_37) {
  s21_decimal val_1 = {{125617186, 1231257813, 124416171, 0x1C0000}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{0xE726139D, 0x20F059AE, 0xBDD811, 0x1C0000}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_38) {
  s21_decimal val_1 = {{100}};
  s21_decimal val_2 = {{10}};
  s21_decimal val_ans = {{10}};
  s21_decimal val_res;

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_39) {
  s21_decimal val_1 = {{1}};
  s21_decimal val_2 = {{1}};
  s21_decimal val_ans = {{1}};
  s21_decimal val_res;

  set_sign(&val_1);
  set_sign(&val_2);

  set_power(&val_1, 23);
  set_power(&val_2, 23);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

START_TEST(test_s21_div_40) {
  s21_decimal val_1 = {{426217046, 1571929377, 1073213845}};
  s21_decimal val_2 = {{1269854873}};
  s21_decimal val_ans = {{609498927, 4123451099, 84514684}};
  s21_decimal val_res;

  set_power(&val_1, 2);
  set_power(&val_2, 3);
  set_power(&val_ans, 7);

  int res = s21_div(val_1, val_2, &val_res);
  int ans = s21_is_equal(val_res, val_ans);

  ck_assert_int_eq(res, OK);
  ck_assert_int_eq(ans, TRUE);
}
END_TEST

Suite* suite_s21_div() {
  Suite* s = suite_create("s21_div");
  TCase* tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, test_s21_div_01);
  tcase_add_test(tc, test_s21_div_02);
  tcase_add_test(tc, test_s21_div_03);
  tcase_add_test(tc, test_s21_div_04);
  tcase_add_test(tc, test_s21_div_05);
  tcase_add_test(tc, test_s21_div_06);
  tcase_add_test(tc, test_s21_div_07);
  tcase_add_test(tc, test_s21_div_08);
  tcase_add_test(tc, test_s21_div_09);
  tcase_add_test(tc, test_s21_div_10);
  tcase_add_test(tc, test_s21_div_11);
  tcase_add_test(tc, test_s21_div_12);
  tcase_add_test(tc, test_s21_div_13);
  tcase_add_test(tc, test_s21_div_14);
  tcase_add_test(tc, test_s21_div_15);
  tcase_add_test(tc, test_s21_div_16);
  tcase_add_test(tc, test_s21_div_17);
  tcase_add_test(tc, test_s21_div_18);
  tcase_add_test(tc, test_s21_div_19);
  tcase_add_test(tc, test_s21_div_20);
  tcase_add_test(tc, test_s21_div_21);
  tcase_add_test(tc, test_s21_div_22);
  tcase_add_test(tc, test_s21_div_23);
  tcase_add_test(tc, test_s21_div_24);
  tcase_add_test(tc, test_s21_div_25);
  tcase_add_test(tc, test_s21_div_26);
  tcase_add_test(tc, test_s21_div_27);
  tcase_add_test(tc, test_s21_div_28);
  tcase_add_test(tc, test_s21_div_29);
  tcase_add_test(tc, test_s21_div_30);
  tcase_add_test(tc, test_s21_div_31);
  tcase_add_test(tc, test_s21_div_32);
  tcase_add_test(tc, test_s21_div_33);
  tcase_add_test(tc, test_s21_div_34);
  tcase_add_test(tc, test_s21_div_35);
  tcase_add_test(tc, test_s21_div_36);
  tcase_add_test(tc, test_s21_div_37);
  tcase_add_test(tc, test_s21_div_38);
  tcase_add_test(tc, test_s21_div_39);
  tcase_add_test(tc, test_s21_div_40);

  suite_add_tcase(s, tc);
  return s;
}
