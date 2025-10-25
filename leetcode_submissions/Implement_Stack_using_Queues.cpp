class MyStack {
private:
    queue<int>q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q1.size()==0)q1.push(x);
        else{
            
            int n = q1.size();
            q1.push(x);
            for(int i= 0;i<n;i++){
                q1.push(q1.front());
                q1.pop();
            }
        }
    }
    
    int pop() {
        int t = q1.front();
        q1.pop();
        return t;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */