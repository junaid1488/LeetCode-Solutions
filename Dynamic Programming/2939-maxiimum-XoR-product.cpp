class Solution {
public:
    int maximumXorProduct(long long a,long long b,int n) {

        const long long MOD=1e9+7;

        for(int i=n-1;i>=0;i--){

            long long bit=1LL<<i;

            if(((a>>i)&1)==((b>>i)&1))
                a|=bit,b|=bit;

            else if(a<b){
                if(!(a&bit)) a^=bit,b^=bit;
            }
            else{
                if(!(b&bit)) a^=bit,b^=bit;
            }
        }

        return (a%MOD)*(b%MOD)%MOD;
    }
};
