#include <stdio.h>

int main() {
    int n, i, max, min;
    printf("Input the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    max = min = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    printf("Maximum element is: %d\n", max);
    printf("Minimum element is: %d\n", min);
    return 0;
}
