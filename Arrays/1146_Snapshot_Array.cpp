class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int curSnap;

public:
    void set(int index, int val) {
        if (!updates[index].empty() && updates[index].back().first == curSnap)
            updates[index].back().second = val;
        else
            updates[index].push_back({curSnap, val});
