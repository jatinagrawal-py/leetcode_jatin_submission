class Solution {
public:
    
    int findidx(int target , vector<vector<int>>& events){
        int l = 0;
        int r = events.size()-1;
        int ans = events.size();

        while(l<=r){
            int mid = l + (r-l)/2;

            if(events[mid][0]<=target){
                l = mid+1;
            }
            else{
                ans = mid;
                r = mid-1;
            }
        }

        return ans;
    }

    int solve(vector<vector<int>>& events, int k , int i , vector<vector<int>>&dp){
        if(k<=0){
            return 0;
        }
        if(i>=events.size()){
            return 0;
        }

        if(dp[i][k]!=-1) return dp[i][k];

        int idx = findidx(events[i][1] , events);
        int take = events[i][2] + solve(events,k-1,idx,dp);
        int nottake = solve(events,k,i+1,dp);

        return dp[i][k]= max(take,nottake);

    }
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        sort(begin(events),end(events));
        return solve(events,k,0,dp);
    }
};