class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        // nums/i - i != nums/j - j
        vector<int>hehe;
        for(int i = 0;i<nums.size();i++){
            hehe.push_back((nums[i]-i));
        }
        unordered_map<int,int>mpp;
        long long count =0;
        for(int i = 0;i<nums.size();i++){
            if(mpp.find(hehe[i])!=mpp.end()){
                count+=(i-mpp[hehe[i]]);
                mpp[hehe[i]]++;
            }
            else{
                count+=i;
                mpp[hehe[i]]++;
            }
        }

        return count;
    }
};