#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int j;
    int tmp;
    int *ret = malloc(2 * sizeof(int));
    *returnSize = 2;

    for (i = 0; i < numsSize - 1; i++) {
        tmp = target - nums[i];
        for (j = i + 1; j < numsSize; j++) {
            if (tmp == nums[j]) {
                    ret[0] = i;
                    ret[1] = j;
                    return ret;
            }
        }
    }

    return NULL;
}

int main(void)
{
    int nums[4] = { 2, 7, 11, 15 };
    int *ret;
    int tmp;

    ret = twoSum(nums, 4, 9, &tmp);
    printf("%d,%d\n", ret[0], ret[1]);
    return 0;
}