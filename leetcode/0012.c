#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// one int max 4 char, 1-3999
#define MAX_LEN (4*4+1)

char * intToRoman(int num){
    static char s[MAX_LEN];
    int nums[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    char *strs[] = {"I", "IV", "V", "IX", "X", "XL","L","XC","C","CD","D","CM","M"};
    int len = sizeof(nums)/sizeof(int);

    s[0] = '\0';
    for (int i = len -1; i >= 0; i--) {
        if (num >= nums[i]) {
            num = num - nums[i];
            strcat(s, strs[i]);
            i++;
            continue;
        }
    }

    return s;
}

int main(void)
{
    char * ret;

    ret = intToRoman(4);
    printf("%s\n", ret);
    ret = intToRoman(1994);
    printf("%s\n", ret);
    ret = intToRoman(1888);
    printf("%s\n", ret);
    return 0;
}