class Solution {
public:
    vector<vector<int>> constructGridLayout(
        int n,
        vector<vector<int>>& edges
    ) {

        vector<vector<int>> g(n);

        for(auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> deg(n);

        for(int i=0;i<n;i++)
            deg[i]=g[i].size();

        int start=-1;

        for(int i=0;i<n;i++) {
            if(deg[i]==1) {
                start=i;
                break;
            }
        }

        /*
            PATH GRAPH
        */

        if(start!=-1){

            vector<int> row;
            vector<int> vis(n);

            int prev=-1;
            int cur=start;

            while(true){

                row.push_back(cur);
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

            return {row};
        }

        /*
            REAL GRID
        */

        int corner=-1;

        for(int i=0;i<n;i++){

            if(deg[i]==2){

                corner=i;
                break;
            }
        }

        vector<int> firstRow;
        vector<int> used(n);

        firstRow.push_back(corner);
        used[corner]=1;

        int prev=-1;
        int cur=corner;

        while(true){

            int nxt=-1;

            for(int v:g[cur]){

                if(v==prev) continue;

                if(deg[v]<=3){

                    nxt=v;
                    break;
                }
            }

            if(nxt==-1) break;

            firstRow.push_back(nxt);
            used[nxt]=1;

            prev=cur;
            cur=nxt;

            if(deg[cur]==2)
                break;
        }

        int cols=firstRow.size();
        int rows=n/cols;

        vector<vector<int>> ans(
            rows,
            vector<int>(cols)
        );

        for(int j=0;j<cols;j++)
            ans[0][j]=firstRow[j];

        for(int r=1;r<rows;r++){

            for(int c=0;c<cols;c++){

                int u=ans[r-1][c];

                for(int v:g[u]){

                    if(!used[v]){

                        used[v]=1;
                        ans[r][c]=v;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
