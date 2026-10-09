class SeatManager {
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;

public:
    SeatManager(int n) {

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
