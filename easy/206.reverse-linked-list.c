/*
 * @lc app=leetcode id=206 lang=c
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (53.01%)
 * Total Accepted:    556.6K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head) {
    if (!head) {
        return 0;
    }
    struct ListNode *tmp;
    struct ListNode *node = head->next;
    struct ListNode *prior_node = head;
    prior_node->next = 0;
    while (node) {
        tmp = node->next;
        node->next = prior_node;
        prior_node = node;
        node = tmp;
    }
    return prior_node;
}
