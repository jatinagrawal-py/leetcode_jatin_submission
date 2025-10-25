class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int l = 0;
        int r = 0;
        int count = 0;

        while(i<=r){
            if(r>=nums.size()-1)return count;
            int farthest = INT_MIN;
            for(int j = i ;j<=r;j++){
                farthest = max(farthest,j+nums[j]);
            }
            l = r;
            r = farthest;
            i = l;
            count++;
        }

        return -1;
    }
};