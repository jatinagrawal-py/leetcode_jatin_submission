class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mpp;
        int minele = INT_MAX;

        for(auto it:basket1){
            mpp[it]++;
            minele = min(minele,it);
        }

        for(auto it:basket2){
            mpp[it]--;
            minele = min(minele,it);
        }

        vector<int>hehe ;

        for(auto it:mpp){
            int price = it.first;
            int count = it.second;

            if(count%2==1)return -1;

            for(int i = 0;i<abs(count)/2;i++){
                hehe.push_back(price);
            }
        }

        sort(hehe.begin(),hehe.end());

        long long ans = 0;

        for(int i = 0;i<hehe.size()/2;i++){
            ans+=min(hehe[i],minele*2);
        }

        return ans;

    }
};