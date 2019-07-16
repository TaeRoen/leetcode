/*
 * @lc app=leetcode id=328 lang=c
 *
 * [328] Odd Even Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode* odd,*oddTail;
    struct ListNode* even,*evenTail;
    if(!head){
        return NULL;
    }
    odd = head;
    oddTail = odd;
    if(!head->next){
        return head;
    }
    even = head->next;
    evenTail = even;
    head = head->next->next;
    bool isOdd = true;
    while(head){
        if(isOdd){
            oddTail->next = head;
            oddTail = oddTail->next;
        }else{
            evenTail->next = head;
            evenTail = evenTail->next;
        }
        isOdd = !isOdd;
        head = head->next;
    }
    oddTail->next = even;
    evenTail->next = NULL;
    return odd;
}



