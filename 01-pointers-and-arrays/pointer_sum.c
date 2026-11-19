/*
 * Add two numbers using pointers.
 */
#include <stdio.h>

int main(void) {
    int num1, num2, sum;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    printf("Input the first number: ");
    scanf("%d", ptr1);
    printf("Input the second number: ");
    scanf("%d", ptr2);

    sum = *ptr1 + *ptr2;
    printf("The sum of the entered numbers is: %d\n", sum);
    return 0;
}
