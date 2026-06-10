class Solution {
public:

    long long dijkstra(
        int n,
        vector<vector<int>>& edges,
        int source,
        int destination) {

        vector<vector<pair<int,int>>> g(n);

        for(auto &e : edges){

            if(e[2] == -1)
                continue;

            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[source] = 0;
        pq.push({0, source});

        while(!pq.empty()){

            auto [d,u] = pq.top();
            pq.pop();

            if(d != dist[u])
                continue;

            for(auto &[v,w] : g[u]){

                if(dist[v] > d + w){

                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist[destination];
    }

    vector<vector<int>> modifiedGraphEdges(
        int n,
        vector<vector<int>>& edges,
        int source,
        int destination,
        int target) {

        long long d =
            dijkstra(
                n,
                edges,
                source,
                destination
            );

        if(d < target)
            return {};

        bool matched = (d == target);

        for(auto &e : edges){

            if(e[2] != -1)
                continue;

            if(matched){

                e[2] = 2000000000;
                continue;
            }

            e[2] = 1;

            long long cur =
                dijkstra(
                    n,
                    edges,
                    source,
                    destination
                );

            if(cur <= target){

                matched = true;

                e[2] +=
                    (target - cur);
            }
        }

        if(!matched)
            return {};

        for(auto &e : edges){

            if(e[2] == -1)
                e[2] = 2000000000;
        }

        long long finalDist =
            dijkstra(
                n,
                edges,
                source,
                destination
            );

        if(finalDist != target)
            return {};

        return edges;
    }
};
