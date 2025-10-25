class MinStack {
public:
    stack<int>st;
    map<int,int>mpp;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        mpp[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        mpp[val]--;
        if(mpp[val]==0){
            mpp.erase(val);
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mpp.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */