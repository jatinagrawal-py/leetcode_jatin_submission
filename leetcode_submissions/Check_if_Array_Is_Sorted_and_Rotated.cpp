class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> ori = nums;
        sort(ori.begin(),ori.end());
        vector<int> b = ori;
        
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j =0;j<n;j++){
                if(ori[j]==nums[(j+i)%(ori.size())]){
                    count++;
                }
            }
            if(count == n){
                return true;
            }
        }
        return false;
    }
};