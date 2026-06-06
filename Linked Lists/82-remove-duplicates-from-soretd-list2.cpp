class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr) {

            // Duplicate group found
            if (curr->next &&
                curr->val == curr->next->val) {

                int duplicateValue = curr->val;

                // Skip all duplicates
                while (curr &&
                       curr->val == duplicateValue) {
                    curr = curr->next;
                }

                prev->next = curr;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
