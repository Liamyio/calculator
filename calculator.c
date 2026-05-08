#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int power(int a, int b) {
    int result = 1;
    for (int i = 0; i < b; i++) {
        result *= a;
    }
    return result;
}

double nthRoot(int a, int b) {
    return pow(a, 1.0 / b);
}   






typedef enum { VAL, ADD, SUB, MUL, DIV, POW, ROOT, END } TokenType;

typedef struct {
    TokenType type;
    int value;
} Token;

Token getNextToken(const char **p) {
    while (**p == ' ') (*p)++;
    if (**p == '\0' || **p == '\n') return (Token){END, 0};
    if (**p == '+') { (*p)++; return (Token){ADD, 0}; }
    if (**p == '-') { (*p)++; return (Token){SUB, 0}; }
    if (**p == '*') { (*p)++; return (Token){MUL, 0}; }
    if (**p == '/') { (*p)++; return (Token){DIV, 0}; }
    if (**p == '^') { (*p)++; return (Token){POW, 0}; }
    if (**p == 'r') { (*p)++; return (Token){ROOT, 0}; }
    int val = 0;
    while (isdigit(**p)) {
        val = val * 10 + (**p - '0');
        (*p)++;
    }
    return (Token){VAL, val};
}

double applyOp(double a, TokenType op, int b) {
    switch (op) {
        case ADD: return add((int)a, b);
        case SUB: return subtract((int)a, b);
        case MUL: return multiply((int)a, b);
        case DIV: return divide((int)a, b);
        case POW: return power((int)a, b);
        case ROOT: return nthRoot((int)a, b);
        default:  return a;
    }
}

int main() {
    char line[256];
    fgets(line, sizeof(line), stdin);

    const char *p = line;
    Token t = getNextToken(&p);
    if (t.type != VAL) { printf("Invalid input\n"); return 1; }

    double result = t.value;

    while (1) {
        Token op = getNextToken(&p);
        if (op.type == END) break;

        Token next = getNextToken(&p);
        if (next.type != VAL) { printf("Invalid input\n"); return 1; }

        result = applyOp(result, op.type, next.value);
    }

    printf("%g\n", result);
    system("pause");
    return 0;


}