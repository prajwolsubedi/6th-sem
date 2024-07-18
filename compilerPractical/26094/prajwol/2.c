#include <stdio.h>
#include <string.h>

typedef enum { Q0, Q1, Q2 } State;

State getNextState(State currentState, char input) {
    switch (currentState) {
        case Q0:
            return (input == '0') ? Q1 : Q0;
        case Q1:
            return (input == '1') ? Q2 : Q1;
        case Q2:
            return (input == '0') ? Q1 : Q0;
        default:
            return Q0;
    }
}

int isAccepted(char *str) {
    State currentState = Q0;
    for (int i = 0; i < strlen(str); i++) {
        currentState = getNextState(currentState, str[i]);
    }
    return (currentState == Q2);
}

int main() {
    char input[100];

    printf("Enter a binary string: ");
    scanf("%s", input);

    if (isAccepted(input)) {
        printf("The string is accepted by the DFA.\n");
    } else {
        printf("The string is not accepted by the DFA.\n");
    }

    return 0;
}