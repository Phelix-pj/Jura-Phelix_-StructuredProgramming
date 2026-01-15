# include <stdio.h>

int main(){
    int n,i;
    printf("Input the number of elements to store in the array: ");

    int arr[n];
    printf("Input %d number of elements in the array:\n");
    for(i = 0; i < n; i++){
        printf("element -%d");
        scanf("%d",&arr[i]);
    }
    printf("\n The values stored into the array are:");
    for(i=n-1; i>=0; i++)
        printf("%d",arr[i]);
    printf("\n The values stored into the array in reverse are:");
    for (i = n-1; i>= 0; i--)
        printf("%d", arr[i]);

    return 0;
}
