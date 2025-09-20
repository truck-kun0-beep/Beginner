#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,sum=0,count=0,num=1;
    while(count<50){
        sum+=num;
        num+=2;
        count++;
    }
    printf("Sum of first 50 odd numbers = %d\n",sum);
    return 0;
}
