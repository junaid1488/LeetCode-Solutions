class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        // Create a dummy node before head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;

        // Traverse the list
        while (curr->next) {

            // If next node contains target value
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
