CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : out/main.o out/my_snprintf.o
	gcc -o app.exe out/main.o out/my_snprintf.o -lm

unit_tests.exe : out/check_main.o out/check_my_snprintf.o out/my_snprintf.o
	gcc -o unit_tests.exe out/check_main.o out/check_my_snprintf.o out/my_snprintf.o

out/main.o : src/main.c inc/my_snprintf.h
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/check_main.o : unit_tests/check_main.c inc/my_snprintf.h inc/check_my_snprintf.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c 

out/my_snprintf.o : src/my_snprintf.c inc/my_snprintf.h
	gcc $(CFLAGS) -c -o out/my_snprintf.o src/my_snprintf.c

out/check_my_snprintf.o : unit_tests/check_my_snprintf.c inc/check_my_snprintf.h inc/my_snprintf.h
	gcc $(CFLAGS) -c -o out/check_my_snprintf.o unit_tests/check_my_snprintf.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe