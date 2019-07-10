/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.06%)
 * Total Accepted:    552.7K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;
    struct ListNode *res, *worker;
    if (l1->val < l2->val) {
        res = l1;
        l1 = l1->next;
    } else {
        res = l2;
        l2 = l2->next;
    }
    worker = res;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            worker->next = l1;
            worker = worker->next;
            l1 = l1->next;
        } else {
            worker->next = l2;
            worker = worker->next;
            l2 = l2->next;
        }
    }
    if (l1)
        worker->next = l1;
    if (l2)
        worker->next = l2;
    return res;
}

