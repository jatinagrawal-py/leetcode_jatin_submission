class Solution {
public:
    int minimumPushes(string words) {
        int n = words.size();
        if (n == 0) return 0;  // Handle empty string case

        int ans = 0;

        unordered_map<int,int>mpp;

        int idx = 2;

        for(auto it:words){
            if(idx>9)idx=2;
            mpp[idx]++;
            ans+=mpp[idx];
            idx++;
        }
        return ans;
    }
};
