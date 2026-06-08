class MyCircularQueue {
private:
    vector<int> q;
    int front, rear, count, capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = 0;
        rear = 0;
        count = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;

        q[rear] = value;
        rear = (rear + 1) % capacity;
        count++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        front = (front + 1) % capacity;
        count--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return q[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return q[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

