CFLAGS := -std=c99 -Wall -Werror -pedantic

app.exe : out/main.o out/matrix_math.o out/matrix_utils.o out/utils.o
	gcc -o app.exe out/main.o out/matrix_math.o out/matrix_utils.o out/utils.o -lm

unit_tests.exe : out/check_main.o out/check_matrix_math.o out/check_matrix_utils.o out/matrix_math.o out/matrix_utils.o out/utils.o
	gcc -o unit_tests.exe out/check_main.o out/check_matrix_math.o out/check_matrix_utils.o out/matrix_math.o out/matrix_utils.o out/utils.o -lm

out/main.o : src/main.c inc/main.h
	gcc $(CFLAGS) -c -o out/main.o src/main.c

out/matrix_math.o : src/matrix_math.c inc/matrix_math.h inc/utils.h
	gcc $(CFLAGS) -c -o out/matrix_math.o src/matrix_math.c

out/matrix_utils.o : src/matrix_utils.c inc/matrix_utils.h inc/utils.h
	gcc $(CFLAGS) -c -o out/matrix_utils.o src/matrix_utils.c

out/utils.o : src/utils.c inc/utils.h
	gcc $(CFLAGS) -c -o out/utils.o src/utils.c

out/check_main.o : unit_tests/check_main.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_main.o unit_tests/check_main.c

out/check_matrix_math.o : unit_tests/check_matrix_math.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_matrix_math.o unit_tests/check_matrix_math.c

out/check_matrix_utils.o : unit_tests/check_matrix_utils.c inc/check_main.h
	gcc $(CFLAGS) -c -o out/check_matrix_utils.o unit_tests/check_matrix_utils.c

.PHONY : clean
clean :
	$(RM) out/*.o *.exe
