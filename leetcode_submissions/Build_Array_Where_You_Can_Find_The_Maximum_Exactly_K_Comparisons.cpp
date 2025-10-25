class Solution {
public:
    int N,M,K;
    int mod = 1e9 + 7;
    int solve(int idx , int search , int prev , vector<vector<vector<int>>>&t){
        if(idx>=N){
            if(search==K)return 1;
            else{
            return 0;
        }
        }
        

        if(t[idx][search][prev]!=-1)return t[idx][search][prev];

        int res = 0;
        for(int i = 1;i<=M;i++){
            if(i>prev){
                res = (res + solve(idx+1,search+1,i,t))%mod;
            }
            else{
                res = (res + solve(idx+1,search,prev,t))%mod;
            }
        }


        return t[idx][search][prev] = res;
    }
    int numOfArrays(int n, int m, int k) {
        // n is like size;
        // m is the maximum element allowed in the array
        // k is the number of search cost
        N = n;
        M = m;
        K = k;
        vector<vector<vector<int>>> t(51, vector<vector<int>>(51, vector<int>(101, -1)));
        return solve(0,0,0,t);




    }
};