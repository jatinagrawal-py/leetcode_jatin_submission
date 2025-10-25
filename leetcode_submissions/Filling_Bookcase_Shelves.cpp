class Solution {
public:
    int dp[1001];
    int solve(vector<vector<int>>& books, int w , int i){
        if(i>=books.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi = 0;
        int addw = 0;
        int res = INT_MAX;
        for(int j = i;j<books.size() ; j++){
            maxi = max(maxi,books[j][1]);
            addw+=books[j][0];
            if(addw<=w){
                res = min(res,maxi+solve(books,w,j+1));
            }
            else break;
        }

        return dp[i]= res;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp,-1,sizeof(dp));
        return solve(books,shelfWidth,0);
    }
};