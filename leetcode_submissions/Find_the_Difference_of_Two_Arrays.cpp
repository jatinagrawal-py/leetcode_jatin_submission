class Solution {
public:
    vector<int> anss(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,bool>mpp;
        vector<int>ans;
        for(auto it:nums1){
            mpp[it]=true;
        }

        for(auto it:nums2){
            if(mpp.find(it)!=mpp.end()){
                mpp[it]=false;
            }
        }

        for(auto it:mpp){
            if(it.second==true){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans;
        ans.push_back(anss(nums1,nums2));
        ans.push_back(anss(nums2,nums1));

        return ans;
    }
};