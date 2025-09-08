#include<stdio.h>

int main() {
    int array[10] = {1,2,3,4,5,6,7,8,9,10}; // array declaration and initialization
    int odd = 0;                            // counter for odd numbers
    int even = 0;                           // counter for even numbers
    int isOdd[sizeof(array)/sizeof(int)];   // array to store odd numbers
    int isEven[sizeof(array)/sizeof(int)];  // array to store even numbers
    
    // logic to separate odd and even numbers
    int i;
    for(i = 0; i < 10; i++) {
        if(array[i] % 2 == 0) {
            isEven[even] = array[i];
            even++;
        } else {
            isOdd[odd] = array[i];
            odd++;
        }
    }

    // logic to visualize array's values
    printf("\nAn array have values    : ");
    for(i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    // logic to visualize odd and even numbers
    printf("\nEven: \n");
    printf("Total even numbers      : %d\n", even);
    printf("Even numbers consist of : ");
    for(i = 0; i < even; i++) {
        printf("%d ", isEven[i]);
    }

    printf("\nOdd: \n");
    printf("Total odd numbers       : %d\n", even);
    printf("Odd numbers consist of  : ");
    for(i = 0; i < odd; i++) {
        printf("%d ", isOdd[i]);
    }
    printf("\n");

    return 0;
}