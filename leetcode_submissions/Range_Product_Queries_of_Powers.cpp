class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>power;
        int mod = 1e9+7;

        for(int i= 0;i<32;i++){
            if(n&(1<<i)){
                power.push_back((1<<i));
            }
        }

        vector<int>ans;

        for(auto it:queries){
            int i = it[0];
            int j = it[1];
            long long hehe = 1;
            for(int k = i;k<=j;k++){
                hehe = (hehe*power[k])%mod;
            }
            ans.push_back((int)hehe);
        }

        return ans;
    }
};