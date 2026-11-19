/*
 * Insert into and delete from a fixed-size array.
 * Reads 9 values, inserts 12 at index 2, then deletes the element at index 6.
 */
#include <stdio.h>

int main(void) {
    int arr[10];
    for (int i = 0; i < 9; i++) {
        printf("Enter value: ");
        scanf("%d", &arr[i]);
    }

    printf("Original array:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    /* Shift elements right to make room at index 2 */
    for (int i = 9; i > 2; i--) {
        arr[i] = arr[i - 1];
    }
    arr[2] = 12;
    printf("Array after inserting 12 into the 3rd position:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    /* Shift elements left to remove index 6 */
    for (int i = 6; i < 9; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Array after deleting the element at the 7th position:\n");
    for (int i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
