struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (!head->next && n == 1) {
        return 0;
    }

    struct ListNode *ret = 0, *tmp = head;
    for (int i = 0; i < n; i++) {
        tmp = tmp->next;
    }

    ret = head;
    if(!tmp){
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