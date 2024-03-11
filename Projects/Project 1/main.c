//Fletcher Morton
//Project 1
#include <stdio.h>

int main()
{
    int id;
    int crn1, crn2;
    int cred1, cred2;

    printf("Enter the student's four digit ID number:  ");
    scanf("%d", &id);
    printf("\nEnter CRN/credit hours for the FIRST course (like 5665/3): ");
    scanf("%d/%d", &crn1, &cred1);
    printf("\nEnter CRN/credit hours for the SECOND course (like 5665/3): ");
    scanf("%d/%d", &crn2, &cred2);

    float total = ((float)cred1 * 120.25) + ((float)cred2 * 120.25) + 35;

    printf("\n\n\n            VALENCE COMMUNITY COLLEGE\n            ORLANDO FL 10101\n            *************************\n");
    printf("\n            Fee Invoice Prepared for Student V%d\n\n            1 Credit Hour = $120.25\n", id);
    printf("\n            CRN     CREDIT HOURS\n            %-8d%-18d$ %.2f", crn1, cred1, ( (float)cred1 * 120.25 ));
    printf("\n            %-8d%-18d$ %.2f", crn2, cred2, ( (float)cred2 * 120.25 ));
    printf("\n\n                    Health & ID fees  $  35.00\n\n            --------------------------------------\n");
    printf("                    Total Payments    $ %.2f\n\n\n", total);


    return 0;
}
