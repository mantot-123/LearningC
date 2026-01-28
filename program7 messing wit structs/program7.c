#include<stdio.h>

struct Flashcard {
    char* title;
    char* content;
};

struct Flashcard newFlashcard(struct Flashcard list[10], char* title, char* content) {
    struct Flashcard fcard = {title, content};
    return fcard;
}

int main() {
    struct Flashcard fcard = {"Hello world!!!", "The quick brown fox jumps over the lazy dog"};
    printf("Title: %s\n", fcard.title);
    printf("Content: %s\n", fcard.content);

    fcard.title = "Title changed";
    printf("Title: %s\n", fcard.title);
    printf("Content: %s\n", fcard.content);
    return 0;
}