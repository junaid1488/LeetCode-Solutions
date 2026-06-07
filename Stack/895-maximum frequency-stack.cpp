class FreqStack {
    unordered_map<int,int> cnt;
    unordered_map<int,stack<int>> st;
    int mx = 0;

public:
    void push(int x) {
        mx = max(mx, ++cnt[x]);
        st[cnt[x]].push(x);
    }

    int pop() {
        int x = st[mx].top();
        st[mx].pop();

        if(--cnt[x], st[mx].empty())
            mx--;

        return x;
    }
};
