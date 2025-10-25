class Solution {
public:
    void solve(int i , vector<vector<int>>&ans , vector<int>&temp , vector<int>&arr , int k , int n){
        if(i>=arr.size()){
            if(n==0 && k==0){
                ans.push_back(temp);
            }
            return;
        }
        if(arr[i]<=n){
            temp.push_back(arr[i]);
            solve(i+1,ans,temp,arr,k-1,n-arr[i]);
            temp.pop_back();
        }

        solve(i+1,ans,temp,arr,k,n);

        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        // 1 number 1 hi bar and k numbers hi use kar sakte hai + they should add to n;
        vector<int>arr = {1,2,3,4,5,6,7,8,9};

        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,ans,temp,arr,k,n);

        return ans;
    }
};