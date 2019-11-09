#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int max(int a, int b)
{
    if (a >= b) {
        return a;
    }
    return b;
}

static void dp(struct TreeNode* root, int *no, int *yes)
{
    if (root == NULL) {
        *no = 0;
        *yes = 0;
        return;
    }
    int lno, lyes, rno, ryes;
    dp(root->left, &lno, &lyes);
    dp(root->right, &rno, &ryes);
    *no = max(lno, lyes) + max(rno, ryes);
    *yes = root->val + lno + rno;
}

int rob(struct TreeNode* root){
    int no, yes;
    dp(root, &no, &yes);
    return max(no, yes);
}

int main(void)
{
    int ret;

    ret = rob(NULL);
    printf("%d\n", ret);
    return 0;
}