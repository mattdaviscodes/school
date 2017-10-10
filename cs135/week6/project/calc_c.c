/*
 * Name: calc_c.c
 * Purpose: Practice interactive programs by implementing a scientific calculator
 * Author: Matt Davis
 * Created: 10/9/17
 * Last Updated: 10/9/17
 */

#include <stdio.h>
#include <math.h>

// Prototypes
void print_options(void);
void add(void);
void subtract(void);
void multiply(void);
void divide(void);
void toggle_precision(void);
void _exp(void);
void _log(void);

// Flag for double precision toggle
int double_precision = 0;

int main(void)
{

    int end = 0;
    int option;

    printf("This program implements a calculator. Options:\n");
    print_options();
    while (!end) {
        printf("Please enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add();
                continue;
            case 2:
                subtract();
                continue;
            case 3:
                multiply();
                continue;
            case 4:
                divide();
                continue;
            case 5:
                toggle_precision();
                continue;
            case 6:
                end = 1;
                break;
            case 7:
                _exp();
                continue;
            case 8:
                _log();
                continue;
            default:
                print_options();
        }
    }

    return 0;
}


void print_options(void)
{
    printf(
        "1 - addition\n"
        "2 - subtraction\n"
        "3 - multiplication\n"
        "4 - division\n"
        "5 - toggle precision\n"
        "6 - exit program\n"
        "7 - Compute exp(x)\n"
        "8 - Compute log(x)\n"
    );
}

void add(void)
{
    if (!double_precision) {
        float x, y;
        printf("Enter first term: ");
        scanf("%f", &x);
        printf("Enter second term: ");
        scanf("%f", &y);
        printf("The sum is: %f\n", x + y);
    } else {
        double x, y;
        printf("Enter first term: ");
        scanf("%lf", &x);
        printf("Enter second term: ");
        scanf("%lf", &y);
        printf("The sum is: %.15lf\n", x + y);
    }
}

void subtract(void)
{
    if (!double_precision) {
        float x, y;
        printf("Enter first term: ");
        scanf("%f", &x);
        printf("Enter second term: ");
        scanf("%f", &y);
        printf("The difference is: %f\n", x - y);
    } else {
        double x, y;
        printf("Enter first term: ");
        scanf("%lf", &x);
        printf("Enter second term: ");
        scanf("%lf", &y);
        printf("The difference is: %.15lf\n", x - y);
    }
}

void multiply(void)
{
    if (!double_precision) {
        float x, y;
        printf("Enter first term: ");
        scanf("%f", &x);
        printf("Enter second term: ");
        scanf("%f", &y);
        printf("The product is: %f\n", x * y);
    } else {
        double x, y;
        printf("Enter first term: ");
        scanf("%lf", &x);
        printf("Enter second term: ");
        scanf("%lf", &y);
        printf("The product is: %.15lf\n", x * y);
    }
}

void divide(void)
{
    if (!double_precision) {
        float x, y;
        printf("Enter first term: ");
        scanf("%f", &x);
        printf("Enter second term: ");
        scanf("%f", &y);
        if (y == 0) {
            printf("Cannot divide by zero!\n");
        } else {
            printf("The quotient is: %f\n", x / y);
        }
    } else {
        double x, y;
        printf("Enter first term: ");
        scanf("%lf", &x);
        printf("Enter second term: ");
        scanf("%lf", &y);
        if (y == 0) {
            printf("Cannot divide by zero!\n");
        } else {
            printf("The quotient is: %.15lf\n", x / y);
        }
    }
}

void toggle_precision(void)
{
    if (!double_precision) {
        double_precision = 1;
        printf("Calculator now works with double precision.\n");
    } else {
        double_precision = 0;
        printf("Calculator now works with single precision.\n");
    }
}

void _exp(void)
{
    if (!double_precision) {
        float x;
        printf("Enter term: ");
        scanf("%f", &x);
        printf("The result of exp(x) is: %f\n", exp(x));
    } else {
        double x;
        printf("Enter term: ");
        scanf("%lf", &x);
        printf("The result of exp(x) is: %.15lf\n", exp(x));
    }
}

void _log(void)
{
    if (!double_precision) {
        float x;
        printf("Enter term: ");
        scanf("%f", &x);
        if (x < 0) {
            printf("Cannot take the log of a negative number!\n");
        } else {
            printf("The result of log(x) is: %f\n", log(x));
        }
    } else {
        double x;
        printf("Enter term: ");
        scanf("%lf", &x);
        if (x < 0) {
            printf("Cannot take the log of a negative number!\n");
        } else {
            printf("The result of log(x) is: %.15lf\n", log(x));
        }
    }
}
