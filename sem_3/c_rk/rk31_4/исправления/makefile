CFLAGS := -std=c99 -Wall -Werror -pedantic -Wvla

a.exe : main.o matrix_funcs.o snake.o util.o
	gcc -o a.exe main.o matrix_funcs.o snake.o util.o

main.o : main.c matrix_funcs.h snake.h util.h
	gcc $(CFLAGS) -c -o main.o main.c

snake.o : snake.c snake.h
	gcc $(CFLAGS) -c -o snake.o snake.c

util.o : util.c util.h
	gcc $(CFLAGS) -c -o util.o util.c

matrix_funcs.o : matrix_funcs.c matrix_funcs.h
	gcc $(CFLAGS) -c -o matrix_funcs.o matrix_funcs.c

.PHONY : clean
clean :
	rm -rf *.o *.exe
