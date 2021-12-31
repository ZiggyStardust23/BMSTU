#include "dynamic_load.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    int error_code = 0;
    
    HMODULE hlib;
    fn_free_arr_t free_arr;
    fn_get_count_elements_t find_num_of_elems;
    fn_read_array_t read_arr;
    fn_create_array_t create_arr;
    fn_fprint_t fprint;
    fn_swap_t swap;
    fn_allocate_arr_t allocate_arr;
    fn_mysort_t mysort;
    fn_find_arr_size_after_key_t find_arr_size_after_key;
    fn_key_t key;
    fn_key_swap_t key_swap;
    fn_comparator_t comparator;
    
    hlib = LoadLibrary("dynamic_lib.dll");
    if (hlib == NULL)
        error_code = LIB_ERROR;
    else
    {
        error_code = lib_allocate_and_free(hlib, &allocate_arr, &free_arr);
        
        if (error_code == 0)
            error_code = lib_io_and_create(hlib, &find_num_of_elems, &create_arr, &read_arr, &fprint);
        
        if (error_code == 0)
            error_code = lib_key_and_sort(hlib, &swap, &mysort, &find_arr_size_after_key, &key, &key_swap, &comparator);
        
        if (error_code == 0)
        {
            if (argc < 3 || argc > 4)
               error_code = INCORRECT_PARAMS;
        }

        FILE *f_in, *f_out;

        if (error_code == 0)
        {
            f_in = fopen(argv[1], "r");
            if (f_in == NULL)
                error_code = FILE_ERROR;
        }
        if (error_code == 0)
        {
            int *pb_src = NULL, *pe_src = NULL;
            int *pb_dst = NULL, *pe_dst = NULL;
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
                        if (error_code == 0)
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
        
        FreeLibrary(hlib);
    }    
    return error_code;
}
