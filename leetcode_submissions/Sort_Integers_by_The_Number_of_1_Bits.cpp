class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        priority_queue<pair<int, int>>pq;
        for(auto it:arr){
            pq.push({__builtin_popcount(it),it});
        }

        for(int i = 0;i<arr.size();i++){
           arr[i] = pq.top().second;
           pq.pop(); 
        }

        reverse(arr.begin(),arr.end());

        return arr;
    }
};