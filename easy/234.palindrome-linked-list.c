/*
 * @lc app=leetcode id=234 lang=c
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.41%)
 * Total Accepted:    246.6K
 * Total Submissions: 690.4K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *invert(struct ListNode *l) {
    struct ListNode *tmp;
    struct ListNode *node = l->next;
    struct ListNode *prior_node = l;
    prior_node->next = NULL;
    while (node) {
        tmp = node->next;
        node->next = prior_node;
        prior_node = node;
        node = tmp;
    }
    return prior_node;
}

bool isPalindrome(struct ListNode *head) {
    if (!head || !head->next) {
        return true;
    }
    struct ListNode *fast = head, *slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    struct ListNode *tail = slow->next, *pre = head;
    if (tail->next) {
        tail = invert(tail);
    }
    while (pre && tail) {
        if (pre->val != tail->val) {
            return false;
        } else {
            pre = pre->next;
            tail = tail->next;
        }
    }
    return true;
}

