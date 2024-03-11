// Fletcher Morton
// Project 4
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int setCourses(int courses, int *, int *, int *);  // Returns 1 if there is a valid number of courses, 0 if not. Lets users input values for the CRN variables
void appRelaunch(char *);                          // Prompts the user to restart the program. Called when user enters an invalid input or reaches the end of the application
int checkCrn(int *);                               // Returns 1 if CRN is valid, returns 0 if not
int getCreditHours(int *);                         // Returns the credit hours of CRN
char* printPrefix(int *);                          // Prints the prefix of the CRN
void printInvoice(int id, int *, int *, int *);    // Prints the fee invoice

int main()
{
    int id;
    int courses;
    int *pCrn1 = malloc(sizeof(int)), *pCrn2 = malloc(sizeof(int)), *pCrn3 = malloc(sizeof(int));
    char *pOption = malloc(sizeof(char));

    do {

        printf("Enter the student's ID: ");
        scanf("%d", &id);

        printf("\nEnter amount of courses (Up to 3): ");
        scanf("%d", &courses);

        if (setCourses(courses, pCrn1, pCrn2, pCrn3) == 0) {
            appRelaunch(pOption);
            continue;
        } else if (checkCrn(pCrn1)*checkCrn(pCrn2)*checkCrn(pCrn3) == 0) {
            printf("\n\tInvalid CRN(s)");
            appRelaunch(pOption);
            continue;
        } else if (getCreditHours(pCrn1)+getCreditHours(pCrn2)+getCreditHours(pCrn3) > 7){
            printf("\n\tSorry we cant process more than 7 credit hours!");
            appRelaunch(pOption);
            continue;
        }

        printInvoice(id, pCrn1, pCrn2, pCrn3);
        appRelaunch(pOption);

    } while (toupper(*pOption) == 'Y');

    free(pCrn1);
    free(pCrn2);
    free(pCrn3);
    return 0;
}


int setCourses(int courses, int *pCrn1, int *pCrn2, int *pCrn3)
{
    while(courses > 3 || courses < 0) {
        printf("\n\tSorry, we cant process this time-invalid number of courses.");
        printf("\n\n\t\tEnter amount of courses (Up to 3): ");
        scanf("%d", &courses);
    }

    switch(courses) {
        case 0:
            *pCrn1 = 0, *pCrn2 = 0, *pCrn3 = 0;
            printf("\nThank you.");
            break;

        case 1:
            *pCrn2 = 0, *pCrn3 = 0;
            printf("\nEnter your course number: ");
            scanf("%d", &*pCrn1);
            break;

        case 2:
            *pCrn3 = 0;
            printf("\nEnter your %d course numbers: ", courses);
            scanf("%d %d", &*pCrn1, &*pCrn2);
            break;

        case 3:
            printf("\nEnter your %d course numbers: ", courses);
            scanf("%d %d %d", &*pCrn1, &*pCrn2, &*pCrn3);
            break;

        default: return 0;
    }

    return 1;

}


void appRelaunch(char *p)
{
    printf("\n\nWould you like to print another invoice? [Y/N]\n\t\t");
    scanf(" %c", &*p);

    while (toupper(*p) != 'Y' && toupper(*p) != 'N') {
        printf("\nInvalid entry. (Your selection must be either Y or N)\n\t\t");
        scanf(" %c", &*p);
    }

    if (toupper(*p) == 'N') {
            printf ("\nGoodbye.\n\n");
            exit(0);
    }
    printf("\n\n\n");
}


int checkCrn(int *crn)
{
    switch(*crn) {
        case 4587:
        case 4599:
        case 8997:
        case 9696:
        case 4580:
        case 4581:
        case 4582:
        case 4583:
        case 3587:
        case 4519:
        case 6997:
        case 9494:
        case 0:
            return 1;
        default:
            return 0;
    }
}

int getCreditHours(int *crn)
{
    switch(*crn) {
        case 4587:
            return 4;
        case 4599:
            return 3;
        case 8997:
            return 1;
        case 9696:
            return 5;
        case 4580:
            return 3;
        case 4581:
            return 4;
        case 4582:
            return 2;
        case 4583:
            return 2;
        case 3587:
            return 4;
        case 4519:
            return 3;
        case 6997:
            return 1;
        case 9494:
            return 3;
        default:
            return 0;
    }
}


char* printPrefix(int *crn)
{
    switch(*crn) {
        case 4587:
            return "MAT 236";
        case 4599:
            return "COP 220";
        case 8997:
            return "GOL 124";
        case 9696:
            return "COP 100";
        case 4580:
            return "MAT 230";
        case 4581:
            return "MAT 231";
        case 4582:
            return "MAT 232";
        case 4583:
            return "MAT 233";
        case 3587:
            return "MAT 256";
        case 4519:
            return "COP 420";
        case 6997:
            return "GOL 127";
        case 9494:
            return "COP 101";
        default:
            return "NULL";
    }
}


void printInvoice(int id, int *pCrn1, int *pCrn2, int *pCrn3)
{
    float total = ((float)getCreditHours(pCrn1) * 120.25) + ((float)getCreditHours(pCrn2) * 120.25) + (float)getCreditHours(pCrn3) * 120.25 + 35;

    printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t*************************\n");
    printf("\n\t\tFee Invoice Prepared for Student V%d\n\n\t\t1 Credit Hour = $120.25\n\n\t\tCRN\tCR_PREFIX\tCR_HOURS", id);

    if (getCreditHours(pCrn1) != 0) {
        printf("\n\t\t%-10d%-20s%-8d$ %.2f", *pCrn1, printPrefix(pCrn1), getCreditHours(pCrn1), ( (float)getCreditHours(pCrn1) * 120.25 ));

        if (getCreditHours(pCrn2) != 0) {
            printf("\n\t\t%-10d%-20s%-8d$ %.2f", *pCrn2, printPrefix(pCrn2), getCreditHours(pCrn2), ( (float)getCreditHours(pCrn2) * 120.25 ));

            if (getCreditHours(pCrn3) != 0) {
                printf("\n\t\t%-10d%-20s%-8d$ %.2f", *pCrn3, printPrefix(pCrn3), getCreditHours(pCrn3), ( (float)getCreditHours(pCrn3) * 120.25 ));

            }
        }
    }

    printf("\n\n\t\t\t\t    Health & ID fees  $ 35.00\n\n\t\t--------------------------------------\n");
    printf("\t\t\t\t    Total Payments    $ %.2f\n\n\n", total);

    return;
}
