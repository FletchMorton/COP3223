// Fletcher Morton
// HW6

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

void populate (int[], int *);
void pass (int[], int);
void distribution (int[], int);
void deviation (int[], int);

int main()
{
    int scores[MAX] = {0};
    int limit;

    populate(scores, &limit);

    printf("Here is your report:\n");
    pass(scores, limit);
    distribution(scores, limit);
    deviation(scores, limit);

    printf("\nGoodbye!\n");
    return 0;
}

void populate(int scores[], int *pLimit) {

    printf("Enter how many scores you want to process: ");
    scanf("%d", &*pLimit);

    printf("Enter your %d scores: ", *pLimit);
    for(int i = 0; i < *pLimit; i++) {
        scanf("%d", &scores[i]);
    }
}

void pass(int scores[], int limit) {
    int pass = 0;

    for(int i = 0; i < limit; i++) {
        switch( (scores[i]) / 10 ) {
            case 10:
            case 9:
            case 8:
            case 7:
                pass++;
                break;
            default:    ;
        }
    }

    printf("\n\t- %d students passed the test with a score of 70 or higher\n", pass);

}

void distribution(int scores[], int limit) {
    int a = 0, b = 0, c = 0, d = 0, f = 0;

    for(int i = 0; i < limit; i++) {
        switch( (scores[i]) / 10) {
            case 10:
            case 9:
                a++;
                break;
            case 8:
                b++;
                break;
            case 7:
                c++;
                break;
            case 6:
                d++;
                break;
            default:
                f++;
        }
    }

    printf("\n\t- Letter Grade distribution of the scores:");
    printf("\n\t\t- %d students earned the grade of A (90-100)\n\t\t- %d students earned the grade of B (80-89)\n\t\t- %d students earned the grade of C (70-79)", a, b, c);
    printf("\n\t\t- %d students earned the grade of D (60-69)\n\t\t- %d students earned the grade of F (0-59)\n", d, f);

}

void deviation(int scores[], int limit) {
    float sum = 0;
    float avg, sigma;

    for(int i = 0; i < limit; i++) {
        sum += scores[i];
    }

    avg = sum /(float) limit;
    sum = 0;

    for(int j = 0; j < limit; j++) {
        sum += (pow(( (float) scores[j] - avg ), 2));
    }

    sigma = sqrt(sum /(float) limit);

    printf("\n\t- The Standard Deviation of the score is: %.2f\n", sigma);

}
