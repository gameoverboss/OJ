#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX (24 + 0.000001)
#define MIN (24 - 0.000001)
#define MAX_LEN 4

void DelNums(double* nums, int numsSize, int i, int j, double* newData)
{
    int index = 0;
    for (int k = 0; k < numsSize; k++) {
        if (k == i || k == j) {
            continue;
        }
        newData[index] = nums[k];
        index++;
    }
}

bool Judge(double* nums, int numsSize)
{
    bool ret = false;
    double newData[MAX_LEN];

    if (numsSize == 1) {
        if (nums[0] <= MAX && nums[0] >= MIN) {
            return true;
        } else {
            return false;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        for(int j = 0; j < numsSize; j++) {
            if (i == j) {
                continue;
            }
            DelNums(nums, numsSize, i, j, newData);
            newData[numsSize - 2] = nums[i] + nums[j];
            ret = Judge(newData, numsSize - 1);
            if (ret == true) {
                return true;
            }
            newData[numsSize - 2] = nums[i] - nums[j];
            ret = Judge(newData, numsSize - 1);
            if (ret == true) {
                return true;
            }
            newData[numsSize - 2] = nums[i] * nums[j];
            ret = Judge(newData, numsSize - 1);
            if (ret == true) {
                return true;
            }
            if (nums[j] == 0) {
                continue;
            }
            newData[numsSize - 2] = nums[i] / nums[j];
            ret = Judge(newData, numsSize - 1);
            if (ret == true) {
                return true;
            }
        }
    }

    return ret;
}

bool judgePoint24(int* nums, int numsSize){
    double newData[MAX_LEN];

    for (int i = 0; i < numsSize; i++) {
        newData[i] = nums[i];
    }
    return Judge(newData, numsSize);
}


int main(void)
{
    int ret;
    int d[4] = {4, 1, 8, 7};

    ret = judgePoint24(d, 4);
    printf("%d\n", ret);
    return 0;
}