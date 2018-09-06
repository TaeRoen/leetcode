struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int numA = 0, numB = 0;
    struct ListNode *tmpA, *tmpB;
    tmpA = headA;
    while (tmpA) {
        numA++;
        tmpA = tmpA->next;
    }
    tmpB = headB;
    while (tmpB) {
        numB++;
        tmpB = tmpB->next;
    }
    if (tmpA == tmpB) {
        tmpA = headA;
        tmpB = headB;
        int differ = 0;
        if (numA > numB) {
            differ = numA - numB;
            for (int i = 0; i < differ; i++) {
                tmpA = tmpA->next;
            }
        } else {
            differ = numB - numA;
            for (int i = 0; i < differ; i++) {
                tmpB = tmpB->next;
            }
        }
        while(tmpA != tmpB){
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        return tmpA;
    }
    return NULL;
}