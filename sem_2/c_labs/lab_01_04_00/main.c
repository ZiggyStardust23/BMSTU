#include <stdio.h>

int main()
{
    int amount_of_money, bottles_to_buy;

    scanf("%d", &amount_of_money);

    bottles_to_buy = amount_of_money - 20;
    bottles_to_buy = bottles_to_buy / 25;

    printf("%d", bottles_to_buy);

    return 0;
}
