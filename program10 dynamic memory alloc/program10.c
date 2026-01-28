#include<stdio.h>
#include<stdlib.h>

int main() {
    // heap - used in dynamic memory allocation, useful if you have data constantly changing in size
    // stack - only used in fixed size data
    
    int* num;
    int size = 20;
    // sizeof(int) = 4 bytes = 4

    // allocate 20*4 bytes for the data. 1 byte = 8 bits. integers take up to 32 bits = 4 bytes of memory space
    // note: you can still write huge data to a memory block that has a smaller space and access it,
    // but those data can still be overwritten at any point in the program, because we have not allocated the remaining space

    // num = malloc(size*sizeof(int));
    num = calloc(size, sizeof(int)); // another way to allocate memory

    if(num == NULL) {
        printf("Memory allocation failed!!!");
    } else {
        printf("Memory allocation success! The address assigned for 'num' is: %p\n", num);
        *num = 10000;
        printf("The value of %p is: %d\n", num, *num);
    }

    // free the pointer - that way when it's done being used, new data can be allocated to it
    // always do this with systems with limited space
    free(num);

    return 0;
}