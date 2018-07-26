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

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    l1 = invert(l1);
    l2 = invert(l2);
    while (l1->val == 0 && l1->next) {
        l1 = l1->next;
    }
    while (l2->val == 0 && l2->next) {
        l2 = l2->next;
    }
    struct ListNode *n1 = invert(l1);
    struct ListNode *n2 = invert(l2);
    struct ListNode *ret = NULL;
    struct ListNode *tail = NULL;
    int bit = 0;
    while (n1 && n2) {
        int sum = n1->val + n2->val + bit;
        if (sum < 10) {
            bit = 0;
        } else {
            bit = 1;
            sum = sum - 10;
        }
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = sum;
        tmp->next = NULL;
        if (ret == NULL) {
            ret = tmp;
            tail = tmp;
        } else {
            tail->next = tmp;
            tail = tmp;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    if (n2) {
        n1 = n2;
    }
    while (n1) {
        int sum = n1->val + bit;
        if (sum < 10) {
            bit = 0;
        } else {
            bit = 1;
            sum = sum - 10;
        }
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = sum;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
        n1 = n1->next;
    }
    if (bit == 1) {
        struct ListNode *tmp = (struct ListNode *)malloc(sizeof(struct ListNode));
        tmp->val = 1;
        tmp->next = NULL;
        tail->next = tmp;
    }
    return ret;
}