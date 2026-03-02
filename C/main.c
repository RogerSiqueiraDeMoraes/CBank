#include <stdio.h>
#include "helpers.c"

int main() {
    int options = 0;
    printf("Options:\n1. Check Balance\n2. Deposit\n3. Withdraw\n4. Exit\n");

    while (options != 4) {
        printf("Enter your choice: ");
        scanf("%i", &options);
        switch (options) {
            case 1:
                printf("Your balance is $1000\n");
                break;
            case 2:
                printf("Deposit successful\n");
                break;
            case 3:
                printf("Withdrawal successful\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

}