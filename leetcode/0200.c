#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char** grid, int row, int col, int i, int j)
{
    grid[i][j] = '0';

    if (i-1 >= 0 && grid[i-1][j] == '1') {
        dfs(grid, row, col, i-1, j);
    }
    if (i+1 < row && grid[i+1][j] == '1') {
        dfs(grid, row, col, i+1, j);
    }
    if (j-1 >= 0 && grid[i][j-1] == '1') {
        dfs(grid, row, col, i, j-1);
    }
    if (j+1 < col && grid[i][j+1] == '1') {
        dfs(grid, row, col, i, j+1);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int ret = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[0]; j++) {
            if (grid[i][j] == '1') {
                ret++;
                dfs(grid, gridSize, gridColSize[0], i, j);
            }
        }
    }

    return ret;
}

int main(void)
{
    int ret;
    int n;

    ret = numIslands(NULL, 0, &n);
    printf("%p\n", ret);
    return 0;
}