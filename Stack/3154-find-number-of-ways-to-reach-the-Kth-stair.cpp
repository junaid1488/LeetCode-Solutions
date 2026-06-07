class Solution {
    map<tuple<long long,int,int>,int> dp;

    int f(long long p,int j,int d,int k){
        if(p>k+1) return 0;

        auto t=make_tuple(p,j,d);
        if(dp.count(t)) return dp[t];

        int ans=(p==k);

        if(d&&p) ans+=f(p-1,j,0,k);
        ans+=f(p+(1LL<<j),j+1,1,k);

        return dp[t]=ans;
    }

public:
    int waysToReachStair(int k) {
        return f(1,0,1,k);
    }
};
