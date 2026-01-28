#include<stdio.h>

#define LIST_SIZE 10
#define CHAR_SIZE 30

int main() {
    int counter = 0;

    char shoppingList[LIST_SIZE][CHAR_SIZE];

    while(counter < LIST_SIZE) {
        char item[CHAR_SIZE];
        printf("Enter a shopping item: ");
        // scanf("%s", &item);
        fgets(item, sizeof(item), stdin);

        if(item[0] <= '\0' || item[0] == '\n') {
            printf("Please enter an item\n");
            continue;
        }

        printf("Successfully added item: %s", item);
        // first example doesn't work
        // C does not allow direct array-to-array assignments (and strings are basically arrays of characters)
        // shoppingList[counter] = item;
        strcpy(shoppingList[counter], item); // -> instead, copy the string to the element. this works
        counter++;
    }

    printf("Your full shopping list is:\n");

    for(int i=0; i < sizeof(shoppingList) / CHAR_SIZE; i++) {
        printf("%d.) %s", (i+1), shoppingList[i]);
    }
    return 0;
}