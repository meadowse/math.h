WWW = -Wall -Wextra -Werror -std=c11
LINUX=-lsubunit -lrt -lpthread -lm
LIBS=-lcheck
LFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: test

re: clean all 

test: s21_math.a
ifeq ($(OS), Darwin)
	gcc $(WWW) unit_test.c s21_math.a -o unit_test $(LIBS)
else
	gcc $(WWW) unit_test.c s21_math.a -o unit_test $(LIBS) $(LINUX)
endif
	./unit_test

gcov_report: clean_test
ifeq ($(OS), Darwin)
	gcc $(WWW) -fprofile-arcs -ftest-coverage unit_test.c s21_*.c -o unit_test $(LIBS)
else
	gcc $(WWW) -fprofile-arcs -ftest-coverage unit_test.c s21_*.c -o unit_test $(LIBS) $(LINUX)
endif
	./unit_test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info

s21_math.a: build_s21_math 

build_s21_math:
	gcc -c s21_*.c
	ar rcs s21_math.a s21_*.o
	ranlib s21_math.a

valgf: s21_math.a
ifeq ($(OS), Darwin)
	gcc $(WWW) unit_test.c s21_math.a -o unit_test $(LIBS)
	CK_FORK=no valgrind --leak-check=full -s ./unit_test
else
	gcc $(WWW) unit_test.c s21_math.a -o unit_test $(LIBS) $(LINUX)
	K_FORK=no valgrind --leak-check=full -s ./unit_test
endif

valg: s21_math.a clean_obj
ifeq ($(OS), Darwin)
	gcc $(WWW) unit_test.c s21_math.a -o unit_test $(LIBS)
	valgrind --leak-check=full -s ./unit_test
else
	gcc $(WWW) unit_test.c s21_math.a -o unit_test $(LIBS) $(LINUX)
	valgrind --leak-check=full -s ./unit_test
endif

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

install_valgrind:
	brew install --HEAD LouisBrunner/valgrind/valgrind

install_cpch:
	brew install cppcheck

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean_test:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf report

clean: clean_lib clean_lib clean_test clean_obj
	rm -rf unit_test

print:
	gcc $(WWW) *.c 