class Solution {
public:
    vector<vector<int>>ans;
    void solve(int n , int k , int took , vector<int>&temp , int prev){
        if(took==k){
            ans.push_back(temp);
            return;
        }
        for(int i = prev+1;i<=n;i++){
            temp.push_back(i);
            solve(n,k,took+1,temp,i);
            temp.pop_back();
        }

        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(n,k,0,temp,0);
        return ans;
    }
};