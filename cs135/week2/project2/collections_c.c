/*
 * Name: collections_.c
 * Purpose: Evaluate Bob's ability to buy books based on logical expressions, extra credit
 * Author: Matt Davis
 * Created: 9/15/17
 * Last Updated: 9/15/17
 */

#include <stdio.h>

int main(void)
{

    // Input variables
    int collection1_volumes, collection1_price, collection2_volumes,
    collection2_price, collection3_volumes, collection3_price, budget;

    // Calculated variables
    int collection1_cost, collection2_cost, collection3_cost;

    // Prompt user for input
    printf("Enter volumes and price per volume for collection 1: ");
    scanf("%d %d", &collection1_volumes, &collection1_price);
    printf("Enter volumes and price per volume for collection 2: ");
    scanf("%d %d", &collection2_volumes, &collection2_price);
    printf("Enter volumes and price per volume for collection 3: ");
    scanf("%d %d", &collection3_volumes, &collection3_price);
    printf("Enter Bob's budget: ");
    scanf("%d", &budget);

    // Evaluate calculated variables
    collection1_cost = collection1_price * collection1_volumes;
    collection2_cost = collection2_price * collection2_volumes;
    collection3_cost = collection3_price * collection3_volumes;

    // Evaluate all logical requirements and print
    if (budget > 0)
    {
        printf("(1) Bob has some money to buy collections.\n");
    }
    else
    {
        printf("(1) Bob does not have money to buy anything.\n");
    }

    if (budget >= collection1_cost + collection2_cost + collection3_cost)
    {
        printf("(2) Bob has enough money to buy all three collections.\n");
    }
    else
    {
        printf("(2) Bob does not have enough money to buy all three collections.\n");
    }

    if (collection1_cost > budget && collection2_cost > budget ||
        collection1_cost > budget && collection3_cost > budget ||
        collection2_cost > budget && collection3_cost > budget)
    {
        printf("(3) At least two collections are more expensive than Bob's budget.\n");
    }
    else
    {
        printf("(3) At least two collections are cheaper than or equal to Bob's budget.\n");
    }

    if (collection1_cost == collection2_cost ||
        collection1_cost == collection3_cost ||
        collection2_cost == collection3_cost)
    {
        printf("(4) At least two collections cost the same amount of money.\n");
    }
    else
    {
        printf("(4) No two collections have the same price.\n");
    }

    if (collection1_cost <= budget && collection2_cost > budget && collection3_cost > budget ||
        collection2_cost <= budget && collection1_cost > budget && collection3_cost > budget ||
        collection3_cost <= budget && collection1_cost > budget && collection2_cost > budget)
    {
        printf("(5) Only one collection is cheaper than or equal to Bob's budget.\n");
    }
    else
    {
        printf("(5) More than one collection is cheaper than or equal to Bob's budget or they are all more expensive.\n");
    }

    if (budget >= collection1_cost && budget >= collection2_cost && budget >= collection3_cost)
    {
        printf("(6) Bob has enough money to buy any one of the three collections.\n");
    }
    else
    {
        printf("(6) Bob does not have enough money to buy any one of the three collections.\n");
    }

    if (budget < collection1_cost && budget < collection2_cost && budget < collection3_cost)
    {
        printf("(7) Bob does not have enough money to buy any collection.\n");
    }
    else
    {
        printf("(7) Bob can buy at least one collection.\n");
    }

    return 0;

}
