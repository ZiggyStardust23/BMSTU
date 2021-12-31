#include "utils.h"
#include "key.h"
#include "mysort.h"

int main(int argc, char **argv)
{
    int error_code = 0;

    setbuf(stdout, NULL);

    if (argc < 3 || argc > 4)
       error_code = INCORRECT_PARAMS;

    FILE *f_in, *f_out;
    
    if (error_code == 0)
    {
        f_in = fopen(argv[1], "r");
        if (f_in == NULL)
            error_code = FILE_ERROR;
    }
        
    if (error_code == 0)
    {
        int *pb_src = NULL, *pe_src = NULL, *pb_dst = NULL, *pe_dst = NULL;
        size_t src_len = 0;
        
        f_out = fopen(argv[2], "w");
        error_code = create_arr(f_in, &pb_src, &src_len);
        
        if (error_code == 0)
        {
            pe_src = pb_src + src_len;
            
            if (argc == 4)
            {
                if (strcmp(argv[3], "f") == 0)
                {
                    int dst_len = find_arr_size_after_key(pb_src, pe_src);
                    if (dst_len == 0)
                        error_code = DST_ARR_IS_EMPTY;
                    else
                    {
                        pb_dst = (int *) malloc(dst_len * sizeof(int));
                        if (pb_dst == NULL)
                            error_code = MEMORY_ERROR;
                        else
                        {
                            pe_dst = pb_dst + dst_len;
                            error_code = key(pb_src, pe_src, pb_dst, pe_dst);

                            if (error_code == 0)
                            {
                                mysort(pb_dst, pe_dst - pb_dst, sizeof(int), comparator);

                                fprint(f_out, pb_dst, pe_dst);
                            }
                            free_arr(&pb_dst, &pe_dst);
                        }
                    }
                }
                else
                    error_code = INCORRECT_PARAMS;
            }
            else
            {
                mysort(pb_src, pe_src - pb_src, sizeof(int), comparator);
                fprint(f_out, pb_src, pe_src);
            }
        }
        free_arr(&pb_src, &pe_src);
        fclose(f_in);
        fclose(f_out);
    } 
    
    return error_code;
}
