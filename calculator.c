#include <stdio.h>
#include <math.h>
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






int main()
{
    int a,b;
    char op;
    double result;
    scanf("%d %c %d",&a,&op,&b);
    switch(op)
    {
        case '+':
            result = add(a,b);
            break;
        case '-':
            result = subtract(a,b);
            break;
        case '*':
            result = multiply(a,b);
            break;
        case '/':
            result = divide(a,b);
            break;
        case '^':
            result = power(a,b);
            break;
        case 'r':
            result = nthRoot(a,b);
            break;
    }
    printf("%lf",result);
    return 0;
}