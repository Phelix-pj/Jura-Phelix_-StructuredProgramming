#include <stdio.h>

int main() {
    int n, i, val, pos;
    printf("Input the size of array: ");
    scanf("%d", &n);

    int arr[n + 1]; // Size + 1 to accommodate new element
    for(i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Input the value to be inserted: ");
    scanf("%d", &val);
    printf("Input the Position (0 to %d): ", n);
    scanf("%d", &pos);

    // Shift elements to the right
    for(i = n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;

    printf("After Insert the element the new list is: ");
    for(i = 0; i <= n; i++) printf("%d ", arr[i]);

    return 0;
}
