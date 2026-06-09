class Solution {
public:
    int maxProductDifference(vector<int>& a) {

        int mx1=0,mx2=0,mn1=INT_MAX,mn2=INT_MAX;

        for(int x:a){
            if(x>mx1) mx2=mx1,mx1=x;
            else if(x>mx2) mx2=x;

            if(x<mn1) mn2=mn1,mn1=x;
            else if(x<mn2) mn2=x;
        }

        return mx1*mx2 - mn1*mn2;
    }
};
