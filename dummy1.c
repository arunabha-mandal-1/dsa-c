#include <stdio.h>

void change(int *a){
    *(a) = *(a)+10;
    return;
}
int main(){
    int temp=15;
    printf("%d\n", temp);

    change(&temp);
    printf("%d\n", temp);
    return 0;
}