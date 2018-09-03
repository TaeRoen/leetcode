struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    if (!head)
        return head;
    if (!head->next)
        return head;
    struct ListNode *final_res = head->next;

    struct ListNode *worker = head->next->next;
    struct ListNode *prior_node = head;
    struct ListNode *tmp;

    head->next->next = head;
    head->next = NULL;

    while (worker && worker->next)
    {
        tmp = worker->next->next;
        prior_node->next = worker->next;
        prior_node = worker;
        worker->next->next = worker;
        worker = tmp;
    }
    if (worker)
    {
        prior_node->next = worker;
    }
    else
    {
        prior_node->next = NULL;
    }
    return final_res;
}