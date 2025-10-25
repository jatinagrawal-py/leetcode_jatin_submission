class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int k = -1;
        if(ruleKey=="type"){
            k =0;
        }
        if(ruleKey=="color"){
            k =1;
        }
        if(ruleKey=="name"){
            k =2;
        }
        int ans = 0;
        for(int i =0;i<items.size();i++){
            if(items[i][k]==ruleValue){
                ans++;
            }
        }
        return ans;
    }
};