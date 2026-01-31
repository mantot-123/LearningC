#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    int capacity = sizeof(char);
    int count = 0;
    char* message = malloc(capacity);

    if(message == NULL) {
        printf("Initial memory allocation failed. Exiting the program...\n");
        return -1;
    }
    
    char c;
    printf("Enter a message:\n");
    while((c = getc(stdin)) != '\n'  && c != EOF && c != '\0') {
        if(count == capacity-1) {
            capacity = capacity*2;
            char* newMsg = realloc(message, capacity); // note: it automatically already frees the old pointer
            if(newMsg == NULL) {
                free(message);
                printf("Memory reallocation failed. Exiting the program...\n");
                return -1;
            }
            message = newMsg;
        }

        *(message+count) = c;
        count++;
    }

    *(message+count) = '\0';

    printf("You typed: \n%s\n", message);
    printf("Number of characters in the message: %i\n", count);
    printf("Capacity in memory: %i\n", capacity);

    free(message);

    return 0;
}