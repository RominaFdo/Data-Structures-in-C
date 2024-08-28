
#include <stdio.h>

int main() {
    int arr[10];
    for (int i=0; i<9; i++){
        printf("Enter value:");
        scanf("%d" , &arr[i]);
    }
    printf("Original array:\n");
    for(int  i=0; i<9; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    for (int i=9; i>2; i--){
        arr[i]=arr[i-1];
    }
    arr[2]=12;
    printf("Array after inserting 12 into the 3rd position:\n");
    for(int  i=0; i<10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    for (int i=6; i<10; i++){
        arr[i]=arr[i+1];
    }
    arr[2]=12;
    printf("Array after deleting 8 from it:\n");
    for(int  i=0; i<9; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

