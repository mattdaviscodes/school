/*
 * Name: lab4.c
 * Author: Matt Davis
 * Purpose: Calculate how much user can purchase with budget
 * Date: 10/2/17
 */

#include <stdio.h>

int main(void)
{
    int budget, items, price, cost;

    printf("Please enter your budget: ");
    scanf("%d", &budget);

    while (budget > 0) {
        printf("Please enter the items and price: ");
        scanf("%d, %d", &items, &price);

        cost = items * price;

        if (budget >= cost) {
            budget -= cost;
        } else {
            printf("You cannot buy the last items.\n");
            printf("Your remaining budget is %d.\n", budget);
            break;
        }
    }

    return 0;
}
