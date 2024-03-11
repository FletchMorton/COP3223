#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define STUMAX 5

typedef struct Student
{
    int id;
    char sName[100];
    int sCrn[4];
    char sPrefix[4][8];
    int sCredit[4];

} student;

void callMenu(student sList[], int[], int[], char[][8], int);
void resetProgram(student sList[], int);
void addStudent(student sList[], int[], int[], char [][8]);
void addClass(student sList[], int[], int[], char [][8], int, int);
int populateCourse(student sList[], int[], int[], char [][8], int);
void courseConfig(student sList[], int[], int[], char [][8]);
void configMenu(student sList[], int[], int[], char [][8], int, int);
void searchStudent(student sList[], int[], int[], char [][8]);
void checkCreditHours(student sList[], int[], int[], char [][8], int, int);
void print(student sList[], int);

int main()
{
    student s1, s2, s3, s4, s5;
    student sList[] = {s1, s2, s3, s4, s5};
    int crn[] = {4587, 4599, 8997, 9696, 1232, 9856, 8520, 8977};
    char prefix[][8] = {"MAT 236", "COP 220", "GOL 124", "COP 100", "MAC 531", "STA 100", "TNV 400", "CMP 100"};
    int credit[] = {4, 3, 1, 3, 5, 2, 5, 1};
    int option = 999;
    int refresh = 999;

    resetProgram(sList, refresh);
    callMenu(sList, crn, credit, prefix, option);

    return 0;
}

void resetProgram(student sList[], int refresh)
{

    if(refresh == 999) {

        //Sets all ID to 0 in all students
        for(int i = 0; i < (STUMAX); i++) {
            sList[i].id = 0;

            //Sets all CNRs and credits to 0 in all students
            for(int j = 0; j < 4; j++) {
                sList[i].sCrn[j] = 0;
                sList[i].sCredit[j] = 0;
            }
        }

        printf("====================WELCOME====================\n\n");
        return;
    }

    if(refresh >= 0 || refresh <= 4) {

        //Sets all ID to 0 in current student
        sList[refresh].id = 0;

        //Sets all CNRs and credits to 0 in current students
        for(int j = 0; j < 4; j++) {
            sList[refresh].sCrn[j] = 0;
            sList[refresh].sCredit[j] = 0;
        }

        return;

    }

    return;
}

void callMenu(student sList[], int crn[], int credit[], char prefix[][8], int option)
{

    do {
        option = 999;

        printf("Choose from one of the following options:\n");
        printf("\t1 - Add a new student\n\t2 - View/Add/Delete courses\n\t3 - Search for a student\n\t4 - Print fee invoice\n\t0 - Exit the program\n\n");
        printf("Enter your selection: ");

        scanf("%d", &option);

        switch(option) {
            case 0:
                printf("\n\n====================GOODBYE=====================\n\n");
                exit(0);
                break;
            case 1:
                addStudent(sList, crn, credit, prefix);
                break;
            case 2:
                courseConfig(sList, crn, credit, prefix);
                break;
            case 3:
                searchStudent(sList, crn, credit, prefix);
                break;
            case 4:
                print(sList, 999);
                break;
            default:
                printf("\n\n-----------------------------------------------\n\nThat was not a valid option. ");
                break;
        }

    } while(option != 0);

    return;
}

void addStudent(student sList[], int crn[], int credit[], char prefix[][8])
{
    int id;
    int courses;
    int currentStudent = 999;

    //Find empty student slot to work with
    for(int i = 0; i < STUMAX; i++) {
        if(sList[i].id == 0) {
            currentStudent = i;
            break;
        }
    }

    //Check if attempting to exceed maximum capacity
    if(currentStudent == 999) {
        printf("\n\tMaximum number of students have been entered (5).\n\n-----------------------------------------------\n\n");
        return;
    }

    //Enter ID
    printf("\n\tEnter the student's id: ");
    scanf("%d", &id);

    //Check for invalid ID number
    while(id == 0) {
        printf("\n\t\tInvalid id number. Please re-enter.\n\n");
        printf("\n\n\t\t\tEnter the student's id: ");
        scanf("%d", &id);
    }

    //Check array of students for matching id
    for(int i = 0; i < STUMAX; i++) {
        if(id == sList[i].id) {
            printf("\nThis student has already been entered.\n\n-----------------------------------------------\n\n");
            return;
        }
    }

    sList[currentStudent].id = id;
    fflush(stdin);
    printf("\n\tEnter the student's full name: ");
    gets(sList[currentStudent].sName);

    printf("\n\tHow many courses is %s taking (Up to 4): ", sList[currentStudent].sName);
    scanf("%d", &courses);

    addClass(sList, crn, credit, prefix, currentStudent, courses);

    return;

}

