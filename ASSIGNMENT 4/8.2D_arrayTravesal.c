#include <stdio.h>

int main() {
    int rows = 6, cols = 4;
    int arr[6][4];
    int i, j, val = 1;

    // Initialize with dummy values
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            arr[i][j] = val++;
        }
    }

    // Traverse and print
    printf("2D Array Traversal (6x4):\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            printf("%2d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
