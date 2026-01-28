#include<stdio.h>

int main() {
    int num1 = 0;
    int num2 = 0;
    int sum = 0;

    printf("Enter your first number:\n");

    // EXAMPLE 1:
    // "&" - address operator - passes the physical address of num1 and num2
    scanf("%d", &num1);
    printf("Enter your second number:\n");
    scanf("%d", &num2);

    // EXAMPLE 2:
    // printf("Enter 2 numbers:\n");
    // // expect the user to enter 2 numbers in a particular string format 
    // // (e.g. "%d hello %d" expects the user to enter something like "123 hello 10")
    // scanf("%d %d", &num1, &num2); 

    sum = num1 + num2;

    printf("%d + %d = %d", num1, num2, sum);
    return 0;
}