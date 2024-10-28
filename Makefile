CC := gcc

LIB ?= s21_decimal.a
TEST_LIB ?= test_s21_decimal.a
TEST_EXE ?= run_test

DIR ?= ./
TEST_DIR ?= $(DIR)tests/

OBJ_DIR ?= $(DIR)objs/
TEST_OBJ_DIR ?= $(TEST_DIR)objs/

SRC := $(wildcard $(DIR)*.c)
INC := $(wildcard $(DIR)*.h)

TEST_SRC := $(wildcard $(TEST_DIR)*.c)
TEST_INC := $(wildcard $(TEST_DIR)*.h)

OBJ := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
TEST_OBJ := $(addprefix $(TEST_OBJ_DIR), $(notdir $(TEST_SRC:.c=.o)))
GCOV_OBJ := $(addprefix $(TEST_OBJ_DIR), $(notdir $(SRC:.c=.o)))

GCOV_TARGET ?= $(DIR)coverage
GCOV_INFO ?= coverage.info

AR := ar rc
RAN := ranlib
MK := mkdir -p
RM := rm -rf

ASAN :=#-fsanitize=address
STDFLAGS := -c -Wall -Wextra -Werror -std=c11 -pedantic
CFLAGS ?= $(STDFLAGS) $(ASAN)
TST_CFLAGS ?= -g $(CFLAGS)#$(shell pkg-config --cflags check)
GCOV_FLAGS ?= -fprofile-arcs -ftest-coverage

TST_LIBS := -lcheck
ifeq ($(shell uname), Linux)
TST_LIBS := -lcheck_pic -lpthread -lrt -lm -lsubunit#$(shell pkg-config --libs check)
endif

all: test $(LIB) gcov_report clean

test: create_obj_test_dir $(TEST_LIB) $(TEST_OBJ)
	$(CC) $(TEST_OBJ) $(TST_LIBS) $(GCOV_FLAGS) -L. $(TEST_LIB) -o $(TEST_EXE)

create_obj_test_dir:
	@$(MK) $(TEST_OBJ_DIR)

$(TEST_LIB): $(GCOV_OBJ)
	$(AR) $(TEST_LIB) $(GCOV_OBJ)
	$(RAN) $(TEST_LIB)

$(GCOV_OBJ): $(TEST_OBJ_DIR)%.o: $(DIR)%.c $(INC)
	$(CC) $(TST_CFLAGS) $(GCOV_FLAGS) $< -o $@

$(TEST_OBJ_DIR)%.o: $(TEST_DIR)%.c $(TEST_INC)
	$(CC) $(TST_CFLAGS) $< -o $@

$(LIB): create_obj_dir $(OBJ)
	$(AR) $(LIB) $(OBJ)
	$(RAN) $(LIB)

create_obj_dir:
	@$(MK) $(OBJ_DIR)

$(OBJ): $(OBJ_DIR)%.o: $(DIR)%.c $(INC)
	$(CC) $(STDFLAGS) $< -o $@

gcov_report: test $(GCOV_TARGET)

$(GCOV_TARGET): $(GCOV_INFO)
	genhtml $(GCOV_INFO) -o $(GCOV_TARGET)

$(GCOV_INFO):
	$(DIR)$(TEST_EXE)
	geninfo $(TEST_OBJ_DIR) -b . -o $(DIR)$(GCOV_INFO)

open:
	@open $(GCOV_TARGET)/src/index.html

check: style cppcheck valgrind leaks

style:
	@cp ../materials/linters/.clang-format .clang-format
	@clang-format -n *.c *.h
	@rm .clang-format
	@cp ../materials/linters/.clang-format $(TEST_DIR).clang-format
	@clang-format -n $(TEST_DIR)*.c $(TEST_DIR)*.h
	@rm $(TEST_DIR).clang-format

cppcheck:
	@find . -type f -name "*.c" | xargs cppcheck -q --enable=all --inconclusive --platform=unix64 --std=c11

valgrind: test
	valgrind $(DIR)$(TEST_EXE) --leak-check=full

leaks: test
ifeq ($(shell uname), Darwin)
	@CK_FORK=no leaks --atExit -- $(DIR)$(TEST_EXE)
endif

clean:
	@$(RM) $(OBJ_DIR)
	@$(RM) $(TEST_OBJ_DIR)
	@$(RM) $(TEST_LIB)
	@$(RM) $(GCOV_INFO)
	@$(RM) run_test.dSYM

fclean: clean
	@$(RM) $(GCOV_TARGET)
	@$(RM) $(TEST_EXE)
	@$(RM) $(LIB)

re: fclean all

.PHONY: all open check style cppcheck valgrind leaks clean fclean re
