class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {

        int n=g.size();
        vector<int> c(n,-1);

        for(int i=0;i<n;i++){

            if(c[i]!=-1) continue;

            queue<int> q;
            q.push(i);
            c[i]=0;

            while(!q.empty()){

                int u=q.front();
                q.pop();

                for(int v:g[u]){

                    if(c[v]==-1)
                        c[v]=c[u]^1,q.push(v);

                    else if(c[v]==c[u])
                        return false;
                }
            }
        }

        return true;
    }
};
