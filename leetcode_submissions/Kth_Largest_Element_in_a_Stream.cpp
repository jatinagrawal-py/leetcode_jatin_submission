class KthLargest {
public:
    int k;

    priority_queue<int,vector<int>,greater<int>>pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto it:nums){
            if(pq.size()<k)pq.push(it);
            else{
                if(pq.top()<it){
                    pq.pop();
                    pq.push(it);
                }
            }
        }
    }
    
    int add(int it) {
        if(pq.size()<k)pq.push(it);
            else{
                if(pq.top()<it){
                    pq.pop();
                    pq.push(it);
                }
            }
              return pq.top();
    }
  
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */