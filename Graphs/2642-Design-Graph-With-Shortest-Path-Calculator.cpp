class Graph {
public:

    const int INF = 1e9;

    vector<vector<int>> dist;
    int n;

    Graph(int n, vector<vector<int>>& edges) {

        this->n = n;

        dist.assign(n, vector<int>(n, INF));

        for(int i=0;i<n;i++)
            dist[i][i]=0;

        for(auto &e:edges){

            int u=e[0];
            int v=e[1];
            int w=e[2];

            dist[u][v]=min(dist[u][v],w);
        }

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(dist[i][k] < INF &&
                       dist[k][j] < INF)
                        dist[i][j]=min(
                            dist[i][j],
                            dist[i][k]+dist[k][j]
                        );
    }

    void addEdge(vector<int> edge) {

        int u=edge[0];
        int v=edge[1];
        int w=edge[2];

        if(w >= dist[u][v])
            return;

        dist[u][v]=w;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                if(dist[i][u] == INF ||
                   dist[v][j] == INF)
                    continue;

                dist[i][j]=min(
                    dist[i][j],
                    dist[i][u]
                    + w
                    + dist[v][j]
                );
            }
        }
    }

    int shortestPath(int node1,
                     int node2) {

        return dist[node1][node2] == INF
            ? -1
            : dist[node1][node2];
    }
};
