class MaxQueue {
public:
    queue<int> q1;
    deque<int> q2;
    MaxQueue() {

    }
    
    int max_value() {
        int res = -1;
        if (!q2.empty())
        {
            res = q2.front();
        }
        return res;
    }
    
    void push_back(int value) {
        q1.push(value);
        while (!q2.empty() && q2.back()<value)
        {
            q2.pop_back();
        }
        q2.push_back(value);
    }
    
    int pop_front() {
        int res = -1;
        if (q1.empty()) return res;
        res = q1.front();
        if (res == q2.front())
        {
            q2.pop_front();
        }
        q1.pop();
        return res;
    }
};
