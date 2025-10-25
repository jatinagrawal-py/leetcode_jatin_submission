class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> arr(candies.size());
        arr = candies;
        sort(arr.begin(),arr.end());
        int max = arr[candies.size()-1];
        vector<bool> ans(0);
        for(int num : candies){
            if(max<=num+extraCandies){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};