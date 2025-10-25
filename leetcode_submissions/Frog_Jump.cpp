class Solution {
public:
    unordered_map<string,int>dp;

    bool solve(vector<int>& stones , int i , int prev){
        if(i==stones.size()-1)return true;

        string key = to_string(i)+"_"+to_string(prev);
        if(dp.find(key)!=dp.end())return dp[key]; 

        int stone1 = stones[i]+prev-1;
        int stone2 = stones[i]+prev;
        int stone3 = stones[i]+prev+1;
        int res = false;

        for(int j = i+1;j<stones.size();j++){
            if(stones[j]==stone3){
                res = res || solve(stones,j,prev+1);
            }
            else if(stones[j]==stone2){
                res = res || solve(stones,j,prev);
            }
            else if(stones[j]==stone1){
                res = res || solve(stones,j,prev-1);            
            }
        }

        return dp[key]= res;

    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return false;
        if(stones.size()==2)return true;

        return solve(stones,1,1);
    }
};