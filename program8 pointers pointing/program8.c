#include <stdio.h>

int main() {
    // example 1
    // note: pointer size in 64-bit system: 8 bytes, so each element occupies 8 bytes of space
    // char *names[6];
    // names[0] = "Emman";
    // names[1] = "Damian";
    // names[2] = "Lewis";
    // names[3] = "Jacky";
    // names[4] = "JoJo";
    // names[5] = "Chris";

    // int length = sizeof(names) / sizeof(names[0]);
    // printf("Size of array of pointers (char*) (in bytes): %d\n", sizeof(names));
    // printf("Size of pointer (in bytes): %d\n", sizeof(names[0]));
    // printf("Number of elements in array: %d\n", length);
    // printf("Names:\n");
    // for(int i=0;i<length;i++) {
    //     printf("%s\n", names[i]);
    // }

    // example 2
    // char *strs[] = {
    //     "Hello",
    //     "World",
    // };

    // strs[0][0] = 'X'; // BIG NO NO -> trying to modify a pointer to a constant string literal, unexpected behaviour
    // it doesn't work because string literals work a bit differently from character arrays 
    // string literals (the version of the string that looks in the source code)
    // are stored in the read-only part of memory, so you can't modify its value directly
    // but you can do it with arrays because it stores the string literal in the read-only part
    // and takes the characters and writes it to a char array in the writable part of memory

    // example 3
    int num1 = 10;
    int num2 = 20;

    int *addr1 = &num1;
    int *addr2 = &num2;

    printf("Before:\n");
    printf("Value of num1: %d\n", num1);
    printf("Value of num2: %d\n", num2);

    *addr1 = *addr1 + 1;
    *addr2 = *addr2 + 2;

    printf("After:\n");
    printf("Value of num1: %d\n", num1);
    printf("Value of num2: %d\n", num2);

    // example 4
    int array[4] = {1,2,3,4};
    printf("Array:\n");
    printf("%d\n", &array[0]);
    printf("%d\n", array);
    printf("Next element: %d\n", *(array+1));
    return 0;
}