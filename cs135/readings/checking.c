/* Allow user to balance checkbook using loops and control statements */

#include "stdio.h"

int main(void)
{
    int command;
    float balance = 0.0f, credit = 0, debit = 0;

    // Show options to user
    printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");

    while (1) {
        printf("Enter command: ");
        scanf("%d", &command);

        // Error check, only accept allowed inputs
        if (command < 0 || command > 4) {
            continue;
        }

        switch (command) {
            case 0:
                balance = 0.0f;
                printf("Balance cleared.\nCurrent balance: $%.2f\n", balance);
                break;
            case 1:
                printf("Enter amount of credit: ");
                scanf("%f", &credit);
                balance += credit;
                break;
            case 2:
                printf("Enter amount of debit: ");
                scanf("%f", &debit);
                balance -= debit;
                break;
            case 3:
                printf("Current balance: $%.2f\n", balance);
                break;
            case 4:
                return 0;
        }
    }

}
