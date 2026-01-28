#include<stdio.h>

#define MAX_STR_SIZE 1000

int main() {
    FILE* fpt;
    char fileContent[MAX_STR_SIZE];
    fpt = fopen("testfile1.txt", "w+");

    printf("Points to address: %x\n", fpt);

    if(fpt == NULL) {
        printf("The file could not be opened. It might not exist?");
    } else {
        printf("The file is successfully opened.\n");
        fputs("Hello world! The file has been accessed using C's built in fopen and fputs functions. HEHEHEHA!\nFrom Emman :D", fpt);
        printf("File successfully written.\n");
        fclose(fpt); // close the file - prevents accidental memory writes as it frees the file from memory
        printf("File successfully closed.\n");
    }
    return 0;
}