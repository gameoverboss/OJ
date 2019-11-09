#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long g_map[101][101];

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    memset(g_map, 0, sizeof(g_map));
    if (obstacleGrid[0][0] == 1) {
        return 0;
    }

    g_map[0][0] = 1;
    for (int j = 1; j < obstacleGridColSize[0]; j++) {
        if (obstacleGrid[0][j] == 1) {
            g_map[0][j] = 0;
        } else {
            g_map[0][j] = g_map[0][j - 1];
        }
    }
    for (int i = 1; i < obstacleGridSize; i++) {
        if (obstacleGrid[i][0] == 1) {
            g_map[i][0] = 0;
        } else {
            g_map[i][0] = g_map[i - 1][0];
        }
    }

    for (int i = 1; i < obstacleGridSize; i++) {
        for (int j = 1; j < obstacleGridColSize[0]; j++) {
            if (obstacleGrid[i][j] == 1) {
                g_map[i][j] = 0;
            } else {
                g_map[i][j] = g_map[i - 1][j] + g_map[i][j - 1];
            }
        }
    }
    return g_map[obstacleGridSize - 1][obstacleGridColSize[0] - 1];
}

int main(void)
{
    printf("%d\n", (1<<31) - 1);
    return 0;
}