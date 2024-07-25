#include <stdio.h>
#include <ctype.h>
#include "stack_Array.h"


void Display(stackEntry e) {
    printf("Element is:%d\n",e);
}

int is_Digit(char c) {
    return isdigit(c);
}

int precedent(char op1, char op2) {
    // Define the precedence of operators
    int prec1, prec2;

    switch (op1) {
        case '+':
        case '-':
            prec1 = 1;
        break;
        case '*':
        case '/':
            prec1 = 2;
        break;
        case '^':
            prec1 = 3;
        break;
        default:
            prec1 = 0;
    }

    switch (op2) {
        case '+':
        case '-':
            prec2 = 1;
        break;
        case '*':
        case '/':
            prec2 = 2;
        break;
        case '^':
            prec2 = 3;
        break;
        default:
            prec2 = 0;
    }

    return prec1 >= prec2;
}

// Function to convert infix to postfix
void IN_to_POST(char infix[], char postfix[]) {
    char c, op;
    int i, j;
    stack s;
    createStack(&s); // Assume max capacity of 100 for simplicity

    for (i = 0, j = 0; (c = infix[i]) != '\0'; i++) {
        if (is_Digit(c)) {
            postfix[j++] = c;
        } else {
            if (!is_Empty(&s)) {
                stackTop(&op, &s);
                while (!is_Empty(&s) && precedent(op, c)) {
                    pop(&op, &s);
                    postfix[j++] = op;
                    if (!is_Empty(&s)) {
                        stackTop(&op, &s);
                    }
                }
            }
            push(c, &s);
        }
    }

    while (!is_Empty(&s)) {
        pop(&op, &s);
        postfix[j++] = op;
    }
    postfix[j] = '\0';
}

int main() {
    char infix[] = "3+5*2";
    char postfix[100];

    IN_to_POST(infix, postfix);
    printf("Postfix: %s\n", postfix);

    return 0;
}
