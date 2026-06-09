class Solution {
public:
    long long cnt(long long n){
        long long res=0;
        for(int b=0;b<60;b++)
            res += (n>>(b+1))*(1LL<<b)
                 + max(0LL,(n&( (1LL<<(b+1))-1 ))-(1LL<<b)+1);
        return res;
    }

    long long sumPos(long long n){
        long long res=0;
        for(int b=0;b<60;b++){
            long long ones=
                (n>>(b+1))*(1LL<<b)
                + max(0LL,(n&((1LL<<(b+1))-1))
                          -(1LL<<b)+1);
            res += ones*b;
        }
        return res;
    }

    long long prefix(long long k){

        long long lo=1,hi=1e15, num=1;

        while(lo<=hi){
            long long mid=(lo+hi)/2;

            if(cnt(mid)<k)
                lo=mid+1;
            else{
                num=mid;
                hi=mid-1;
            }
        }

        long long res=sumPos(num-1);

        long long need=k-cnt(num-1);

        for(int b=0;b<60 && need;b++)
            if(num>>b & 1){
                res+=b;
                need--;
            }

        return res;
    }

    long long modPow(long long a,long long b,long long mod){
        long long r=1;
        while(b){
            if(b&1) r=r*a%mod;
            a=a*a%mod;
            b>>=1;
        }
        return r;
    }

    vector<int> findProductsOfElements(
        vector<vector<long long>>& queries) {

        vector<int> ans;

        for(auto &q:queries){

            long long l=q[0];
            long long r=q[1];
            long long mod=q[2];

            long long expo=
                prefix(r+1)-prefix(l);

            ans.push_back(
                modPow(2,expo,mod)
            );
        }

        return ans;
    }
};
