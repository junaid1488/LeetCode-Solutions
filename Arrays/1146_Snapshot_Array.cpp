class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int curSnap;

public:
    SnapshotArray(int length) 

    int get(int index, int snap_id) {
        int idx = upper_bound(
            updates[index].begin(),
  
        if (idx == 0) return 0;

        return updates[index][idx - 1].second;
    }
};
