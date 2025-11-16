class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next) {

            prev = slow;
            slow = slow->next;

            fast = fast->next->next;
        }
        prev->next = nullptr;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }



    ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* t = &dummy;
        while (a && b) {
            if (a->val < b->val) {
                t->next = a;
                a = a->next;
            } else {
                t->next = b;
                b = b->next;
            }
            t = t->next;
        }
        
        t->next = a ? a : b;
        return dummy.next;
    }
};
