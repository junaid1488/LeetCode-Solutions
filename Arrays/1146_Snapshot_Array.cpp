class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int curSnap;

public:
    SnapshotArray(int length) {
        updates.resize(length);
        curSnap = 0;
    }



        if (idx == 0) return 0;

        return updates[index][idx - 1].second;
    }
};
