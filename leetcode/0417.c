#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN (150)
static int g_state[MAX_LEN][MAX_LEN];
static int g_Pac[MAX_LEN][MAX_LEN];
static int g_Atl[MAX_LEN][MAX_LEN];

static void seachPac(int i, int j, int** matrix, int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return;
    }

    if (g_Pac[i][j] == 1) {
        return;
    }
    g_Pac[i][j] = 1;

    g_state[i][j] = 1;

    if ((i-1 >= 0) && (matrix[i][j] <= matrix[i-1][j])) {
        seachPac(i-1, j, matrix, m, n);
    }
    if ((i+1 < m) && (matrix[i][j] <= matrix[i+1][j])) {
        seachPac(i+1, j, matrix, m, n);
    }
    if ((j-1 >= 0) && (matrix[i][j] <= matrix[i][j-1])) {
        seachPac(i, j-1, matrix, m, n);
    }
    if ((j+1 < n) && (matrix[i][j] <= matrix[i][j+1])) {
        seachPac(i, j+1, matrix, m, n);
    }
}

static void seachAtl(int i, int j, int** matrix,  int m, int n)
{
    if (i < 0 || j < 0 || i >= m || j >= n) {
        return;
    }

    if (g_Atl[i][j] == 1) {
        return;
    }
    g_Atl[i][j] = 1;

    g_state[i][j] |= 2;

    if ((i-1 >= 0) && (matrix[i][j] <= matrix[i-1][j])) {
        seachAtl(i-1, j, matrix, m, n);
    }
    if ((i+1 < m) && (matrix[i][j] <= matrix[i+1][j])) {
        seachAtl(i+1, j, matrix, m, n);
    }
    if ((j-1 >= 0) && (matrix[i][j] <= matrix[i][j-1])) {
        seachAtl(i, j-1, matrix, m, n);
    }
    if ((j+1 < n) && (matrix[i][j] <= matrix[i][j+1])) {
        seachAtl(i, j+1, matrix, m, n);
    }
}

int** pacificAtlantic(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int count = 0;

    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL; 
    }

    for (int i = 0; i < MAX_LEN; i++) {
        for (int j = 0; j < MAX_LEN; j++) {
            g_state[i][j] = 0;
            g_Pac[i][j] = 0;
            g_Atl[i][j] = 0;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        seachPac(i, 0, matrix, matrixSize, matrixColSize[0]);       
    }
    for (int j = 0; j < matrixColSize[0]; j++) {
        seachPac(0, j, matrix, matrixSize, matrixColSize[0]);       
    }
    for (int i = matrixSize - 1; i >= 0; i--) {
        seachAtl(i, matrixColSize[0]-1, matrix, matrixSize, matrixColSize[0]);
    }
    for (int j = matrixColSize[0]-1; j >= 0; j--) {
        seachAtl(matrixSize - 1, j, matrix, matrixSize, matrixColSize[0]);
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (g_state[i][j] == 3) {
                count++;
            }
        }
    }
    *returnSize = count;
    if (count == 0) {
        return NULL;
    }
    int *col = malloc(sizeof(int)*count);
    *returnColumnSizes = col;
    for (int i = 0; i < count; i++) {
        col[i] = 2;
    }
    int **ret = malloc(sizeof(int*)*count);
    int k = 0;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            if (g_state[i][j] == 3) {
                ret[k] = malloc(sizeof(int)*2);
                ret[k][0] = i;
                ret[k][1] = j;
                k++;
            }
        }
    }
    return ret;
}

int main(void)
{
    int ** ret;
    int n;
    int *p;

/*
[
    [1,2,2,3,5],
    [3,2,3,4,4],
    [2,4,5,3,1],
    [6,7,1,4,5],
    [5,1,1,2,4]]
*/
    ret = pacificAtlantic(NULL, 0, NULL, &n, &p);
    printf("%p\n", ret);
    return 0;
}