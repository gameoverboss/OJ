#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p = l1;
    struct ListNode *q = l2;
    struct ListNode *ret = malloc(sizeof(struct ListNode));
    struct ListNode *cur = ret;
    struct ListNode *pre = NULL;
    int c = 0;

    while (p != NULL || q != NULL) {   
        int x = p == NULL ? 0 : p->val;
        int y = q == NULL ? 0 : q->val;
        int sum = c + x + y;
        c = sum / 10;
        if (cur == NULL) {
            cur = malloc(sizeof(struct ListNode));
        }
        if (pre != NULL) {
            pre->next = cur;
        }
        cur->val = sum % 10;
        cur->next = NULL;
        pre = cur;
        cur = NULL;
        if (p != NULL)
            p = p->next;
        if (q != NULL)
            q = q->next;
    }
    if (c != 0) {
        if (cur == NULL) {
            cur = malloc(sizeof(struct ListNode));
        }
        if (pre != NULL) {
            pre->next = cur;
        }
        cur->val = c;
        cur->next = NULL;
    } 

    return ret;
}

struct ListNode m[6];

int main(void)
{
    struct ListNode *a, *b, *c;
    
    a = &m[0];
    m[0].next = &m[1];
    m[1].next = &m[2];
    m[2].next = NULL;
    m[0].val = 2;
    m[1].val = 4;
    m[2].val = 3;

    b = &m[3];
    m[3].next = &m[4];
    m[4].next = &m[5];
    m[5].next = NULL;
    m[3].val = 5;
    m[4].val = 6;
    m[5].val = 4;

    c = addTwoNumbers(a, b);

    while (c != NULL)
    {
        printf("%d\n", c->val);
        c = c->next;
    }

    return 0;
}