void addClass(student sList[], int crn[], int credit[], char prefix[][8], int currentStudent, int courses)
{
    int currentIndex;

    //Check for invalid course number
    while(courses > 4 || courses < 0) {
        printf("\n\t\tSorry, we cant process this time-invalid number of courses.");
        printf("\n\n\t\t\tEnter amount of courses (Up to 4): ");
        scanf("%d", &courses);
    }

    switch(courses) {
        case 0:
            printf("\nThank you.");
            break;

        case 1:
            printf("\n\tEnter your course number: ");

            for(int i = 0; i < STUMAX; i++) {
                if(sList[currentStudent].sCrn[i] == 0) {
                    scanf("%d", &sList[currentStudent].sCrn[i]);
                    currentIndex = (i+1);
                    break;
                }
            }

            if(populateCourse(sList, crn, credit, prefix, currentStudent) != currentIndex) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                resetProgram(sList, currentStudent);
                return;
            }

            checkCreditHours(sList, crn, credit, prefix, currentStudent, courses);

            break;

        case 2:
            printf("\n\tEnter your %d course numbers: ", courses);

            for(int i = 0; i < STUMAX; i++) {
                if(sList[currentStudent].sCrn[i] == 0) {
                    scanf("%d %d", &sList[currentStudent].sCrn[i], &sList[currentStudent].sCrn[(i+1)]);
                    currentIndex = (i+1);
                    break;
                }
            }

            if(populateCourse(sList, crn, credit, prefix, currentStudent) != (currentIndex+1)) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                resetProgram(sList, currentStudent);
                return;
            }

            checkCreditHours(sList, crn, credit, prefix, currentStudent, courses);

            break;

        case 3:
            printf("\n\tEnter your %d course numbers: ", courses);

            for(int i = 0; i < STUMAX; i++) {
                if(sList[currentStudent].sCrn[i] == 0) {
                    scanf("%d %d %d", &sList[currentStudent].sCrn[i], &sList[currentStudent].sCrn[(i+1)], &sList[currentStudent].sCrn[(i+2)]);
                    currentIndex = (i+1);
                    break;
                }
            }

            if(populateCourse(sList, crn, credit, prefix, currentStudent) != (currentIndex+2)) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                resetProgram(sList, currentStudent);
                return;
            }

            checkCreditHours(sList, crn, credit, prefix, currentStudent, courses);

            break;

        case 4:
            printf("\n\tEnter your %d course numbers: ", courses);

            for(int i = 0; i < STUMAX; i++) {
                if(sList[currentStudent].sCrn[i] == 0) {
                    scanf("%d %d %d %d", &sList[currentStudent].sCrn[i], &sList[currentStudent].sCrn[(i+1)], &sList[currentStudent].sCrn[(i+2)], &sList[currentStudent].sCrn[(i+3)]);
                    currentIndex = (i+1);
                    break;
                }
            }

            if(populateCourse(sList, crn, credit, prefix, currentStudent) != (currentIndex+3)) {
                printf("\nInvalid course number has been entered.\n\n-----------------------------------------------\n\n");
                resetProgram(sList, currentStudent);
                return;
            }

            checkCreditHours(sList, crn, credit, prefix, currentStudent, courses);

            break;

        default:
            exit(0);
    }

    printf("\nSuccess!\n\n-----------------------------------------------\n\n");

    return;

}

int populateCourse(student sList[], int crn[], int credit[], char prefix[][8], int currentStudent)
{
    int valid = 0;

    for(int i = 0; i < STUMAX; i++){
        if(sList[currentStudent].sCrn[i] > 0) {
            for(int j = 0; j < 8; j++) {
                if(sList[currentStudent].sCrn[i] == crn[j]) {
                    sList[currentStudent].sCredit[i] = credit[j];
                    strcpy(sList[currentStudent].sPrefix[i], prefix[j]);
                    valid++;
                }
            }
        }
    }

    return valid;
}

