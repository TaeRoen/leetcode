/*
 * @lc app=leetcode id=24 lang=c
 *
 * [24] Swap Nodes in Pairs
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

struct ListNode *swapPairs(struct ListNode *head) {
    if (!head)
        return head;
    if (!head->next)
        return head;

    struct ListNode *res = head->next;
    struct ListNode *prior_node = head;
    struct ListNode *tmp = head->next->next;

    head->next->next = head;
    head = tmp;

    while (head && head->next) {
        tmp = head->next->next;
        prior_node->next = head->next;
        prior_node = head;
        head->next->next = head;
        head = tmp;
    }
    if (head) {
        prior_node->next = head;
    } else {
        prior_node->next = NULL;
    }
    return res;
}
// @lc code=end
