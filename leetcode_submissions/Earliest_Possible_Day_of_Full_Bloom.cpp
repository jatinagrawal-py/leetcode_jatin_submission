class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        int n = gt.size();
        vector<pair<int,int>>hehe(n);
        for(int i = 0;i<n;i++){
            hehe[i] ={gt[i],pt[i]};
        }
        sort(hehe.begin(),hehe.end());
        reverse(hehe.begin(),hehe.end());
        int maxdays = 0;
        int prev = 0;
        for(auto it:hehe){
            int grow = it.first;
            int plant = it.second;
            maxdays = max(maxdays,prev+1+grow+plant);
            prev = plant+prev;
        }

        return maxdays-1;
    }
};