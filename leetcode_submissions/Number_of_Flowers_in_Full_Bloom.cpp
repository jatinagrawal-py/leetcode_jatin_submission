class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>mpp;
        for(auto it:flowers){
            mpp[it[0]]++;
            mpp[it[1]+1]--;
        }
        int sum = 0;
        for(auto &it:mpp){
            sum+=it.second;
            it.second = sum;
        }
        vector<int>ans;
        for(auto it:people){
            auto ptr = mpp.lower_bound(it);
            if((ptr->first)==it){
                ans.push_back(ptr->second);
            }
            else if(ptr==mpp.begin()){
                ans.push_back(0);
            }
            else{
                ptr--;
                ans.push_back(ptr->second);
            }
        }

        return ans;
    }
};