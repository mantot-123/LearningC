// A BETTER VERSION OF THE SHOPPING LIST PROGRAM, THIS TIME USERS CAN ENTER AS MANY ITEMS AS THEY NEED
// INCLUDES DYNAMIC ARRAY AND INPUT SIZING
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char** addToList(char** list, int* count, int* capacity, char* newItem);
char* promptUserItem();
void exportListToDataFile(); // potential feature - add persistent storage?

// adds new item to the shopping list 
char** addToList(char** list, int* count, int* capacity, char* newItem) {
    int limit = (*capacity / sizeof(char*));
    // check if the shopping list is about to get full
    if(*count >= limit) {
        *capacity = (*capacity)*2;
        char** newList = realloc(list, *capacity);
        if(newList == NULL) {
            free(newItem);
            printf("Error occured while adding new item '%s': Failed to allocate new memory for the shopping list.\n", newItem);
            return NULL;
        }
        list = newList;
    }

    *(list+*count) = newItem;
    (*count)++;
    printf("Item successfully added: %s\n", newItem);
    return list;
}


// gets user input - returns a pointer
char* promptUserItem() {
    int count = 0;
    int capacity = sizeof(char);
    char* itemInput = malloc(capacity);

    if(itemInput == NULL) {
        printf("Initial memory allocation for shopping item input failed. Memory might be full? Crashing...\n");
        return NULL;
    }

    char c;
    printf("Enter an item to add to the list: ");
    // get user input from standard io stream (command line), also check if that character is not a newline or an end character (EOF)
    while((c = getc(stdin)) != '\n' && c != EOF && c != '\0') {
        if(count >= capacity-1) {
            capacity = capacity*2;
            char* newItemInput = realloc(itemInput, capacity*2);
            if(newItemInput == NULL) {
                free(itemInput);
                printf("Failed to reallocate memory while getting user input. Memory might be full? Crashing...\n");
                return NULL;
            }
            itemInput = newItemInput;
        }
        
        itemInput[count] = c;
        count++;
    }

    itemInput[count] = '\0'; // add a '\0' to indicate the end of string input
    return itemInput;
}

int main() {
    FILE* shoppingFile;
    // set initial shopping item count and list capacity
    // can be changed later when adding new items
    int count = 0;
    int capacity = 1*sizeof(char*);
    char** list = malloc(capacity);
    while(1) {
        char* item = promptUserItem();
        if(item != NULL) {
            list = addToList(list, &count, &capacity, item);
            if(list == NULL) {
                continue;
            }

            // print the shopping list
            printf("Your current shopping list:\n");
            for(int i=0; i<count; i++) {
                printf("%d.) %s\n", (i+1), list[i]);
            }
        }
        // free(item); // note: if you allocate memory and free it, there is a chance that the next promptUserItem call can still use the same address as before
        // actually nvm that last line i was stupid to free the input item from memory, apparently that might have caused the shopping array to print out the corrupted data after freeing
    }
    free(list);
    return 0;
}