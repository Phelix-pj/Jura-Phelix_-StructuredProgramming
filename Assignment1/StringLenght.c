#include <stdio.h>
#include <string.h>
int main(){

char  name [20];

printf("Enter your name and press ENTER:\n");
scanf("%s",&name);

printf("What's up %s\n",name);

printf("Your name has %zu characters\n", strlen(name));


return 0;
}
