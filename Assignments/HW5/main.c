// Fletcher Morton
// HW5
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pFirst = malloc(sizeof(int));
    int *pSecond = malloc(sizeof(int));
    char *pChoice = malloc(sizeof(char));

    printf("Please enter two integers: ");
    scanf("%d %d", &*pFirst, &*pSecond);

    printf("Now...\n\tA or a: Show the sum\n\tP or p: Show the product\n\tD or d: Show the division of your first number by the second\n\nYour choice: ");
    scanf(" %c", &*pChoice);

    switch(*pChoice) {
        case 'a':
        case 'A':
            printf("\n\n\t%d + %d = %d", *pFirst, *pSecond, ((*pFirst) + (*pSecond)) );
            break;

        case 'p':
        case 'P':
            printf("\n\n\t%d x %d = %d", *pFirst, *pSecond, ((*pFirst) * (*pSecond)) );
            break;

        case 'd':
        case 'D':
            if (*pSecond == 0) {
                printf("\n\n\tERROR: Division by 0 is not possible\n\nGoodbye.\n\n");
                return 0;

            } else if ( ((*pFirst)%(*pSecond)) != 0) {
                printf("\n\n\t%d / %d = %.2f", *pFirst, *pSecond, ((float) (*pFirst) / (float) (*pSecond)) );

            } else {
                printf("\n\n\t%d / %d = %d", *pFirst, *pSecond, ((*pFirst) / (*pSecond)) );
            }

            break;

        default:
            printf("\n\n\tInvalid option.\n\nGoodbye.\n\n");
            return 0;
    }

    printf("\n\nGoodbye.\n\n");

    free(pFirst);
    free(pSecond);

    return 0;
}
