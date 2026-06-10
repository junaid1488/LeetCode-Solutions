class Solution {
public:

    long long minimumTime(
        int n,
        vector<vector<int>>& edges) {

        vector<vector<array<long long,3>>> g(n);

        for(auto &e : edges){

            int u = e[0];
            int v = e[1];
            int s = e[2];
            int en = e[3];

            g[u].push_back({v,s,en});
        }

        vector<long long> dist(
            n,
            LLONG_MAX
        );

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){

            auto [t,u] = pq.top();
            pq.pop();

            if(t != dist[u])
                continue;

            if(u == n-1)
                return t;

            for(auto &e : g[u]){

                long long v = e[0];
                long long start = e[1];
                long long end = e[2];

                long long depart =
                    max(t,start);

                if(depart > end)
                    continue;

                long long arrive =
                    depart + 1;

                if(arrive < dist[v]){

                    dist[v] = arrive;

                    pq.push({
                        arrive,
                        (int)v
                    });
                }
            }
        }

        return -1;
    }
};
