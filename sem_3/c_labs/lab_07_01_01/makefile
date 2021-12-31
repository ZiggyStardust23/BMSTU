CFLAGS := -std=c99 -Wall -Werror -pedantic
TEST_OBJ := out/check_comparator.o out/check_key.o out/check_mysort.o

app.exe : out/main.o out/funcs.o out/key.o out/mysort.o
	gcc -o app.exe out/main.o out/funcs.o out/key.o out/mysort.o

unit_tests.exe : out/check_main.o out/key.o out/mysort.o out/funcs.o $(TEST_OBJ)
	gcc -o unit_tests.exe out/check_main.o out/key.o out/mysort.o out/funcs.o $(TEST_OBJ) -lcheck

out/main.o : src/main.c inc/main.h
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/funcs.o : src/funcs.c inc/funcs.h
	gcc $(CFLAGS) -c -o out/funcs.o src/funcs.c

out/key.o : src/key.c inc/key.h
	gcc $(CFLAGS) -c -o out/key.o src/key.c

out/check_main.o : unit_tests/check_main.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/mysort.o : src/mysort.c inc/mysort.h
	gcc $(CFLAGS) -c -o out/mysort.o src/mysort.c

out/check_comparator.o : unit_tests/check_comparator.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_comparator.o unit_tests/check_comparator.c

out/check_mysort.o : unit_tests/check_mysort.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_mysort.o unit_tests/check_mysort.c

out/check_key.o : unit_tests/check_key.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_key.o unit_tests/check_key.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe
