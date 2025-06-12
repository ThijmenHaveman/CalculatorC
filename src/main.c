#include <stdio.h>

int main() {
    int num1, num2;
    int sum, diff, mult;
    int success = 0;
    float quot;

    printf("Enter two integers and the operation you would like to perform:\n");

    // expecting 1 int, 1 int, and 1 char (operation) on separate inputs / lines 
    char op;
    printf("Enter operation (+, -, *, /): ");
    scanf_s("%c", &op, 1);

    printf("Enter two integers: ");
    if (scanf_s("%d %d", &num1, &num2) != 2) {
        printf("Error: Invalid input.\n");
        return 1;
    }

    sum = num1 + num2;
    diff = num1 - num2;
    mult = num1 * num2;
    quot = num1 / num2;

    if (op == '+') {
        printf("Sum: %d\n", sum);
        success = 1;
    }
    else if (op == '-') {
        printf("Difference: %d\n", diff);
        success = 1;
    }
    else if (op == '*') {
        printf("%d %c %d = %d\n", num1, op, num2, mult);
        success = 1;
    }
    else if (op == '/') {
        if (num2 == 0) {
            printf("Error: Division by zero.\n");
        } else {
            printf("%d %c %d = %.2f\n", num1, op, num2, quot);
            success = 1;
        }
    }
    else {
        printf("Invalid operation.\n");
        printf("Valid operations are: +, -, *, /\n");
        printf("Please try again.\n");
        main();
        return 0;
    }

    // does the user want to perform another calculation?
    if (success) {
        printf("Calculation completed, would you like to perform another calculation?\n");
        printf("Type \"Yes\" or \"No\":\n");

        char response[4];
        scanf_s("%3s", response, (unsigned int)sizeof(response));
        if (response[0] == 'Y' || response[0] == 'y') {
            main();
        } else {
            printf("Exiting the program.\n");
        }
    } else {
        printf("failed.\n");
    }

    return 0;
}