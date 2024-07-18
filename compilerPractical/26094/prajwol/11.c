#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_SIZE 100

// Structure to represent a stack
struct Stack {
    int top;
    char *array;
};

// Function to create a stack of given size
struct Stack* createStack(int size) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->array = (char*)malloc(size * sizeof(char));
    return stack;
}

// Function to push an element to the stack
void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1)
        return '\0';
    return stack->array[stack->top--];
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to return the precedence of the operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int k = 0;

    for (int i = 0; infix[i]; i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack->top != -1 && stack->array[stack->top] != '(') {
                postfix[k++] = pop(stack);
            }
            pop(stack); // Discard '('
        } else if (isOperator(infix[i])) {
            while (stack->top != -1 && precedence(stack->array[stack->top]) >= precedence(infix[i])) {
                postfix[k++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (stack->top != -1) {
        postfix[k++] = pop(stack);
    }

    postfix[k] = '\0';
}

// Function to generate three-address code from postfix expression
void generateThreeAddressCode(char* expr) {
    char t = 't'; // Temporary variable name

    struct Stack* stack = createStack(strlen(expr));

    for (int i = 0; expr[i]; i++) {
        if (!isOperator(expr[i])) {
            push(stack, expr[i]);
        } else {
            char op2 = pop(stack);
            char op1 = pop(stack);
            printf("%c = %c %c %c\n", t++, op1, expr[i], op2);
            push(stack, t - 1);
        }
    }
}

int main() {
    char infix[MAX_EXPR_SIZE];
    char postfix[MAX_EXPR_SIZE];

    printf("Enter the infix expression: ");
    fgets(infix, MAX_EXPR_SIZE, stdin);

    // Remove the newline character from input
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Three-address code for the given expression:\n");
    generateThreeAddressCode(postfix);
    return 0;
}
