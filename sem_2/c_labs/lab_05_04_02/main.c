#include "funcs.h"

int main(int argc, char **argv)
{
    int err_code;

    if (argc == 4)
    {
        if (strcmp(argv[1], "sb") == 0)
        {
            if ((err_code = sort(argv[2], argv[3])) != 0)
                return err_code;
        }
        else if (strcmp(argv[1], "fb") == 0)
        {
            if ((err_code = print_goods(argv[2], argv[3])) != 0)
                return err_code;
        }
        else
            return INCORRECT_PARAMS;
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "ab") == 0)
        {
            if ((err_code = add_new(argv[2])) != 0)
                return err_code;
        }
        else
            return INCORRECT_PARAMS;
    }
    else
        return INCORRECT_PARAMS;

    return 0;
}