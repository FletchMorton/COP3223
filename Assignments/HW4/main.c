// Fletcher Morton
// HW 4
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char optionChar;
    int number;
    int domain;
    int primeFlag;
    char retry;


    do { // the entire program exists within a do while loop, so the program executes once, and then may repeat if the user wishes
        retry = 'x'; // resetting value of the retry character to an arbitrary value
        printf("Chose from the following options:\nA or a: Display divisors of a natural number\nB or b: Display multiplication table for a natural number\nQ or q to exit\n\n");
        printf("\n\tYour choice: ");
        scanf(" %c", &optionChar);

        switch (optionChar) {

            // Case A
            case 'a': ; // Falls through to A
            case 'A':

                printf("\n\tEnter your number: ");
                scanf("%d", &number);

                if (number < 0) { // Testing if user inputs a natural number
                    printf("\n\t%d is not a natural number...", number);

                } else {
                    printf("\n\tThe divisors of %d are: ", number);

                    for (int i = number; i >= 1; i--) { // Decrementing for loop. Divides user number by i and sees if the remainder is 0. If so, current i iteration is a divisor of number
                        if ( (number%i) == 0 ) {
                                if (i == number) { // tests for initial iteration of for loop and changes output for formatting's sake
                                    printf("%d", number/i);
                                    ++primeFlag;
                                    continue;
                                } else if (i == 1) { // tests for final iteration of for loop and changes output for formatting's sake
                                    printf(" and %d", number/i);
                                    ++primeFlag;
                                    continue;
                                }
                            printf(", %d", number/i);
                            ++primeFlag;
                        }
                    }

                    if (primeFlag == 2 && (number%1) == 0 && (number%number) == 0) { // primeFlag was incremented in each iteration of for loop. This is to test for prime numbers
                        printf(" (%d is a prime number)", number);
                    }
                }

                printf("\n\n");

            break;


            // Case B
            case 'b': ; // Falls through to B
            case 'B':
                printf("\n\tEnter your number: ");
                scanf("%d", &number);

                if (number < 0) {
                    printf("\n\t%d is not a natural number...", number);
                } else {
                    printf("\n\tEnter the size of the multiplication table (1,2,...): ");
                    scanf("%d", &domain);

                    for (int i = 1; i <= domain; i++) { // incrementing for loop that multiplies the user entered number by the current iteration's i value to make a multiplication table
                        printf("\n\t%d x %d = %d", number, i, number*i);
                    }

                }

                printf("\n\n");

            break;


            // Case Q
            case 'q': ; // Falls through to Q
            case 'Q':
                printf("\n\tBye!\n\n");
                return 0;
            break;

            // Default
            default:
                printf("\n\tInvalid option.\n\n");
                return 0;
        }

        while (retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n') { // while loop that repeats input option if user is entering an invalid character
            printf("Would you like to try again? Y/N\n");
            printf("Your choice: ");
            scanf(" %c", &retry);
            printf("\n");
        }

        printf("\n");

    } while (retry == 'Y' || retry == 'y'); // loop the entire program if the user wants to play around some more

    return 0;
}
