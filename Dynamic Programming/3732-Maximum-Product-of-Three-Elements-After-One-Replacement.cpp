class Solution {
public:
    long long maximumProduct(vector<int>& a) {

        sort(a.begin(),a.end());

        long long M=100000,n=a.size();

        return max({
            M*1LL*a[n-1]*a[n-2],
            M*1LL*a[0]*a[1],
            -M*1LL*a[n-1]*a[0],
            -M*1LL*a[n-1]*a[1],
            -M*1LL*a[0]*a[1]
        });
    }
};
