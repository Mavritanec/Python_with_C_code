#include "tests/test_s21_decimal.h"

int main() {
  run_tests();
  return 0;
}

void run_tests() {
  Suite* list_cases[] = {suite_s21_add(),
                         suite_s21_sub(),
                         suite_s21_mul(),
                         suite_s21_div(),
                         suite_s21_mod(),
                         suite_s21_is_less(),
                         suite_s21_is_less_or_equal(),
                         suite_s21_is_greater(),
                         suite_s21_is_greater_or_equal(),
                         suite_s21_is_equal(),
                         suite_s21_is_not_equal(),
                         suite_s21_from_int_to_decimal(),
                         suite_s21_from_float_to_decimal(),
                         suite_s21_from_decimal_to_int(),
                         suite_s21_from_decimal_to_float(),
                         suite_s21_floor(),
                         suite_s21_round(),
                         suite_s21_truncate(),
                         suite_s21_negate(),
                         NULL};

  for (Suite** current_testcase = list_cases; *current_testcase;
       current_testcase++)
    run_testcase(*current_testcase);
}

void run_testcase(Suite* testcase) {
  static int counter_testcase = 1;

  if (counter_testcase > 1) putchar('\n');
  printf("%s%d%s", "CURRENT TEST: ", counter_testcase, "\n");
  counter_testcase++;

  SRunner* sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}
