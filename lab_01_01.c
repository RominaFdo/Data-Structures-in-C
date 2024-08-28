
#include <stdio.h>

int main() {
    int num1,num2,sum;
    int *ptr1;
    int *ptr2;
    printf("Test Data: \n");
    printf("Input the first number: \n");
    scanf("%d", &num1);
    printf("Input the second number: \n");
    scanf("%d", &num2);
    ptr1 = &num1;
    ptr2 = &num2;
    sum = *ptr1 + *ptr2;
    printf("The sum of the entered numbers is: %d",sum);
    return 0;
}
