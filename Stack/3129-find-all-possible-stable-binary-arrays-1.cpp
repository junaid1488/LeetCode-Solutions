class Solution {
    int dp[201][201][2], M=1e9+7;

    int f(int z,int o,int t,int l){
        if(!z) return t && o<=l;
        if(!o) return !t && z<=l;

        int &r=dp[z][o][t];
        if(r!=-1) return r;

        long long a=t?
            f(z,o-1,0,l)+f(z,o-1,1,l)
          - (o>l?f(z,o-l-1,0,l):0)
          :
            f(z-1,o,0,l)+f(z-1,o,1,l)
          - (z>l?f(z-l-1,o,1,l):0);

        return r=(a%M+M)%M;
    }

public:
    int numberOfStableArrays(int z,int o,int l) {
        memset(dp,-1,sizeof(dp));
        return (f(z,o,0,l)+f(z,o,1,l))%M;
    }
};
