# include <stdio.h>

int main(){
    int count = 10;
    int *pCount;

    pCount = &count;

    *pCount = 20;

    printf("Updated value of count is %d\n",count);

    return 0;
}
