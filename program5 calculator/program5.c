#include<stdio.h>

int main() {
    while(1) {
        float num1 = 0.0, num2 = 0.0;
        float result = 0.0;
        char op;

        printf("Enter an operation (+, -, *, /)\n");
        // there is a bug where in the next iteration, the program would skip the scanf() method, so the user can't enter anything
        // this happens because the last character that is ever read in the input stream is a newline character
        // (or "\n") when the user clicks enter
        // to fix this, add a space before %c to prevent the while loop from skipping this scanf function
        // so it ignores the newline character
        scanf(" %c", &op);
        
        printf("Enter the first and second numbers\n");
        scanf("%f %f", &num1, &num2);
        
        switch(op) {
            case '+':
                printf("Addition mode selected\n");
                result = num1 + num2;
                break;
            case '-':
                printf("Subtraction mode selected\n");
                result = num1 - num2;
                break;
            case '*':
                printf("Multiplication mode selected\n");
                result = num1 * num2;
                break;
            case '/':
                printf("Division mode selected\n");
                result = num1 / num2;
                break;
            default:
                printf("Invalid operation. Please select a valid one.\n");
                op = 'A';
                break;
        }

        if(op == 'A') {
            continue;
        }

        printf("The result for the calculation is: %f %c %f = %.2f\n", num1, op, num2, result); 

    }

    return 0;
}