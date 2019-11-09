#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int bfs(int** grid, int n, int i, int j)
{
    int ret = 0;
    int newLand = grid[i][j] + 1;

    if (i-1 >= 0 && grid[i-1][j] == 0) {
        grid[i-1][j] = newLand;
        ret++;
    }
    if (i+1 < n && grid[i+1][j] == 0) {
        grid[i+1][j] = newLand;
        ret++;
    }
    if (j-1 >= 0 && grid[i][j-1] == 0) {
        grid[i][j-1] = newLand;
        ret++;
    }
    if (j+1 < n && grid[i][j+1] == 0) {
        grid[i][j+1] = newLand;
        ret++;
    }
    return ret;
}

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int land = 1;
    int ret = 0;

LOOP:
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == land) {
                ret += bfs(grid, gridSize, i, j);
            }
        }
    }
    if (ret != 0) {
        land++;
        ret = 0;
        goto LOOP;
    }

    if (land == 1) {
        return -1;
    }
    return land - 1;
}

int main(void)
{
    int ret;
    int n;

    ret = maxDistance(NULL, 0, &n);
    printf("%p\n", ret);
    return 0;
}