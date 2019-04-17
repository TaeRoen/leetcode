struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *insertionSortList(struct ListNode *head) {
    if (!head) {
        return 0;
    }
    struct ListNode *ret = head;
    head = head->next;
    ret->next = 0;

    while (head) {
        struct ListNode *current = head, *tmp = ret;
        head = head->next;
        if (ret->val > current->val) {
            current->next = ret;
            ret = current;
            continue;
        }

        current->next = 0;
        while (tmp->next) {
            if (tmp->next->val > current->val) {
                current->next = tmp->next;
                tmp->next = current;
                break;
            }
            tmp = tmp->next;
        }
        if (!current->next) {
            tmp->next = current;
            current->next = 0;
        }
    }
    return ret;
}