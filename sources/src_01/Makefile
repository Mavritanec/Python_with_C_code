CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g
GCOV_FLAGS ?= -fprofile-arcs -ftest-coverage

DIR ?= ./
GCOV_TARGET ?= $(DIR)coverage
GCOV_INFO ?= coverage.info

CHECK_FLAGS=-lcheck -lm -lpthread $(shell pkg-config --cflags --libs check)
ALL_FLAGS=$(CFLAGS) $(LFLAGS) $(CHECK_FLAGS) $(GCOV_FLAGS) 
SRCS = $(wildcard ./s21_*.c)
OBJS = $(SRCS:.c=.o)
TESTS_PATH=$(DIR)tests/
NAME = test

all: clean s21_decimal.a gcov_report

rebuild: clean test

test: clean s21_decimal.a
	$(CC) $(CFLAGS) $(LFLAGS) $(CHECK_FLAGS) main.c $(TESTS_PATH)*.c $(OBJS) -o $(NAME)
	$(DIR)$(NAME)

fclean: clean
	rm -rf *.txt
	rm -rf *.a
	rm $(NAME)
	rm -rf $(GCOV_TARGET)

clean:
	rm -rf *.o
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.dSYM

s21_decimal.a: $(OBJS)
	ar rc s21_decimal.a $(OBJS) 
	ranlib s21_decimal.a

gcov_report: $(GCOV_TARGET)

$(GCOV_TARGET): CFLAGS += $(GCOV_FLAGS)
$(GCOV_TARGET): $(GCOV_INFO)
	genhtml $(GCOV_INFO) -o $(GCOV_TARGET)

$(GCOV_INFO): test
	$(DIR)$(NAME)
	geninfo $(DIR) -b $(DIR) -o $(DIR)$(GCOV_INFO)

open:
	open coverage/src/index.html

check: cppcheck style valgrind leaks

cppcheck:
	@cppcheck -q --enable=all --suppress=missingIncludeSystem --inconclusive --platform=unix64 --std=c11 *.c $(TESTS_PATH)*.c

style:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -n *.c *.h $(TESTS_PATH)*.c $(TESTS_PATH)*.h
	@rm .clang-format

valgrind: test
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt $(DIR)$(NAME)
	make clean

ifeq ($(shell uname), Darwin)
leaks: test
	@CK_FORK=no leaks --atExit -- $(DIR)$(NAME)
	make clean
endif
