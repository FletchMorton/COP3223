//Fletcher Morton
//HW3
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, z;
    char userChoice;

    printf("Enter three integers in a comma seperated list: ");
    scanf("%d, %d, %d", &x, &y, &z);
    printf("\nYou entered: %d, %d and %d\n\n\n", x, y, z);

    printf("Choose one of the following options:\n\tA - Print the lowest number entered\n\tB - Print the highest number entered\n\tC - Print whether the first number is even or odd\n\tD - Add the first two numbers and divide by the third number");
    printf("\n\nYour selection: ");
    scanf(" %c", &userChoice);

    switch (userChoice) {

        case 'A':
            if(x < y) {

                if(x < z) {
                    printf("\n\n%d\n\n", x);
                } else {
                    printf("\n\n%d\n\n", z);
                }

            } else {

                if(y < z) {
                    printf("\n\n%d\n\n", y);
                } else {
                    printf("\n\n%d\n\n", z);
                }

            }
        break;

        case 'B':
            if(x > y) {

                if(x > z) {
                    printf("\n\n%d\n\n", x);
                } else {
                    printf("\n\n%d\n\n", z);
                }

            } else {

                if(y > z) {
                    printf("\n\n%d\n\n", y);
                } else {
                    printf("\n\n%d\n\n", z);
                }

            }
        break;

        case 'C':
            if( (x%2) == 0 ) {
                printf("\n\n%d is an even number\n\n", x);
            } else {
                printf("\n\n%d is an odd number\n\n", x);
            }
        break;

        case 'D':
            if (z == 0) {

                printf("\n\nERROR: Division by zero\n\n");

            } else {

                if( ((x+y)%z) == 0) {
                   printf("\n\n%d divided by %d is %d\n\n", (x+y), z, ( (x+y)/z ));
                } else {
                    printf("\n\n%d divided by %d is %.2f\n\n", (x+y), z, ( (float)(x+y)/z ));
                }

            }
        break;

        default : printf("\n\nInvalid input\n\n");

    }


    return 0;
}
