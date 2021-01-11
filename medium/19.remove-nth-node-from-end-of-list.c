/*
 * @lc app=leetcode id=19 lang=c
 *
 * [19] Remove Nth Node From End of List
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (!head->next && n == 1) {
        return 0;
    }

    struct ListNode *ret = 0, *tmp = head;
    for (int i = 0; i < n; i++) {
        tmp = tmp->next;
    }

    ret = head;
    if (!tmp) {
        return head->next;
    }
    while (tmp->next) {
        tmp = tmp->next;
        ret = ret->next;
    }

    if (ret->next) {
        ret->next = ret->next->next;
    }
    return head;
}
// @lc code=end
