class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans(gain.size()+1);
        ans[0]=0;
        int sum =0;
        for(int i =0;i<gain.size();i++){
            ans[i+1]= sum + gain[i];
            sum = sum + gain[i];
        }
        return *(max_element(ans.begin(),ans.end()));
    }
};