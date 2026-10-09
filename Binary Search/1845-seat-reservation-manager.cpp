class SeatManager {
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i+

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
