#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CAN_GO (-1)

bool canJump(int* nums, int numsSize){
    nums[numsSize - 1] = CAN_GO;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (i + nums[i] >= numsSize) {
            nums[i] = CAN_GO;
            continue;
        }
        for (int j = nums[i]; j > 0; j--) {
            if (nums[i + j] == CAN_GO) {
                nums[i] = CAN_GO;
                break;
            }
        }
    }

    if (nums[0] == CAN_GO) {
        return true;
    }

    return false;
}

int main(void)
{

    return 0;
}