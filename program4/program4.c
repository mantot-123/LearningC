#include <stdio.h>
#include <stdlib.h>

// example 1
// int main() {
//     int count = 0;
//     printf("\nEnter a sentence:\n");

//     // getchar() - connects to input stream (keyboard), gets user input until the user clicks "enter"
//     while (getchar() != '\n') {
//         count++;
//     }

//     printf("\nNumber of characters is %d\n", count);
//     return 0;
// }


// example 2
// int main() {
//     char c;
//     printf("enter a character:");
//     c = getchar();
//     putchar(c); // print a single character. same as printf
//     return 0;
// }


// example 3
// int main() {
//     double x = 2.25, small = 0.0, big = 0.0, a = 0.0;

//     small = floor(x);
//     big = ceil(x);
//     a = abs(x);

//     printf("%f\n", x);
//     printf("%f\n", small);
//     printf("%f\n", big);
//     printf("%f\n", a);

//     printf("%.2f\n", x);
//     printf("%.2f\n", small);
//     printf("%.2f\n", big);
//     printf("%.2f\n", a);
// }


// example 4
int main() {
    int randomNumber = 0;

    // use the computer's current time as a seed for generating random numbers
    // prevents rand from generating the same number each time it runs
    srand(time(NULL));
    
    randomNumber  = rand() % 10; // random number between 1 and 10 (not inclusive)

    printf("%d", randomNumber);
    return 0;
}
