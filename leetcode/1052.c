#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int X){
    int m = 0;
    int base = 0;
    int cur;

    for (int i = 0; i < customersSize; i++) {
        if (grumpy[i] == 0) {
            base += customers[i];
        }
    }

    for (int i = 0; i + X <= customersSize; i++) {
        cur = base;
        for (int j = 0; j < X; j++) {
            if (grumpy[i+j] == 1) {
                cur += customers[i+j];
            }
        }
        if (cur > m) {
            m = cur;
        }
    }

    return m;
}

int main(void)
{

    return 0;
}