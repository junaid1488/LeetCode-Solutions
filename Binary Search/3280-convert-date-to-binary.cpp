class Solution {
    string bin(int x){
        string s;

        while(x){
            s += (x & 1) + '0';
            x >>= 1;
        }

        reverse(s.begin(), s.end());
        return s.empty() ? "0" : s;
    }

public:
    string convertDateToBinary(string date) {
        return bin(stoi(date.substr(0,4))) + "-" +
               bin(stoi(date.substr(5,2))) + "-" +
               bin(stoi(date.substr(8,2)));
    }
};
