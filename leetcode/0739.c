#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int *p = malloc(sizeof(int)*TSize);
    *returnSize = TSize;

    for (int i = TSize - 1; i >= 0; i--) {
        p[i] = 0;
        for (int j = i + 1; j < TSize;) {
            if (T[j] > T[i]) {
                p[i] = j - i;
                break;
            } else {
                if (p[j] == 0) {
                    break;
                } else {
                    j += p[j];
                }
            }
        }
    }

    return p;
}


int main(void)
{

    return 0;
}