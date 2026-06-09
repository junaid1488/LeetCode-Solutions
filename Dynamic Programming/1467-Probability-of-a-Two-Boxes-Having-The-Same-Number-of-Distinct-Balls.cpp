class Solution {
    vector<double> f;
    double good=0, tot=0;
    int n;

    void dfs(int i, vector<int>& b,
             int a,int c,int d1,int d2,double w){

        if(i==b.size()){
            if(a!=n || c!=n) return;
            tot+=w;
            if(d1==d2) good+=w;
            return;
        }

        for(int x=0;x<=b[i];x++){
            int y=b[i]-x;

            if(a+x>n || c+y>n) continue;

            dfs(i+1,b,
                a+x,c+y,
                d1+(x>0),
                d2+(y>0),
                w*f[b[i]]/f[x]/f[y]);
        }
    }

public:
    double getProbability(vector<int>& balls) {

        int s=accumulate(balls.begin(),balls.end(),0);
        n=s/2;

        f.assign(s+1,1);
        for(int i=1;i<=s;i++) f[i]=f[i-1]*i;

        dfs(0,balls,0,0,0,0,1);

        return good/tot;
    }
};
