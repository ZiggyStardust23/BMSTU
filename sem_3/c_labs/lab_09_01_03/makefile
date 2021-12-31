CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : out/main.o out/funcs.o out/util_funcs.o
	gcc -o app.exe out/main.o out/funcs.o out/util_funcs.o -lm

unit_tests.exe : out/check_main.o out/check_util_funcs.o out/check_funcs.o out/funcs.o out/util_funcs.o
	gcc -o unit_tests.exe out/check_main.o out/check_util_funcs.o out/check_funcs.o out/funcs.o out/util_funcs.o -lm

out/main.o : src/main.c inc/funcs.h inc/goods.h inc/util_funcs.h
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/funcs.o : src/funcs.c inc/funcs.h inc/goods.h
	gcc $(CFLAGS) -c -o out/funcs.o src/funcs.c

out/util_funcs.o : src/util_funcs.c inc/util_funcs.h
	gcc $(CFLAGS) -c -o out/util_funcs.o src/util_funcs.c

out/check_main.o : unit_tests/check_main.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/check_funcs.o : unit_tests/check_funcs.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_funcs.o unit_tests/check_funcs.c

out/check_util_funcs.o : unit_tests/check_util_funcs.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_util_funcs.o unit_tests/check_util_funcs.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe
