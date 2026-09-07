class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int curSnap;

public:
    SnapshotArray(int length) {
        updates.resize(length);
        curSnap = 0;
    int snap() {
        curSnap++;
        return curSnap - 1;
    }

    int get(int index, int snap_id) {
        int idx = upper_bound(
            updates[index].begin(),
  
        if (idx == 0) return 0;

        return updates[index][idx - 1].second;
    }
};