void courseConfig(student sList[], int crn[], int credit[], char prefix[][8])
{
    int id;
    int courses;

    printf("\n\tEnter the student's id: ");
    scanf("%d", &id);

    while(id == 0) {
        printf("\n\tInvalid id number. Please re-enter.\n\n");
        printf("\n\n\t\tEnter the student's id: ");
        scanf("%d", &id);
    }

    for(int i = 0; i < STUMAX; i++) {
        if(id == sList[i].id) {
            if(sList[i].sCrn[0] == 0) {
                printf("\n%s is not currently enrolled in any courses...\n\n-----------------------------------------------\n\n", sList[i].sName);
            }

            printf("\n===============================================\n\nHere are the courses that %s is taking:\n", sList[i].sName);

            printf("\tCRN\t  PREFIX\tCR. HOURS\n");
            for(int j = 0; j < 4; j++) {
                if(sList[i].sCrn[j] == 0) {
                    break;
                }

                printf("\t%d\t  %s\t%d\n", sList[i].sCrn[j], sList[i].sPrefix[j], sList[i].sCredit[j]);
                ++courses;
            }

            printf("\n===============================================\n");

            configMenu(sList, crn, credit, prefix, i, courses);
            return;
        }
    }

    printf("\nNo student found!\n\n-----------------------------------------------\n\n");
    return;
}

void configMenu(student sList[], int crn[], int credit[], char prefix[][8], int currentStudent, int courses)
{
    char invoiceOption;
    char menuChoice;
    int addSub;

    printf("\nChoose from:\n\tA - Add a new course for %s\n\tD - Delete a course from %s's schedule\n\tC - Cancel operation\n\nEnter your selection: ", sList[currentStudent].sName, sList[currentStudent].sName);
    scanf(" %c", &menuChoice);

    do {
        switch(toupper(menuChoice)) {
            case 'A':
                if((4 - courses) == 0) {
                    printf("\n\t\tMaximum amount of courses already assigned (4).\n\n-----------------------------------------------\n\n");
                    return;
                }

                printf("\n\t%s is able to take %d more courses. How many will you add: ", sList[currentStudent].sName, (4-courses));
                scanf("%d", &addSub);

                if((addSub + courses) > 4) {
                    printf("\nThis would exceed the course limit (4).\n\n-----------------------------------------------\n\n");
                    return;
                }

                addClass(sList, crn, credit, prefix, currentStudent, addSub);

                //_______________________________________________________________________________________

                printf("Would you like to print a new invoice? [Y/N]: ");
                scanf(" %c", &invoiceOption);

                if(toupper(invoiceOption) == 'Y') {
                    print(sList, currentStudent);
                    return;
                }
                while(toupper(invoiceOption) != 'N') {
                    printf("\n\n\tInvalid option. Would you like to print a new invoice? [Y/N]: ");
                }

                printf("\n\n-----------------------------------------------\n\n");

                //_______________________________________________________________________________________

                return;
                break;

            case 'D':
                if(courses == 0) {
                    printf("\n\t\tThis student is not enrolled for any courses...\n\n-----------------------------------------------\n\n");
                    return;
                }

                printf("\n\tPlease enter the course ID of the class that you would like to remove: ");
                scanf("%d", &addSub);

                for(int i = 0; i < 4; i++) {
                    if(addSub == sList[currentStudent].sCrn[i]) {
                        addSub = i;
                        break;
                    }
                }

                while((addSub+1) < 4) {
                    if(sList[currentStudent].sCrn[addSub] == 0 || sList[currentStudent].sCrn[(addSub+1)] == 0) {
                        break;
                    }

                    sList[currentStudent].sCrn[addSub] = sList[currentStudent].sCrn[addSub+1];
                    sList[currentStudent].sCredit[addSub] = sList[currentStudent].sCredit[addSub+1];
                    strcpy(sList[currentStudent].sPrefix[addSub], sList[currentStudent].sPrefix[addSub+1]);

                    ++addSub;
                }

                sList[currentStudent].sCrn[addSub] = 0;
                sList[currentStudent].sCredit[addSub] = 0;
                strcpy(sList[currentStudent].sPrefix[addSub], "NULL");

                printf("\n\n\n\n\n\n");
                printf("\t      Gone for good!\n\n-----------------------------------------------\n\n");

                //_______________________________________________________________________________________

                printf("\nWould you like to print a new invoice? [Y/N]: ");
                scanf(" %c", &invoiceOption);

                if(toupper(invoiceOption) == 'Y') {
                    print(sList, currentStudent);
                    return;
                }
                while(toupper(invoiceOption) != 'N') {
                    printf("\n\n\tInvalid option. Would you like to print a new invoice? [Y/N]: ");
                }

                printf("\n\n-----------------------------------------------\n\n");

                //_______________________________________________________________________________________

                return;
                break;

            case 'C':
                printf("\n\n-----------------------------------------------\n\n");
                return;
                break;

            default:
                printf("\n\t\tInvalid option.\n");
                break;
        }
    }while(toupper(menuChoice) != 'C');
}

