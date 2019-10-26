#include <stdio.h>

typedef unsigned int u_int;

int primetest(u_int num){
    for (u_int i = 2; i <= num; i++)
        if (num % i == 0)
           return 0;
   return 1;
}

int main(){
    u_int p = 4294967029;
    printf("%d",primetest(p));
    return 0;
}