struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode *fast, *slow;
    if (head && head->next && head->next->next) {
        fast = head->next->next;
        slow = head->next;
    } else {
        return false;
    }
    while (fast && fast->next && fast->next->next && slow && slow->next) {
        if (slow == fast) {
            return true;
        } else {
            fast = fast->next->next;
            slow = slow->next;
        }
    }
    return false;
}