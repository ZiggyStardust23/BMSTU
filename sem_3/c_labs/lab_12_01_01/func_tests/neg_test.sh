#!/bin/bash
../app.exe `cat neg_$1_args.txt` > out.txt
error_code=$?

errors=("OK" "INCORRECT_ARGS" "MEMORY_ERROR" "DATA_IS_EMPTY" "FILE_NOT_FOUND" "SRC_ARR_IS_EMPTY" "DST_ARR_IS_EMPTY" "FILE_IS_INCORRECT" "INCORRECT_PARAMS")

{
FC out.txt neg_00_out.txt
  rc_s=$?
} &> /dev/null
if [ $rc_s == 0 ] && [ $error_code != 0 ]
then
echo -e NEG_"$1": "\e[32mPASSED\e[0m Код ошибки: ${errors[error_code]} = $error_code"
else
FC out.txt neg_00_out.txt
echo -e NEG_"$1": "\e[31mFAILED\e[0m Код ошибки: ${errors[error_code]} = $error_code"
fi
rm "out.txt"
rm -rf "neg_out.txt"