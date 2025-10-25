class Solution {
public:
    int maxDifference(string s) {
        // max difference -> a1 ki freq jyada a2 ki freq kam

        vector<int>arr(26,0);
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(auto it:s){
            arr[it-'a']++;
        }

        for(auto it:arr){
            if(it%2==0 && it!=0){
                mini = min(mini,it);
            }
            else if(it!=0 && it%2==1){
                maxi = max(maxi , it);
            }
        }

        return maxi-mini;
    }
};