class DinnerPlates {
    int cap;
    vector<stack<int>> st;
    priority_queue<int, vector<int>, greater<int>> avail;

public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }

    void push(int val) {

        while(!avail.empty() &&
              avail.top() < st.size() &&
              st[avail.top()].size() == cap)
            avail.pop();

        if(avail.empty()) {
            st.push_back(stack<int>());
            st.back().push(val);

            if(cap > 1)
                avail.push(st.size() - 1);
        }
        else {
            int i = avail.top();

            st[i].push(val);

            if(st[i].size() == cap)
                avail.pop();
        }
    }

    int popAtStack(int index) {

        if(index >= st.size() || st[index].empty())
            return -1;

        int val = st[index].top();
        st[index].pop();

        avail.push(index);

        return val;
    }

    int pop() {

        while(!st.empty() && st.back().empty())
            st.pop_back();

        if(st.empty())
            return -1;

        int val = st.back().top();
        st.back().pop();

        avail.push(st.size() - 1);

        while(!st.empty() && st.back().empty())
            st.pop_back();

        return val;
    }
};  
