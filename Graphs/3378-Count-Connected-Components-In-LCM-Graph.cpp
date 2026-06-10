class Solution {
public:

    vector<int> parent, sz;

    int find(int x){
        return parent[x] == x
            ? x
            : parent[x] = find(parent[x]);
    }

    void unite(int a,int b){

        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b])
            swap(a,b);

        parent[b] = a;
        sz[a] += sz[b];
    }

    int countComponents(vector<int>& nums,
                        int threshold) {

        int n = nums.size();

        parent.resize(threshold + 1);
        sz.assign(threshold + 1,1);

        for(int i=0;i<=threshold;i++)
            parent[i]=i;

        vector<int> present(
            threshold + 1,
            0
        );

        int big = 0;

        for(int x:nums){

            if(x > threshold)
                big++;
            else
                present[x] = 1;
        }

        for(int g=1; g<=threshold; g++){

            vector<int> vals;

            for(int mult=g;
                mult<=threshold;
                mult+=g){

                if(present[mult])
                    vals.push_back(mult);
            }

            int m = vals.size();

            for(int i=0;i<m;i++){

                for(int j=i+1;j<m;j++){

                    long long l =
                        1LL * vals[i]
                        / gcd(vals[i],vals[j])
                        * vals[j];

                    if(l <= threshold)
                        unite(vals[i],vals[j]);
                }
            }
        }

        unordered_set<int> comps;

        for(int x:nums){

            if(x <= threshold)
                comps.insert(find(x));
        }

        return (int)comps.size() + big;
    }
};
