public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode invertListNode(ListNode l) {
        if (l.next == null) {
            return l;
        } else {
            ListNode res = invertListNode(l.next);
            res.next = l;
            return res;
        }
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(0);
        if (l1.next == null && l2.next == null) {
            return res;
        }

        return res;
    }
}