#include <stdio.h>
#include <string.h>

// Function to check if a character is an operator
int isOperator(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
        case '=':
        case '<':
        case '>':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char input[1000];
    int count = 0;

    // Prompt the user for a string
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Iterate over each character in the string
    for (int i = 0; i < strlen(input); i++) {
        if (isOperator(input[i])) {
            count++;
        }
    }

    // Print the count of operators
    printf("The number of operators in the string: %d\n", count);

    return 0;
}
