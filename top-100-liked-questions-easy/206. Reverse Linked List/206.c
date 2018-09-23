struct ListNode {
    int val;
    struct ListNode *next;
};
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