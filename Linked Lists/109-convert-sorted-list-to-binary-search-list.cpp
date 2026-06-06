/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 * };
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 * };
 */

class Solution {
public:

    TreeNode* buildBST(ListNode* head) {

        if (!head)
            return nullptr;

        if (!head->next)
            return new TreeNode(head->val);

        ListNode* prev = nullptr;
        ListNode* slow = head;
        ListNode* fast = head;

        // Find middle node
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Disconnect left half
        prev->next = nullptr;

        TreeNode* root = new TreeNode(slow->val);

        root->left = buildBST(head);
        root->right = buildBST(slow->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return buildBST(head);
    }
};
