class Solution {
public:
    bool isPalindrome(long long num) {
        long long original = num, rev = 0;

        while (num) {
            rev = rev * 10 + num % 10;
            num /= 10;
        }

        return original == rev;
    }

    long long createPalindrome(long long num, bool odd) {
        long long pal = num;

        if (odd) num /= 10;

        while (num) {
            pal = pal * 10 + num % 10;
            num /= 10;
        }

        return pal;
    }

    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left);
        long long R = stoll(right);

        int count = 0;

        for (long long i = 1; i < 100000; i++) {

            // Odd length palindrome root
            long long root = createPalindrome(i, true);
            long long sq = root * root;

            if (sq <= R && sq >= L && isPalindrome(sq))
                count++;

            // Even length palindrome root
            root = createPalindrome(i, false);
            sq = root * root;

            if (sq <= R && sq >= L && isPalindrome(sq))
                count++;
        }

        return count;
    }
};
