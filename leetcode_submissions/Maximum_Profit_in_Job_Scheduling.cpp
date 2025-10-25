class Solution {
public:
    int find(vector<vector<int>>&arr , int l , int target){
        int r = arr.size()-1;
        int ans = -1;
        
        while(l<=r){
            int mid = (l+r)/2;

            if(arr[mid][0]>=target){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
    int dp[50001];
    int solve( vector<vector<int>>&arr , int i){
        if(i>=arr.size()){
            return 0;
        }
        
        if(dp[i]!=-1) return dp[i];

        int next = find(arr,i+1,arr[i][1]);
        int take = arr[i][2] + solve(arr,next);
        int nottake = solve(arr,i+1);

        return dp[i]= max(take,nottake);
    }

    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& p) {
        int n = st.size();
        vector<vector<int>>arr;
        memset(dp,-1,sizeof(dp));

        for(int i = 0;i<n;i++){
            vector<int>temp;
            temp.push_back(st[i]);
            temp.push_back(et[i]);
            temp.push_back(p[i]);
            arr.push_back(temp);
        }

        sort(begin(arr),end(arr));

        return solve(arr,0);
    }
};