#include <stdio.h>

/*
4
3+1
2+2
2+1+1
1+1+1+1
*/
static int g_count[120][120];

int get_split_count(int n, int max)
{
    int ret;
    //printf("%d %d\n", n, max);
    if (n == 1 || max == 1)
        return 1;
    if (g_count[n-1][max-1] != 0)
        return g_count[n-1][max-1];

    if (n == max) {
        ret = 1 + get_split_count(n, n - 1);
        goto out;
    }
    if (n < max) {
        ret = get_split_count(n, n);
        goto out;
    }
    ret = get_split_count(n, max - 1) + get_split_count(n - max, max);
out:
    g_count[n-1][max-1] = ret;
    return ret;
}

int main(void)
{
    printf("%d\n", get_split_count(4, 4));
    printf("%d\n", get_split_count(6, 6));
    printf("%d\n", get_split_count(120, 120));
    return 0;
}