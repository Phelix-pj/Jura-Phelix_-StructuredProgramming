#include <stdio.h>

int main() {
    int n, i, j, count;
    printf("Input the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
    }

    printf("The unique elements found in the array are: ");
    for(i = 0; i < n; i++) {
        count = 0;
        for(j = 0; j < n; j++) {
            if(i != j && arr[i] == arr[j]) {
                count++;
                break;
            }
        }
        if(count == 0) printf("%d ", arr[i]);
    }
    return 0;
}
