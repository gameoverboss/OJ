#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DEL 200000

int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

bool canReorderDoubled(int* A, int ASize){
    qsort(A, ASize, sizeof(int), compare);

    int next;
    int j = 1;
    for (int i = 0; i < ASize; i++) {
        if (A[i] == DEL) {
            continue;
        }
        if (A[i] < 0) {
            if (A[i] % 2 != 0) {
                return false;
            }
            next = A[i] / 2;
        } else {
            next = A[i] * 2;
        }
        bool isFound = false;
        for (; j < ASize; j++) {
            if (A[j] == next) {
                isFound = true;
                A[j] = DEL;
                j++;
                break;
            }
        }
        if (isFound == false) {
            return false;
        }
    }
    return true;
}

int main(void)
{
    bool ret;

    ret = canReorderDoubled(NULL, 0);
    printf("%p\n", ret);
    return 0;
}