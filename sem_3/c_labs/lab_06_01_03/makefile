CFLAGS := -std=c99 -Wall -Werror -pedantic
TEST_OBJ := out/check_util_funcs.o out/check_funcs.o

app.exe : out/main.o out/funcs.o out/util_funcs.o
	gcc -o app.exe out/main.o out/funcs.o out/util_funcs.o

unit_tests.exe : out/check_main.o out/util_funcs.o out/funcs.o $(TEST_OBJ)
	gcc -o unit_tests.exe out/check_main.o out/util_funcs.o out/funcs.o $(TEST_OBJ) -lcheck -lm -lrt -lpthread -lsubunit

out/main.o : main.c goods.h util_funcs.h  funcs.h
	gcc $(CFLAGS) -c -o out/main.o main.c

out/funcs.o : funcs.c funcs.h goods.h
	gcc $(CFLAGS) -c -o out/funcs.o funcs.c

out/util_funcs.o : util_funcs.c util_funcs.h
	gcc $(CFLAGS) -c -o out/util_funcs.o util_funcs.c

out/check_main.o : unit_tests/check_main.c unit_tests/check_main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/check_funcs.o : unit_tests/check_funcs.c unit_tests/check_main.h
	gcc $(CFLAGS) -c -o out/check_funcs.o unit_tests/check_funcs.c

out/check_util_funcs.o : unit_tests/check_util_funcs.c unit_tests/check_main.h
	gcc $(CFLAGS) -c -o out/check_util_funcs.o unit_tests/check_util_funcs.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe
