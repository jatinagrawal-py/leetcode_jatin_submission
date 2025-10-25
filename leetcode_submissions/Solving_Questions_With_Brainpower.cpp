class Solution {
public:
    typedef long long ll;

    ll solve(vector<vector<int>>& questions,int i , vector<ll>&t){
        if( i>=questions.size()){
            return 0;
        }
        if(t[i]!=-1){
            return t[i];
        }
        ll skip = solve(questions,i+1,t);
        ll take = questions[i][0] + solve(questions,i+questions[i][1]+1,t);

        return t[i]= max(take,skip);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        // q 0 se chalu hon raha hai
        vector<ll>t(questions.size(),-1);
        return solve(questions,0,t);
    }
};