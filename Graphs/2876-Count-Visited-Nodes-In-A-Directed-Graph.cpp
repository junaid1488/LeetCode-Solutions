class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {

        int n = edges.size();

        vector<int> indeg(n,0);

        for(int v : edges)
            indeg[v]++;

        queue<int> q;

        for(int i=0;i<n;i++)
            if(indeg[i]==0)
                q.push(i);

        vector<int> order;

        while(!q.empty()){

            int u=q.front();
            q.pop();

            order.push_back(u);

            int v=edges[u];

            if(--indeg[v]==0)
                q.push(v);
        }

        vector<int> ans(n,0);
        vector<int> vis(n,0);

        for(int i=0;i<n;i++){

            if(indeg[i]>0 && !vis[i]){

                int cur=i;
                int len=0;

                do{
                    vis[cur]=1;
                    len++;
                    cur=edges[cur];
                }while(cur!=i);

                cur=i;

                do{
                    ans[cur]=len;
                    cur=edges[cur];
                }while(cur!=i);
            }
        }

        for(int i=(int)order.size()-1;i>=0;i--){

            int u=order[i];

            ans[u]=ans[edges[u]]+1;
        }

        return ans;
    }
};