void searchStudent(student sList[], int crn[], int credit[], char prefix[][8])
{
    int id;
    char option;

    printf("\n\tEnter the student's ID: ");
    scanf("%d", &id);

    for(int i = 0; i < STUMAX; i++) {
        if(sList[i].id == id) {
            printf("\n--------------------STUDENT--------------------\n%s\n\tID: %d\n-----------------------------------------------\n", sList[i].sName, sList[i].id);
            printf("\nWould you like to view or edit this student's courses? [Y/N]: ");
            scanf(" %c", &option);

            if(toupper(option) == 'Y') {
                courseConfig(sList, crn, credit, prefix);
                return;
            }
            while(toupper(option) != 'N') {
                printf("\n\n\tInvalid option. Would you like to view or edit this student's courses? [Y/N]: ");
            }

            printf("\n\n-----------------------------------------------\n\n");

            return;
        }
    }

    printf("\nStudent not found!");
    printf("\n\n-----------------------------------------------\n\n");

    return;
}

void print(student sList[], int currentStudent)
{
    int id;
    float total = 35;

    if(currentStudent == 999) {
        printf("\n\tWho will this invoice be for? Please enter their ID: ");
        scanf("%d", &id);

        while(id == 0) {
            printf("\n\tInvalid id number. Please re-enter.\n\n");
            printf("\n\n\t\tEnter the student's id: ");
            scanf("%d", &id);
        }

        for(int i = 0; i < STUMAX; i++) {
            if(id == sList[i].id) {
                currentStudent = i;
            }
            if((i+1) == STUMAX && currentStudent == 999) {
                printf("\n\n\t\tStudent not found!\n\n-----------------------------------------------\n\n");
                return;
            }
        }

    } else {
        id = sList[currentStudent].id;
    }

    for(int i = 0; i < STUMAX; i++) {
        total += (float)(sList[currentStudent].sCredit[i] * 120.25 );
    }

    printf("\n\n\n\t\tVALENCE COMMUNITY COLLEGE\n\t\tORLANDO FL 10101\n\t\t***********************************************\n");
    printf("\n\t\tFee Invoice Prepared for Student: %d-%s\n\n\t\t1 Credit Hour = $120.25\n\n\t\tCRN\tCR_PREFIX\tCR_HOURS", id, sList[currentStudent].sName);

    for(int i = 0; i < 4; i++) {
        if(sList[currentStudent].sCrn[i] == 0) {
            break;
        }

        printf("\n\t\t%-10d%-20s%-8d$ %.2f", sList[currentStudent].sCrn[i], sList[currentStudent].sPrefix[i], sList[currentStudent].sCredit[i], (float)(sList[currentStudent].sCredit[i] * 120.25) );
    }

    printf("\n\n\t\t\t\t    Health & ID fees  $ 35.00\n\n\t\t-----------------------------------------------\n");
    printf("\t\t\t\t    Total Payments    $ %.2f\n\n\n", total);

}

void checkCreditHours(student sList[], int crn[], int credit[], char prefix[][8], int currentStudent, int courses)
{
    int total = 0;
    char creditMenuChoice;

    for(int i = 0; i < 4; i++) {
        total = (sList[currentStudent].sCredit[i]) + total;
    }

    if(total > 7) {
        printf("\n\t\tStudents cannot take more than 7 credit hours.\n");
    } else {
        return;
    }

    printf("\n\tChoose from:\n\t\tA - Re-enter the %d course numbers\n\t\tB - Reset student and return to Main Menu\n\n\tYour selection: ", courses);
    scanf(" %c", &creditMenuChoice);

    switch(toupper(creditMenuChoice)) {
        case 'A':
            for(int i = 0; i < 4; i++) {
                sList[currentStudent].sCrn[i] = 0;
                sList[currentStudent].sCredit[i] = 0;
                strcpy(sList[currentStudent].sPrefix[i], "NULL");
            }

            addClass(sList, crn, credit, prefix, currentStudent, courses);
            break;

        case 'B':
            resetProgram(sList, currentStudent);
            break;
    }

    return;
}
