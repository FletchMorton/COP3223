// Fletcher Morton
// HW1

#include <stdio.h>

/* Question 1

It's
ormal to        ake C! 1o you like it!

*/

/* Question 2

3
0.00
1.50
1  2

*/

/* Question 3

$   36

*/

int main()
{
    float x;

    printf("Enter a distance in miles to have it converted into kilometers: ");
    scanf("%f", &x);
    printf("\n%.2f miles is equivalent to %.2f kilometers\n\n", x, (x*1.609));


    return 0;
}
