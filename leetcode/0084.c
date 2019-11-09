#include <stdio.h>
#include <stdlib.h>


int largestRectangleArea(int* heights, int heightsSize){
    int max;
    int tmp;
    int minIndex;
    int minH;

    if (heightsSize == 0) {
        return 0;
    }
    if (heightsSize == 1) {
        return heights[0];
    }

    minH = heights[0];
    minIndex = 0;
    for (int i = 1; i < heightsSize; i++) {
        if (heights[i] < minH) {
            minH = heights[i];
            minIndex = i;
        }
    }

    max = minH * heightsSize;
    tmp = largestRectangleArea(heights, minIndex);
    if (tmp > max) {
        max = tmp;
    }
    tmp = largestRectangleArea(heights + (minIndex + 1), heightsSize - minIndex - 1);
    if (tmp > max) {
        max = tmp;
    }

    return max;
}


int main(void)
{
    
    return 0;
}