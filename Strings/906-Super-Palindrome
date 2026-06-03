class Solution {
public:
    bool isPalindrome(long long x) {
        string s = to_string(x);
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    int superpalindromesInRange(string left, string right) {
        long long L = stoll(left);
        long long R = stoll(right);

        int count = 0;

        // Generate odd-length palindromes
        for (int k = 1; k < 100000; k++) {
            string s = to_string(k);
            string rs = s;
            reverse(rs.begin(), rs.end());

            string pal = s + rs.substr(1);
            long long root = stoll(pal);
            long long square = root * root;

            if (square > R) break;

            if (square >= L && isPalindrome(square))
                count++;
        }

        // Generate even-length palindromes
        for (int k = 1; k < 100000; k++) {
            string s = to_string(k);
            string rs = s;
            reverse(rs.begin(), rs.end());

            string pal = s + rs;
            long long root = stoll(pal);
            long long square = root * root;

            if (square > R) break;

            if (square >= L && isPalindrome(square))
                count++;
        }

        return count;
    }
};
