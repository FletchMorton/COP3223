//Fletcher Morton
//Project 3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int id, courses;
    int cred1 = 0;
    int cred2 = 0;
    int cred3 = 0;
    int crn1 = 0;
    int crn2 = 0;
    int crn3 = 0;
    char prefix1[8];
    char prefix2[8];
    char prefix3[8];
    char retry;


    do {
        retry = '~';
        printf("Enter the student's ID number: ");
        scanf("%d", &id);


        printf("\nEnter how many courses taken (up to 3): ");
        scanf("%d", &courses);
        if(courses > 3 || courses < 0) {
            printf("\nSorry, we cant process this time-invalid number of courses.\n\n\tWould you like to print another invoice? Y=yes, N=No\n\t\t");
            scanf(" %c", &retry);

            while(retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n') {
                printf("\n\nInvalid entry. (You selection must be either Y or N)\n\t\t");
                scanf(" %c", &retry);
            }

            if(retry == 'Y' || retry == 'y') {
                printf("\n\n\n");
                continue;
            } else {
                printf("Goodbye!\n\n");
                return 0;
            }

        }

        if(courses == 0) {
            printf("\nThank you!");
        } else if(courses == 1) {
            printf("\nEnter course number: ");
            scanf("%d", &crn1);
        } else if(courses == 2) {
            printf("\nEnter the 2 course numbers: ");
            scanf("%d %d", &crn1, &crn2);
        } else if(courses == 3) {
            printf("\nEnter the 3 course numbers: ");
            scanf("%d %d %d", &crn1, &crn2, &crn3);
        }

        switch (crn1) {
            case 4587:
                cred1 = 4;
                strcpy(prefix1, "MAT 236");
                break;

            case 4599:
                cred1 = 3;
                strcpy(prefix1, "COP 220");
                break;

            case 8997:
                cred1 = 1;
                strcpy(prefix1, "GOL 124");
                break;

            case 9696:
                cred1 = 5;
                strcpy(prefix1, "COP 100");
                break;

            case 4580:
                cred1 = 3;
                strcpy(prefix1, "MAT 230");
                break;

            case 4581:
                cred1 = 4;
                strcpy(prefix1, "MAT 231");
                break;

            case 4582:
                cred1 = 2;
                strcpy(prefix1, "MAT 232");
                break;

            case 4583:
                cred1 = 2;
                strcpy(prefix1, "MAT 233");
                break;

            case 3587:
                cred1 = 4;
                strcpy(prefix1, "MAT 256");
                break;

            case 4519:
                cred1 = 3;
                strcpy(prefix1, "COP 420");
                break;

            case 6997:
                cred1 = 1;
                strcpy(prefix1, "GOL 127");
                break;

            case 9494:
                cred1 = 3;
                strcpy(prefix1, "COP 101");
                break;

            case 0: break;

            default:
                retry = '~';
                printf("\nSorry invalid crn(s).\n\n\tWould you like to print another invoice? Y=yes, N=No\n\t\t");
                scanf(" %c", &retry);

                while(retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n') {
                    printf("\n\n\tInvalid entry. (You selection must be either Y or N)\n\t\t");
                    scanf(" %c", &retry);
                }

                if(retry == 'Y' || retry == 'y') {
                    printf("\n\n\n");
                    continue;
                } else {
                    printf("Goodbye!\n\n");
                    return 0;
                }
        }


        switch (crn2) {
            case 4587:
                cred2 = 4;
                strcpy(prefix2, "MAT 236");
                break;

            case 4599:
                cred2 = 3;
                strcpy(prefix2, "COP 220");
                break;

            case 8997:
                cred2 = 1;
                strcpy(prefix2, "GOL 124");
                break;

            case 9696:
                cred2 = 5;
                strcpy(prefix2, "COP 100");
                break;

            case 4580:
                cred2 = 3;
                strcpy(prefix2, "MAT 230");
                break;

            case 4581:
                cred2 = 4;
                strcpy(prefix2, "MAT 231");
                break;

            case 4582:
                cred2 = 2;
                strcpy(prefix2, "MAT 232");
                break;

            case 4583:
                cred2 = 2;
                strcpy(prefix2, "MAT 233");
                break;

            case 3587:
                cred2 = 4;
                strcpy(prefix2, "MAT 256");
                break;

            case 4519:
                cred2 = 3;
                strcpy(prefix2, "COP 420");
                break;

            case 6997:
                cred2 = 1;
                strcpy(prefix2, "GOL 127");
                break;

            case 9494:
                cred2 = 3;
                strcpy(prefix2, "COP 101");
                break;

            case 0: break;

            default:
                retry = '~';
                printf("\nSorry invalid crn(s).\n\n\tWould you like to print another invoice? Y=yes, N=No\n\t\t");
                scanf(" %c", &retry);

                while(retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n') {
                    printf("\n\n\tInvalid entry. (You selection must be either Y or N)\n\t\t");
                    scanf(" %c", &retry);
                }

                if(retry == 'Y' || retry == 'y') {
                    printf("\n\n\n");
                    continue;
                } else {
                    printf("Goodbye!\n\n");
                    return 0;
                }
        }


        switch (crn3) {
            case 4587:
                cred3 = 4;
                strcpy(prefix3, "MAT 236");
                break;

            case 4599:
                cred3 = 3;
                strcpy(prefix3, "COP 220");
                break;

            case 8997:
                cred3 = 1;
                strcpy(prefix3, "GOL 124");
                break;

            case 9696:
                cred3 = 5;
                strcpy(prefix3, "COP 100");
                break;

            case 4580:
                cred3 = 3;
                strcpy(prefix3, "MAT 230");
                break;

            case 4581:
                cred3 = 4;
                strcpy(prefix3, "MAT 231");
                break;

            case 4582:
                cred3 = 2;
                strcpy(prefix3, "MAT 232");
                break;

            case 4583:
                cred3 = 2;
                strcpy(prefix3, "MAT 233");
                break;

            case 3587:
                cred3 = 4;
                strcpy(prefix3, "MAT 256");
                break;

            case 4519:
                cred3 = 3;
                strcpy(prefix3, "COP 420");
                break;

            case 6997:
                cred3 = 1;
                strcpy(prefix3, "GOL 127");
                break;

            case 9494:
                cred3 = 3;
                strcpy(prefix3, "COP 101");
                break;

            case 0: break;

            default:
                retry = '~';
                printf("\nSorry invalid crn(s).\n\n\tWould you like to print another invoice? Y=yes, N=No\n\t\t");
                scanf(" %c", &retry);

                while(retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n') {
                    printf("\n\n\tInvalid entry. (You selection must be either Y or N)\n\t\t");
                    scanf(" %c", &retry);
                }

                if(retry == 'Y' || retry == 'y') {
                    printf("\n\n\n");
                    continue;
                } else {
                    printf("Goodbye!\n\n");
                    return 0;
                }
        }


        if ( (cred1 + cred2 + cred3) > 7) {
            printf("\n\nSorry we cant process more than 7 credit hours!\n\n\tWould you like to print another invoice? Y=yes, N=No\n\t\t");
            scanf(" %c", &retry);

            while(retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n') {
                    printf("\n\n\tInvalid entry. (You selection must be either Y or N)\n\t\t");
                    scanf(" %c", &retry);
                }

                if(retry == 'Y' || retry == 'y') {
                    printf("\n\n\n");
                    continue;
                } else {
                    printf("Goodbye!\n\n");
                    return 0;
                }
        }


        float total = ((float)cred1 * 120.25) + ((float)cred2 * 120.25) + (float)cred3 * 120.25 + 35;

        printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t*************************\n");
        printf("\n\t\tFee Invoice Prepared for Student V%d\n\n\t\t1 Credit Hour = $120.25\n\n\t\tCRN\tCR_PREFIX\tCR_HOURS", id);

        if (courses > 0) {
            printf("\n\t\t%-10d%-20s%-8d$ %.2f", crn1, prefix1, cred1, ( (float)cred1 * 120.25 ));

            if (courses >= 2 && crn2 != 0) {
                printf("\n\t\t%-10d%-20s%-8d$ %.2f", crn2, prefix2, cred2, ( (float)cred2 * 120.25 ));

                if (courses == 3 && crn3 != 0) {
                printf("\n\t\t%-10d%-20s%-8d$ %.2f", crn3, prefix3, cred3, ( (float)cred3 * 120.25 ));

                }
            }
        }

        printf("\n\n\t\t\t\t    Health & ID fees  $ 35.00\n\n\t\t--------------------------------------\n");
        printf("\t\t\t\t    Total Payments    $ %.2f\n\n\n", total);




        printf("Would you like to print another invoice? Y=yes, N=No\n\t\t");
        scanf(" %c", &retry);

        while(retry != 'Y' && retry != 'y' && retry != 'N' && retry != 'n') {
                    printf("\n\n\tInvalid entry. (You selection must be either Y or N)\n\t\t");
                    scanf(" %c", &retry);
                }

                if(retry == 'Y' || retry == 'y') {
                    printf("\n\n\n");
                    continue;
                } else {
                    printf("Goodbye!\n\n");
                    return 0;
                }

        printf("\n");


    } while (retry == 'Y' || retry == 'y');

    return 0;
}
