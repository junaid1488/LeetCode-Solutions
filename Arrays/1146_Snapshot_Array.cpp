class SnapshotArray {
    vector<vector<pair<int, int>>> updates;
    int curSnap;

public:
    SnapshotArray(int length) {
        updates.resize(length);
        curSnap = 0;
    }
