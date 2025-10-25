class Solution {
public:
    int n , m;
    vector<vector<long long>>dp;
    long long solve(vector<int>& robot , vector<int>& newfactory , int i , int j){
        if(i>=robot.size())return 0;
        if(j>=newfactory.size() && i< robot.size())return 1e18;

        if(dp[i][j]!=-1) return dp[i][j];

        long long take = abs(robot[i]-newfactory[j]) + solve(robot,newfactory,i+1,j+1);
        long long nottake =  solve(robot,newfactory,i,j+1);

        return dp[i][j]= min(take,nottake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int>newfactory;
        for(auto it:factory){
            for(int i = 0;i<it[1];i++){
                newfactory.push_back(it[0]);
            }
        }
        m = newfactory.size();
        n = robot.size();
        dp.assign(n+1,vector<long long>(m+1,-1));
        return solve(robot,newfactory,0,0);
    }
};