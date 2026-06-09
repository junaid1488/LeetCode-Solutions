class Solution {
public:
    int maxProduct(vector<int>& a, int k, int lim) {

        unordered_map<long long,int> dp, ndp;

        for(int x:a){

            ndp=dp;

            if(x<=lim)
                ndp[((long long)x<<1)|1]=
                max(ndp[((long long)x<<1)|1],x);

            for(auto &[s,p]:dp){

                long long np=1LL*p*x;
                if(np>lim) continue;

                int par=s&1,sum=s>>1;
                long long ns=((long long)(par?sum-x:sum+x)<<1)|(par^1);

                ndp[ns]=max(ndp[ns],(int)np);
            }

            dp.swap(ndp);
        }

        int ans=-1;

        for(auto &[s,p]:dp)
            if((int)(s>>1)==k)
                ans=max(ans,p);

        return ans;
    }
};
