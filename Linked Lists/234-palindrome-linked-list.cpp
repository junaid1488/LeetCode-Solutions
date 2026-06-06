class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> nums;

        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }

        int i = 0, j = nums.size() - 1;

        while (i < j) {
            if (nums[i] != nums[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};
