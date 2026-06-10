class Solution {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {

        vector<vector<int>> g(n);

        for(auto &e : edges){
            int u=e[0];
            int v=e[1];

            g[u].push_back(v);
            g[v].push_back(u);
        }

        bool isCycle = true;

        for(int i=0;i<n;i++){
            if(g[i].size()==1){
                isCycle=false;
                break;
            }
        }

        vector<int> order;

        if(!isCycle){

            int start=0;

            while(g[start].size()!=1)
                start++;

            vector<int> vis(n,0);

            int cur=start;
            int prev=-1;

            while(true){

                order.push_back(cur);
                vis[cur]=1;

                int nxt=-1;

                for(int v:g[cur]){

                    if(v!=prev){
                        nxt=v;
                        break;
                    }
                }

                if(nxt==-1) break;

                prev=cur;
                cur=nxt;
            }
        }
        else{

            vector<int> vis(n,0);

            int cur=0;
            int prev=-1;

            while(true){

                order.push_back(cur);
                vis[cur]=1;

                int nxt=-1;

                for(int v:g[cur]){

                    if(v!=prev && !vis[v]){
                        nxt=v;
                        break;
                    }
                }

                if(nxt==-1) break;

                prev=cur;
                cur=nxt;
            }
        }

        vector<int> perm;

        for(int x=1;x<=n;x+=2)
            perm.push_back(x);

        int startEven =
            (n%2==0 ? n : n-1);

        for(int x=startEven;x>=2;x-=2)
            perm.push_back(x);

        vector<long long> val(n);

        for(int i=0;i<n;i++)
            val[order[i]]=perm[i];

        long long ans=0;

        for(auto &e:edges){

            ans +=
                val[e[0]]
                * val[e[1]];
        }

        return ans;
    }
};
