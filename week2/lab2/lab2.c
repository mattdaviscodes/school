/*
 * Name: lab2.c
 * Author: Matt Davis
 * Purpose: Assignment for CS135 Lab2
 */

#include <stdio.h>

#define MINUTES_PER_WEEK 10080
#define MINUTES_PER_DAY 1440
#define MINUTES_PER_HOUR 60

int main(void)
{



    // Decalare needed variables
    int minutes_in;
    int weeks_out, days_out, hours_out, minutes_out;

    // Prompt user for input
    printf("Enter a number of minutes: ");
    scanf("%d", &minutes_in);

    // Calculate output
    weeks_out = minutes_in / MINUTES_PER_WEEK;  // Remainder will be truncated
    days_out = (minutes_in % MINUTES_PER_WEEK) / MINUTES_PER_DAY;
    hours_out = (minutes_in % MINUTES_PER_DAY) / MINUTES_PER_HOUR;
    minutes_out = minutes_in % MINUTES_PER_HOUR;


    // Print output
    printf("This represents: %d weeks, %d days, %d hours, and %d minutes\n", weeks_out, days_out, hours_out, minutes_out);

    return 0;
}
