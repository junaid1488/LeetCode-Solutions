
class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int curSnap;

public:
  

            updates[index].push_back({curSnap, val});
    }

    int get(int index, int snap_id) {
        int idx = upper_bound(
            updates[index].begin(),
            updates[index].end(),
            make_pair(snap_id, INT_MAX)
    
    }
};
