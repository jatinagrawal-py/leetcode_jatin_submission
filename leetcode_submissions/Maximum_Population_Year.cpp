class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>arr(102,0);
        for(auto it:logs){
            arr[it[0]-1950]++;
            arr[it[1]-1950]--;
        }
        int sum = 0;
        for(auto &it:arr){
            sum+=it;
            it = sum;
        }
        int maxi = INT_MIN;
        int ans = -1;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]>maxi){
                maxi = arr[i];
                ans = i+1950;
            }
        }
        return ans;
    }
};