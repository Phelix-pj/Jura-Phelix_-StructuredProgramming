

#include <stdio.h>

int main() {

    int num1, num2;
    int *ptr1, *ptr2;

    num1 = 10;
    num2 = 20;

    ptr1 = &num1;
    ptr2 = &num2;

    int sum = *ptr1 + *ptr2;

    printf("Sum = %d\n", sum);

    return 0;
}

