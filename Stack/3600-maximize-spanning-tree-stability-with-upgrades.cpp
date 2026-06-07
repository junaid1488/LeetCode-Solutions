class DSU {
public:
    vector<int> p;
    DSU(int n): p(n) { iota(p.begin(), p.end(), 0); }
    int find(int x){ return p[x]==x ? x : p[x]=find(p[x]); }
    bool unite(int a,int b){
        a=find(a), b=find(b);
        if(a==b) return false;
        p[a]=b;
        return true;
    }
};

class Solution {
public:
    bool ok(int n, vector<vector<int>>& e, int k, int x){
        DSU d(n);
        int comp=n, used=0;
        vector<pair<int,int>> up;

        for(auto &v:e)
            if(v[3]){
                if(v[2]<x || !d.unite(v[0],v[1])) return false;
                comp--;
            }

        for(auto &v:e){
            if(v[3]) continue;
            if(v[2]>=x){
                if(d.unite(v[0],v[1])) comp--;
            } else if(2*v[2]>=x)
                up.push_back({v[0],v[1]});
        }

        for(auto &[u,v]:up)
            if(d.unite(u,v))
                comp--, used++;

        return comp==1 && used<=k;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int l=1,r=200000,ans=-1;
        while(l<=r){
            int m=(l+r)/2;
            if(ok(n,edges,k,m))
                ans=m,l=m+1;
            else
                r=m-1;
        }
        return ans;
    }
};
