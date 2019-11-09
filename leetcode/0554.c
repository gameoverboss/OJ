#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX_COL 10000
#define MAX_ROW 10000
static int g_map[MAX_ROW];
static int g_index[MAX_ROW];

int leastBricks(int** wall, int wallSize, int* wallColSize){
    int max = 0;
    int cur = 0;
    int len = 0;
    int nextIndex = 0;

    for (int i = 0; i < wallColSize[0]; i++) {
        len += wall[0][i];
    }
    nextIndex = len;
    for (int i = 0; i < wallSize; i++) {
        g_map[i] = wall[i][0];
        g_index[i] = 0;
        if (g_map[i] < nextIndex) {
            nextIndex = g_map[i];
        }
    }

    for (int i = nextIndex; i < len;) {
        cur = 0;
        nextIndex = len;
        for (int r = 0; r < wallSize; r++) {
            if (g_map[r] < i) {
                g_index[r]++;
                g_map[r] += wall[r][g_index[r]];
            }
            if (g_map[r] == i) {
                cur++;
            } else {
                if (g_map[r] < nextIndex) {
                    nextIndex = g_map[r];
                }
            }
        }
        if (cur > max) {
            max = cur;
        }
        i = nextIndex;
    }

    return wallSize - max;
}


int main(void)
{

    return 0;
}