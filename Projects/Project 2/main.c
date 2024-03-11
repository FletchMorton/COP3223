//Fletcher Morton
//Project 2
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int id, courses;
    int cred1 = 0;
    int cred2 = 0;
    int crn1 = 0;
    int crn2 = 0;


    printf("Enter the student's ID number: ");
    scanf("%d", &id);

    printf("\nEnter hour many courses taken (up to 2): ");
    scanf("%d", &courses);
    if (courses > 2 || courses < 0){
       printf("\nSorry, we cant process this time-invalid number of courses.\n\n\n\t\t\tTry again. Goodbye!\n\n\n\n");
       return 0;
    } else if (courses == 0) {
        printf("\nThank you!");

    } else if (courses == 1) {
        printf("\nEnter course number: ");
        scanf("%d", &crn1);
    } else if (courses == 2) {
        printf("\nEnter the 2 course numbers separated by - :(like 2356-8954): ");
        scanf("%d-%d", &crn1, &crn2);
    }

    switch (crn1) {
        case 4587: cred1 = 4;
        break;
        case 4599: cred1 = 3;
        break;
        case 8997: cred1 = 1;
        break;
        case 9696: cred1 = 3;
        break;
        case 0: break;
        default:
            printf("\n\nSorry, invalid entry.\n\n");
            return 0;

    }

    switch (crn2) {
        case 4587: cred2 = 4;
        break;
        case 4599: cred2 = 3;
        break;
        case 8997: cred2 = 1;
        break;
        case 9696: cred2 = 3;
        break;
        case 0: break;
        default:
            printf("\n\nSorry, invalid entry.\n\n");
            return 0;

    }

    float total = ((float)cred1 * 120.25) + ((float)cred2 * 120.25) + 35;

    printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t*************************\n");
    printf("\n\t\tFee Invoice Prepared for Student V%d\n\n\t\t1 Credit Hour = $120.25\n", id);

    if (courses > 0) {
        printf("\t\tCRN\tCREDIT HOURS\n\t\t%-8d%-18d$ %.2f", crn1, cred1, ( (float)cred1 * 120.25 ));

        if (courses == 2 && crn2 != 0) {
            printf("\n\t\t%-8d%-18d$ %.2f", crn2, cred2, ( (float)cred2 * 120.25 ));

        }
    }

    printf("\n\n\t\t\tHealth & ID fees  $ 35.00\n\n\t\t--------------------------------------\n");
    printf("\t\t\tTotal Payments\t  $ %.2f\n\n\n", total);




    return 0;
}
