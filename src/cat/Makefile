
FLAGS = -Wall -Wextra -Werror

all: s21_cat

s21_cat: Makefile cat.h cat.c
	lgcc $(FLAGS) s21_cat.c -o s21_cat

check:
	clang-format -style=Google -n *.c

rebuild:
	make clean
	make all

clean:
	rm -f s21_cat s21_grep