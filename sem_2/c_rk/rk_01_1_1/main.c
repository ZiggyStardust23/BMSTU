#include <stdio.h>

#define INCORRECT_INPUT -1
#define NUM_NOT_NATURAL -2

int find_sum_of_min_and_max(int num)
{
	int save_num = num;
	int sum = 0;
	int cur_num;
	int max = save_num % 10;
	int min = save_num % 10;
	
	while (save_num > 0)
	{
		cur_num = save_num % 10;
		save_num = (save_num - cur_num) / 10;
		
		if (cur_num > max)
			max = cur_num;
		if (cur_num < min)
			min = cur_num;	
	}
	
	sum = max + min;
	
	return sum;
}

int main()
{
	int num;
	int result;
	
	if (scanf("%d", &num) != 1)
		return INCORRECT_INPUT;
	
	if (num <= 0)
		return NUM_NOT_NATURAL;
	
	result = find_sum_of_min_and_max(num);
	
	printf("%d", result);
	
	return 0;
}



