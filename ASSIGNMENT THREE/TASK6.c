#include <stdio.h>

void incrementByValue(int x) {
    x = x + 1;
}

void incrementByReference(int *x) {
    *x = *x + 1;
}

int main() {
    int num = 10;

    printf("Original value: %d\n", num);

    incrementByValue(num);
    printf("After incrementByValue: %d\n", num);

    incrementByReference(&num);
    printf("After incrementByReference: %d\n", num);

    return 0;
}
