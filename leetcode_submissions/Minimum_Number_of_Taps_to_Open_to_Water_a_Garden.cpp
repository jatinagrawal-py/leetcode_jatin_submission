class Solution {
public:
    map<pair<int,int>,int>dp;
    int solve(int n, vector<pair<int,int>>& ranges , int i , int maxend){
        if(i>=ranges.size()){
            if(maxend>=n)return 0;
            return 1e9;
        }

        if(ranges[i].first>maxend)return 1e9;

        if(dp.find({i,maxend})!=dp.end())return dp[{i,maxend}];
        
        int take = 1+ solve(n,ranges,i+1,max(maxend,ranges[i].second));
        int nottake = solve(n,ranges,i+1,maxend);

        return dp[{i,maxend}]= min(take,nottake);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>range;

        for(int i = 0;i<ranges.size();i++){
            range.push_back({max(0,(i-ranges[i])) , (i+ranges[i]) });
        }

        sort(range.begin(),range.end());

        int ans = solve(n,range,0,0);

        if(ans>=1e9)return -1;

        return ans;
    }
};