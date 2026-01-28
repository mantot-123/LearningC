#include<stdio.h>

#define MAX_STR_SIZE 1000

int main() {
    FILE* fpt;
    char fileContent[MAX_STR_SIZE];
    fpt = fopen("testfile1.txt", "r+");

    printf("Points to address: %x\n", fpt);

    if(fpt == NULL) {
        printf("The file could not be opened. It might not exist?");
    } else {
        printf("The file is successfully opened.\n");
        fgets(fileContent, MAX_STR_SIZE, fpt);
        printf("%s\n", fileContent);
        fclose(fpt);
        printf("File successfully closed.\n");
    }
    return 0;
}