#include <stdio.h>
#include <stdlib.h>

static int getArea(int* height, int left, int right)
{
    if (height[left] > height[right]) {
        return height[right] * (right - left);
    }
    return height[left] * (right - left);
}

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int ret;
    int max = getArea(height, left, right);

    for (; left < right; ) {
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
        ret = getArea(height, left, right);
        if (ret > max) {
            max = ret;
        }
    }
    return max;
}

int main(void)
{
    int nums[] = {1,8,6,2,5,4,8,3,7};
    int ret;

    ret = maxArea(nums, sizeof(nums)/sizeof(int));
    printf("%d\n", ret);
    return 0;
}