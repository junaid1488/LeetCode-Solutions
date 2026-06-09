class Solution {
public:
    long long f(vector<int>& a, vector<int>& b){

        long long ans=0;

        for(long long x:a){

            long long t=x*x;
            unordered_map<long long,int> mp;

            for(long long y:b){
                if(t%y==0) ans+=mp[t/y];
                mp[y]++;
            }
        }

        return ans;
    }

    int numTriplets(vector<int>& nums1,
                    vector<int>& nums2) {

        return f(nums1,nums2)+f(nums2,nums1);
    }
};
