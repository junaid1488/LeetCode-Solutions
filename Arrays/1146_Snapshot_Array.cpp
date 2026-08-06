class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int curSnap;


  
    

        if (idx == 0) return 0;

        return updates[index][idx - 1].second;
    }
};
