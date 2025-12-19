# include <stdio.h>

int main (){
    int num = 10;
    int *ptr;

    ptr = &num;


    printf("The value of num is %d\n", num);
    printf("The value stored in the Address of num is %p\n", (void *)ptr);
    printf("Address of num is %d\n", (void *) &num);
    printf("The value accessed using *ptr  is %d\n", *ptr);

    return 0;
}
