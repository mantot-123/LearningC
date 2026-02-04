// A BETTER VERSION OF THE SHOPPING LIST PROGRAM, THIS TIME USERS CAN ENTER AS MANY ITEMS AS THEY NEED
// INCLUDES DYNAMIC ARRAY AND INPUT SIZING
// ALSO FEATURES PERSISTENT STORAGE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEM_NAME_LENGTH 100 // temporary thing, i'll make sure to include dynamic sizing at some point

typedef struct {
    int charCount;
    char* name;
} Item;

typedef struct {
    int count;
    int capacity;
    char** items;
} ShoppingList;

// adds new item to the shopping list 
ShoppingList* addToList(ShoppingList* list, char* newItem) {
    int limit = (*list).capacity / sizeof(char*);
    // check if the shopping list is about to get full
    if((*list).count >= limit) {
        (*list).capacity = (*list).capacity*2;
        char** newItems = realloc((*list).items, (*list).capacity);
        if((*list).items == NULL) {
            free(newItem);
            printf("Error occured while adding new item %s: Failed to allocate new memory for the shopping list.\n", newItem);
            return NULL;
        }
        (*list).items = newItems;
    }

    (*list).items[(*list).count] = newItem;
    (*list).count++;
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

// saves the shopping list array to a data file
int exportListToFile(ShoppingList* listObj) {
    FILE* shoppingFile = fopen("shoppinglist.dat", "w+");

    if(shoppingFile == NULL) {
        printf("Failed to open shopping list file (shoppinglist.dat)\n");
        return 1;
    }

    // use the arrow operator (->) instead of the dot (.) if you want to dereference the struct and access its members
    fwrite(&listObj->count, sizeof(ShoppingList), 1, shoppingFile);
    fwrite(&listObj->capacity, sizeof(ShoppingList), 1, shoppingFile);

    for(int i=0; i<listObj->count; i++) {
        // sizeof char = 1, so on the second parameter we pass 1
        fwrite(listObj->items[i], 1, strlen(listObj->items[i]), shoppingFile);
    }

    fclose(shoppingFile);
    return 0;
}

ShoppingList* readListFromFile() {
    FILE* shoppingFile = fopen("shoppinglist.dat", "r+");

    if(shoppingFile == NULL) {
        printf("Failed to open shopping list file (shoppinglist.dat)\n");
        return NULL;
    }

    ShoppingList* listObj = malloc(sizeof(ShoppingList));

    // checks if the data file is empty, then it loads empty shopping list data

    // load the capacity and item count data
    size_t readCount = fread(&listObj->count, sizeof(int), 1, shoppingFile);
    size_t readCapacity = fread(&listObj->capacity, sizeof(int), 1, shoppingFile);

    // check if the capacity and item counts have been loaded correctly, if not, allocate a new list entirely
    if(readCount != 1 || readCapacity != 1) {
        int count = 0;
        int capacity = 8*sizeof(char*);
        char** list = malloc(capacity);
        listObj->count = count;
        listObj->capacity = capacity;
        listObj->items = list;
        return listObj;
    }

    // read each individual shopping item name from the list
    char** list = malloc(listObj->capacity);
    for(int i=0; i<listObj->count; i++) {
        fread(list+i, 1, MAX_ITEM_NAME_LENGTH, shoppingFile);
    }

    listObj->items = list;

    return listObj;
}

int main() {
    // set initial shopping item count and list capacity
    // can be changed later when adding new items
    ShoppingList* shopListObj = readListFromFile();
    while(1) {
        char* item = promptUserItem();
        if(item != NULL) {
            addToList(shopListObj, item);
            
            if(shopListObj->items  == NULL) {
                continue;
            }

            printf("%d", exportListToFile(shopListObj));

            // print the shopping list
            printf("Your current shopping list:\n");
            for(int i=0; i<shopListObj->count; i++) {
                printf("%d.) %s\n", (i+1), shopListObj->items[i]);
            }
        }
        // free(item); // note: if you allocate memory and free it, there is a chance that the next promptUserItem call can still use the same address as before
        // actually nvm that last line i was stupid to free the input item from memory, apparently that might have caused the shopping array to print out the corrupted data after freeing
    }
    free(&shopListObj);
    return 0;
}