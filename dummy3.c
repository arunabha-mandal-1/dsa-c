#include<stdio.h>
#include<stdlib.h>

int main()
{
    static int x=0;
    x++;
    printf("Team %d\n",x);
    if(x<10)
        main();
    else
        exit;
}