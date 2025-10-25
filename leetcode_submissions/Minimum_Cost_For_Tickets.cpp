class Solution {
public:
    int dp[326];
    int solve(vector<int>& days, vector<int>& costs,int i ){
        if(i<0){
            return 0;
        }

        if(dp[i]!=-1)return dp[i];

        int cost1 = costs[0] + solve(days,costs,i-1);

        int maxidays = days[i]-6;

        int j = i;
        while(j>=0 && days[j]>=maxidays){
            j--;
        }

        int cost2 = costs[1] + solve(days,costs,j);

        maxidays = days[i]-29;

        j = i;
        while(j>=0 && days[j]>=maxidays){
            j--;
        }

        int cost3 = costs[2] + solve(days,costs,j);


        return dp[i]= min(cost1,min(cost2,cost3));


    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(days,costs,days.size()-1);
    }
};