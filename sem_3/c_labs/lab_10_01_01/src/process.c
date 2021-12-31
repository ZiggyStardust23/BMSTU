#include "../inc/process.h"

int process(char *in_fname, char *out_fname)
{
    int error_code = 0;

    FILE *f = NULL;
    
    if (error_code == 0)
        f = fopen(in_fname, "r");

    if (error_code == 0 && f == NULL)
        error_code = FILE_NOT_FOUND;

    node_t *head = NULL;

    if (error_code == 0)
    {
        head = malloc(sizeof(node_t));
        read_from_file_to_list(f, head);
    }

    int choice = 0;
    if (error_code == 0)
    {
        print_menu();
        scanf("%d", &choice);
    }
    while (choice != 4 && error_code == 0)
    {
        if (choice == 1)
            print_list(head);
        else if (choice == 2)
            pop_front(&head);
        else if (choice == 3)
            add_elem(&head);
        else if (choice != 4)
            printf("Try again");
        if (choice != 4)
        {
            print_menu();
            scanf("%d", &choice);
        }
    }

    FILE *f_out = fopen(out_fname, "w");

    write_to_file(f_out, head);

    free_list(head);

    fclose(f);
    fclose(f_out);

    return error_code;
}