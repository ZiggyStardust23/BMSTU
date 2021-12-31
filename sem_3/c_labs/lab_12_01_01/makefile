INC := ./inc
OUT := ./out
SRC := ./src

CC := gcc
CFLAGS := -std=c99 -Werror -Wall -Wpedantic -ggdb -I$(INC)

############################################

DYNAMIC_ALL := $(OUT)/dynamic_io_utils.o $(OUT)/dynamic_sort.o $(OUT)/dynamic_key.o
DYNAMIC_MAIN := $(SRC)/dynamic_main.c
DYNAMIC_LOAD := $(SRC)/dynamic_load_main.c $(SRC)/dynamic_load.c

ALL := $(OUT)/io_utils.o $(OUT)/mysort.o $(OUT)/key.o
MAIN := $(SRC)/main.c
UNIT := $(OUT)/check_main.o $(OUT)/check_key.o $(OUT)/check_sort.o
DYN_UNIT := $(OUT)/dynamic_check_main.o $(OUT)/dynamic_check_key.o $(OUT)/dynamic_check_sort.o

############################################

dynamic_load: $(DYNAMIC_LOAD) dynamic_lib.dll
	$(CC) $(CFLAGS) $^ -o app.exe

dynamic_link: $(DYNAMIC_MAIN) dynamic_lib.dll
	$(CC) $(CFLAGS) $< -L. dynamic_lib.dll -o app.exe

static: $(MAIN) static_lib.a
	$(CC) $(CFLAGS) $^ -o app.exe

static_unit_tests: $(UNIT) $(ALL)
	$(CC) -o unit_tests.exe $^ -lcheck

dynamic_unit_tests: $(DYN_UNIT)
	$(CC) $^ -L. dynamic_lib.dll -o unit_tests.exe -lcheck

dynamic_lib.dll: $(DYNAMIC_ALL)
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@

############################################

$(OUT)/dynamic_%.o: ${SRC}/dynamic_%.c ${INC}/dynamic_*.h object_dir
	$(CC) $(CFLAGS) -D ARR_EXPORTS -c $< -o $@
    
$(OUT)/dynamic_check_%.o: ./unit_tests/check_%.c ${INC}/check_*.h object_dir
	$(CC) $(CFLAGS) -D DYNAMIC_UNIT -c $< -o $@
    
$(OUT)/check_%.o: ./unit_tests/check_%.c ${INC}/check_*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

############################################

static_lib.a: $(ALL)
	ar rc $@ $^
	ranlib $@

$(OUT)/%.o: ${SRC}/%.c ${INC}/*.h object_dir
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: func
func:
	cd ./func_tests && bash all_tests.sh

.PHONY: clean
clean:
	$(RM) $(OUT)/*.o
	$(RM) *.exe
	$(RM) *.o
	$(RM) *.a *.dll
	rm -rf $(OUT)


