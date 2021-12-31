#!/bin/bash

../app.exe `cat pos_"$1"_args.txt` > "out.txt"
error_code=$?

errors=("OK" "INCORRECT_ARGS" "MEMORY_ERROR" "DATA_IS_EMPTY" "FILE_NOT_FOUND" "SRC_ARR_IS_EMPTY" "DST_ARR_IS_EMPTY" "FILE_IS_INCORRECT" "INCORRECT_PARAMS")

{
FC pos_out.txt pos_"$1"_out.txt
  rc_f=$?
FC out.txt neg_00_out.txt
  rc_s=$?
} &> /dev/null

if [ $rc_s == 0 ] && [ $error_code == 0 ] && [ $rc_f == 0 ]
then
echo -e POS_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[error_code]} = $error_code"
else
FC pos_out.txt pos_"$1"_out.txt
echo -e POS_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[error_code]} = $error_code"
fi
rm out.txt pos_out.txt