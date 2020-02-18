#include "header.h"

long long int potencia(long int, long int); //función recursiva

long long int hashing(long int key) {
    long long int num1, res;

    num1 = ((key / 1000) + 1) / 2;
    res = (potencia(key,num1) / 100);
    res = res % 100;

    return res;
}

long long int potencia(long int x, long int y) {
    if (y==0)
         return 1;
    else
         return x*(potencia(x,y-1));
}
