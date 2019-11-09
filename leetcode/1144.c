#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>




int movesToMakeZigzag(int* nums, int numsSize){
    int ret1 = 0;
    int ret2 = 0;
    int d1;
    int d2;

    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == 0) {
            if (i > 0 && nums[i] >= nums[i - 1]) {
                d1 = nums[i] - nums[i - 1] + 1;
            } else {
                d1 = 0;
            }
            if (i < numsSize - 1 && nums[i] >= nums[i + 1]) {
                d2 = nums[i] - nums[i + 1] + 1;
            } else {
                d2 = 0;
            }
            if (d1 >= d2) {
                ret1 += d1;
            } else {
                ret1 += d2;
            }
        } else {
            if (i > 0 && nums[i] >= nums[i - 1]) {
                d1 = nums[i] - nums[i - 1] + 1;
            } else {
                d1 = 0;
            }
            if (i < numsSize - 1 && nums[i] >= nums[i + 1]) {
                d2 = nums[i] - nums[i + 1] + 1;
            } else {
                d2 = 0;
            }
            if (d1 >= d2) {
                ret2 += d1;
            } else {
                ret2 += d2;
            }
        }
    }
    if (ret1 <= ret2) {
        return ret1;
    }
    return ret2;
}


int main(void)
{

    return 0;
}