#include <stdio.h>
#include <conio.h>

int main() {
    int option;
    float value1, value2, result;

    do {
        printf("\n==== Basic Calculator ====\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &option);

        if(option == 5) {
            printf("Exiting Calculator\n");
            break;
        }

        if(option >= 1 && option <= 4) {
            printf("Enter value 1: ");
            scanf("%f", &value1);
            printf("Enter value 2: ");
            scanf("%f", &value2);
        }

        switch(option) {
            case 1:
                result = value1 + value2;
                printf("Result = %.2f\n", result);
                break;

            case 2:
                result = value1 - value2;
                printf("Result = %.2f\n", result);
                break;

            case 3:
                result = value1 * value2;
                printf("Result = %.2f\n", result);
                break;

            case 4:
                if(value2 == 0) {
                    printf("Result: Error - Division by zero not possible\n");
                } else {
                    result = value1 / value2;
                    printf("Result = %.2f\n", result);
                }
                break;

            default:
                printf("Result: Invalid Choice.\n");
        }
        printf("---------------------------------\n");
        
    } while(option != 5);
    
    getch();
    return 0;
}
