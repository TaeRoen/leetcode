struct ListNode {
    int val;
    struct ListNode *next;
};

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