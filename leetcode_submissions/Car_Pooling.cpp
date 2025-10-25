class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>arr(1002,0);
        for(auto it:trips){
            arr[it[1]]+=it[0];
            arr[it[2]]-=it[0];
        }
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>capacity)return false;
            arr[i] = sum;
        }
        return true;
    }
};