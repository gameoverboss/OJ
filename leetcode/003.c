#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char * s){
    int i;
    int len = strlen(s);
    int max = 1;
    int begin = 0;
    int end = 1;
    int found;

    if (len <= 1) {
        return len;
    }

    for (; end <= len - 1; end++) {
        found = 0;
        for (i = 0; begin + i < end; i++) {
            if (s[end] == s[begin + i]) {
                found = 1;
                break;
            }
        }
        if (found) {
            begin = begin + i + 1;
            continue;
        }
        if (end + 1 - begin > max) {
            max = end + 1 - begin;
        }
    }

    return max;
}


int main(void)
{
    printf("%d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("%d\n", lengthOfLongestSubstring("bbbbbb"));
    printf("%d\n", lengthOfLongestSubstring("aab"));
    printf("%d\n", lengthOfLongestSubstring("pwwkew"));

    return 0;
}
