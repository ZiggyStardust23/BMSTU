#include <stdio.h>

#define MAX_ARRAY_LENGTH 10
#define INCORRECT_LENGTH -1
#define INCORRECT_INPUT -2
#define THERE_IS_NO_ODDS -3

int main()
{
    int array_length;
    int current_element;
    int mult_of_odds = 1;
    int num_of_odds = 0;

    if (scanf("%d", &array_length) != 1)
        return INCORRECT_INPUT;
    if (array_length < 1 || array_length > MAX_ARRAY_LENGTH)
        return INCORRECT_LENGTH;
    
    int array[MAX_ARRAY_LENGTH];

    for (int i = 0; i < array_length; i++)
    {   
        if (scanf("%d", &current_element) != 1)
            return INCORRECT_INPUT;

        array[i] = current_element;

        if (array[i] % 2 != 0)
        {
            mult_of_odds *= array[i];
            num_of_odds += 1;
        }
    }

    if (num_of_odds == 0)
    {
        return THERE_IS_NO_ODDS;
    }

    printf("%d", mult_of_odds);

    return 0;
}

