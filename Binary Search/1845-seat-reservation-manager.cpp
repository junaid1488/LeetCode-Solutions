class SeatManager {
    priority_queue<
        int,
        vector<int>,
        greater<int>
    > pq;


    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
