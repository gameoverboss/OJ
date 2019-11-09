#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_A 80000

static int g_map[MAX_A];
static int g_q[MAX_A];
static int g_qIndex;
static int g_qCur;

int deq()
{
    g_qCur++;
    return g_q[g_qCur - 1];
}

void enq(int x, int count)
{
    for (int i = 0; i < count; i++) {
        g_q[g_qIndex] = x;
        g_qIndex++;
    }
}

int minIncrementForUnique(int* A, int ASize)
{
    int ret = 0;
    memset(g_map, 0, sizeof(g_map));
    g_qIndex = 0;
    g_qCur = 0;

    for (int i = 0; i < ASize; i++) {
        g_map[A[i]]++;
    }
    for (int i = 0; i < MAX_A; i++) {
        if (g_map[i] >= 2) {
            enq(i, g_map[i] - 1);
        } else if ((g_qCur != g_qIndex) && (g_map[i] == 0)) {
            ret += i - deq();
        }
    }
    return ret;
}

int main(void)
{
    int ret;
    int A[10] = { 1, 2, 2 };
    ret = minIncrementForUnique(A, 3);
    return 0;
}