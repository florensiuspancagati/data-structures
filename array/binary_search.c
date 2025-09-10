#include<stdio.h>

int binarySearch(int array[], int begining, int end, int searched) {
    if(end >= begining) {
        int mid = (begining + end) / 2;
        printf("Search in index %d - %d, mid = %d (value = %d)\n", begining, end, mid, array[mid]);
        if(array[mid] == searched) {
            return mid+1;
        } else if(array[mid] < searched) {
            return binarySearch(array, mid+1, end, searched);
        } else {
            return binarySearch(array, begining, mid-1, searched);
        }
    }
    return 0;
}

int main() {
int array[] = {5, 7, 8, 16, 21, 80, 87, 89, 100};
    int length = sizeof(array)/sizeof(array[0]);
    int searched = 100;
    int result = binarySearch(array, 0, length-1, searched);

    printf("\n\nThe elements of the array are:\n");
    for(int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\nElement to be searched is    : %d", searched);
    if(result == -1) {
        printf("\nElement is not present in the array.");
    } else {
        printf("\nElement is present at %d position of array.", result);
    }
    printf("\n\n\n");
    return 0;
}