
// A valid identifier in C must start with a letter (either uppercase or lowercase) or an underscore (_) and can be followed by letters, digits (0-9), or underscores. Here is a simple C program to check whether a given identifier is valid or not:
#include <stdio.h>
#include <ctype.h>

int isValidIdentifier(char *identifier) {
    if (!(isalpha(identifier[0]) || identifier[0] == '_')) {
        return 0; // Not a valid identifier
    }

    // Check the remaining characters
    for (int i = 1; identifier[i] != '\0'; i++) {
        if (!(isalnum(identifier[i]) || identifier[i] == '_')) {
            return 0;
        }
    }

    return 1; 
}

int main() {
    char identifier[100];

    printf("Enter an identifier: ");
    scanf("%s", identifier);

    if (isValidIdentifier(identifier)) {
        printf("'%s' is a valid identifier.\n", identifier);
    } else {
        printf("'%s' is not a valid identifier.\n", identifier);
    }

    return 0;
}
