struct ListNode {
    int val;
    struct ListNode *next;
};

struct Tupple {
    struct ListNode *head;
    struct ListNode *tail;
};

struct Tupple binarySortList(struct ListNode *head) {
    struct Tupple res;
    if (!head) {
        res.head = 0;
        res.tail = 0;
        return res;
    }
    if (!head->next) {
        res.head = head;
        res.tail = head;
        return res;
    }
    struct ListNode *big_head = 0, *big_tail = 0, *small_head = 0, *small_tail = 0, *tmp = head->next;
    head->next = 0;
    while (tmp) {
        if (tmp->val > head->val) {
            if (!big_head) {
                big_head = tmp;
            } else {
                big_tail->next = tmp;
            }
            big_tail = tmp;
        } else {
            if (!small_head) {
                small_head = tmp;
            } else {
                small_tail->next = tmp;
            }
            small_tail = tmp;
        }
        tmp = tmp->next;
    }
    if (big_tail) {
        big_tail->next = 0;
        struct Tupple tupple = binarySortList(big_head);
        big_head = tupple.head;
        big_tail = tupple.tail;
    }
    if (small_tail) {
        small_tail->next = 0;
        struct Tupple tupple = binarySortList(small_head);
        small_head = tupple.head;
        small_tail = tupple.tail;
    }
    if (small_head) {
        res.head = small_head;
        small_tail->next = head;
    } else {
        res.head = head;
    }
    if (big_head) {
        head->next = big_head;
        res.tail = big_tail;
    } else {
        head->next = 0;
        res.tail = head;
    }
    return res;
}

struct ListNode *sortList(struct ListNode *head) {
    struct Tupple tupple = binarySortList(head);
    return tupple.head;
}