class MinStack {
private:
    vector<int> st;
    vector<int> m;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        st.push_back(x);
        if(m.empty()||x<=getMin()) m.push_back(x);
    }
    
    void pop() {
        if(st.back()==m.back()) m.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return m.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */