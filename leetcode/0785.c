#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODE 100
static int g_node[MAX_NODE];

static bool dfs(int** graph, int graphSize, int* graphColSize, int i)
{
    bool ret;
    int curSet = g_node[i];
    int othSet = 1;
    if (curSet == 1) {
        othSet = 2;
    }

    for (int j = 0; j < graphColSize[i]; j++) {
        if (g_node[graph[i][j]] == 0) {
            g_node[graph[i][j]] = othSet;
            ret = dfs(graph, graphSize, graphColSize, graph[i][j]);
            if (ret == false) {
                return false;
            }
        } else if (g_node[graph[i][j]] == curSet) {
            return false;
        }
    }

    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize){
    memset(g_node, 0, sizeof(g_node));

    bool ret;
    g_node[0] = 1;
    for (int i = 0; i < graphSize; i++) {
        ret = dfs(graph, graphSize, graphColSize, i);
        if (ret == false) {
            return false;
        }
    }

    return true;
}

int main(void)
{

    return 0;
}