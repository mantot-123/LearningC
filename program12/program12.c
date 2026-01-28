#include<stdio.h>

int main() {
    printf("Enter something:");
    char c = getc(stdin);

    // printf("%c", c);

    c = getc(stdin);

    printf("%c", c);
    
    return 0;
}