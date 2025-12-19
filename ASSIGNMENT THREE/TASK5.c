# include <stdio.h>

void swapNumbers(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


int main (){
    int a = 5;
    int b = 10;

    printf("Before swapping: a = %d, b = %d\n",a,b);

     swapNumbers(&a, &b);

    printf ("Atfer swapping : a= %d, b = %d\n", a, b);

    return 0;
}
