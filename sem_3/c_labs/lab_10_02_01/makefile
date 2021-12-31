CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : out/main.o out/funcs.o out/process.o out/io.o
	gcc -o app.exe out/main.o out/funcs.o out/process.o out/io.o -lm

unit_tests.exe : out/check_main.o out/check_funcs.o out/funcs.o
	gcc -o unit_tests.exe out/check_main.o out/check_funcs.o out/funcs.o -lm

out/main.o : src/main.c inc/funcs.h inc/struct.h
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/funcs.o : src/funcs.c inc/funcs.h inc/struct.h
	gcc $(CFLAGS) -c -o out/funcs.o src/funcs.c

out/process.o : src/process.c inc/process.h inc/struct.h inc/funcs.h
	gcc $(CFLAGS) -c -o out/process.o src/process.c

out/io.o : src/io.c inc/io.h inc/struct.h
	gcc $(CFLAGS) -c -o out/io.o src/io.c

out/check_main.o : unit_tests/check_main.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/check_funcs.o : unit_tests/check_funcs.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_funcs.o unit_tests/check_funcs.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe