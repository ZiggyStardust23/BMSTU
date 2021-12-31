#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NOT_FOUND -1
#define INCORRECT_ARG -2


typedef struct node node;
typedef struct student student;

struct student
{
	char name[255];
	node *mark_head;
	int age;
};

struct node
{
	struct student data;
	int num;
	node *next_elem;
};

int main(int argc, char **argv)
{
	FILE *f = NULL;
	
	int error_code = 0;
	
	if (argc == 3 && strcmp(argv[1], "-f") == 0)
	{
		f = fopen(argv[2], "r");
		
		if (f == NULL)
		{
			printf("File not found");
			error_code = FILE_NOT_FOUND;
		}
		
		else
		{
			node *head = NULL;
			
			student cur_student;
			
			int cur_age;
			int cur_mark_int;
			node *cur_elem = NULL;
			node *cur_head_mark = NULL;
			node *cur_mark;
			

			if (fscanf(f, "%s", cur_student.name) == 1)
			{
				
				fscanf(f, "%d", &cur_age);
				cur_student.age = cur_age;
			
				fscanf(f, "%d", &cur_mark_int);
				cur_head_mark = malloc(sizeof(node));
				cur_head_mark->num = cur_mark_int;
				cur_head_mark->next_elem = NULL;
				cur_mark = cur_head_mark;
				
				while (fscanf(f,"%d", &cur_mark_int) == 1)
				{
					cur_mark->next_elem = malloc(sizeof(node));
					cur_mark = cur_mark->next_elem;
					cur_mark->num = cur_mark_int;;
					cur_mark->next_elem = NULL;
				}
				
				cur_student.mark_head = cur_head_mark;
			
				head = malloc(sizeof(node));
				head->data = cur_student;
				head->next_elem = NULL;
			}
			
			cur_elem = head;

			while (fscanf(f, "%s", cur_student.name) == 1)
			{
				fscanf(f, "%d", &cur_age);
				cur_student.age = cur_age;
			
				fscanf(f, "%d", &cur_mark_int);
			
				cur_head_mark = malloc(sizeof(node));
				cur_head_mark->num = cur_mark_int;
				
				cur_head_mark->next_elem = NULL;
				cur_mark = cur_head_mark;
				
				while (fscanf(f,"%d", &cur_mark_int) == 1)
				{
					cur_mark->next_elem = malloc(sizeof(node));
					cur_mark = cur_mark->next_elem;
					cur_mark->num = cur_mark_int;
					cur_mark->next_elem = NULL;
				}
				cur_student.mark_head = cur_head_mark;
			
				cur_elem->next_elem = malloc(sizeof(node));
				cur_elem = cur_elem->next_elem;
				cur_elem->data = cur_student;
				cur_elem->next_elem = NULL;
			}
			cur_elem = head;
			while (cur_elem != NULL)
			{
				printf("%s ", cur_elem->data.name);
				printf("%d ", cur_elem->data.age);
				cur_mark = cur_elem->data.mark_head;
				
				while (cur_mark != NULL)
				{
					printf("%d ", cur_mark->num);
					cur_mark = cur_mark->next_elem;
				}
				
				printf("\n");
				cur_elem = cur_elem->next_elem;
			}
			
			cur_elem = head;
			while (cur_elem != NULL)
			{
				node *element_to_delete = cur_elem;
				cur_mark = cur_elem->data.mark_head;
				while (cur_mark != NULL)
				{
					node *element_to_delete = cur_mark;
					cur_mark = cur_mark->next_elem;
					free(element_to_delete);
				}
				cur_elem = cur_elem->next_elem;
				free(element_to_delete);
			}
			
		}
	}
	else 
	{
		printf("Key not valid");
		error_code = INCORRECT_ARG;
	}
	return error_code;
}