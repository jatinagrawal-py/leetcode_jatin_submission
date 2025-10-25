class StockSpanner {
public:
    vector<int>arr;
    stack<int>st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int i = arr.size()-1;
        while(!st.empty() && arr[i]>=arr[st.top()]){
            st.pop();
        }
        int ele = st.empty()?-1:st.top();

        st.push(i);

        return i-ele;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */