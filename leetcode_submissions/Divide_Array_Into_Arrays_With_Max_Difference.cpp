class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = 0;
        vector<vector<int>>ans;
        vector<int>temp;

       
        while(j<nums.size()){
            temp.push_back(nums[j]);
            if(j-i+1==3){
                if((nums[j]-nums[i])<=k){
                    ans.push_back(temp);
                    temp.clear();
                }
                else{
                    return {};
                }
                i = j+1;
            }
            j++;
        }

        return ans;
        
    }
};