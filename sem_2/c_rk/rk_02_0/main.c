#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_NUM_OF_CITIES 1300

#define INCORRECT_INPUT -1
#define INCORRECT_NUM_OF_CITIES -2
#define FILE_ERROR -3

//Структура для представления города
struct city
{
    char name[MAX_STR_LEN];
	char region[MAX_STR_LEN];
	char district[MAX_STR_LEN];
	int people;
	int year;
};

//Функция читает строки файла и заполняет структуры в массиве структур
//Возвращает код ошибки, либо 0 если ошибок нет
int read_struct(struct city struct_arr[MAX_NUM_OF_CITIES], int num_of_cities, FILE * in_file)
{
	for (int i = 0; i < num_of_cities; i++)
	{
		char cur_name[MAX_STR_LEN];
		if (fscanf(in_file, "%s", cur_name) != 1)
			return INCORRECT_INPUT;
		
		char cur_region[MAX_STR_LEN];
		if (fscanf(in_file, "%s", cur_region) != 1)
			return INCORRECT_INPUT;
		
		char cur_district[MAX_STR_LEN];
		if (fscanf(in_file, "%s", cur_district) != 1)
			return INCORRECT_INPUT;
		
		int cur_people;
		if (fscanf(in_file, "%d", &cur_people) != 1)
			return INCORRECT_INPUT;
		
		int cur_year;
		if (fscanf(in_file, "%d", &cur_year) != 1)
			return INCORRECT_INPUT;
		
		strcpy(struct_arr[i].name, cur_name);
		strcpy(struct_arr[i].region, cur_region);
		strcpy(struct_arr[i].district, cur_district);
		struct_arr[i].people = cur_people;
		struct_arr[i].year = cur_year;
	}
	
	return 0;
}


int main()
{
    struct city struct_arr[1300];
	int num_of_cities;
	
	FILE * in_file = fopen("in.txt", "r");
	
	if (in_file == NULL)
		return FILE_ERROR;
	
	//Чтение первой строки файла, чтобы определить количество городов
	if (fscanf(in_file, "%d", &num_of_cities) != 1)
	{
		return INCORRECT_INPUT;
		fclose(in_file);
	}
	if (num_of_cities < 0 && num_of_cities > MAX_NUM_OF_CITIES)
	{
		return INCORRECT_NUM_OF_CITIES;
		fclose(in_file);
	}
	//Заполнение массива структур
	if (read_struct(struct_arr, num_of_cities, in_file) != 0)
		return INCORRECT_INPUT;
	
    //Подсчет суммы населения всех городов
	long int sum_of_people = 0;
	
	for (int i = 0; i < num_of_cities; i++)
		sum_of_people += struct_arr[i].people;
		
	//Нахождение средней численности населения
	int average_people = (int)(sum_of_people / num_of_cities);
	

	//Определение даты основания города, с самым большим
	//количеством вхождений буквы s в название
	int year_to_find = 0;
	int max_num_of_s = 0;
	for (int i = 0; i < num_of_cities; i++)
	{
		char cur_name[MAX_STR_LEN];
		int cur_num_of_s = 0;
		strcpy(cur_name, struct_arr[i].name);
		int j = 0;
		
		while (cur_name[j] != '\0')
		{
			if (cur_name[j] == 's')
				cur_num_of_s++;
			j++;
		}
		
		if (cur_num_of_s > max_num_of_s)
		{
			max_num_of_s = cur_num_of_s;
			year_to_find = struct_arr[i].year;
		}
	}
	
	//Создание(или перезапись) файла для вывода
	FILE * out_file = fopen("out.txt", "w"); 
	fprintf(out_file, "%d\n%d", average_people, year_to_find);
	
	fclose(in_file);
	fclose(out_file);
	
	return 0;
}