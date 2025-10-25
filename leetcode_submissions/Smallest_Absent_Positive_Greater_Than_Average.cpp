class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        double sum = 0.0;
        for(auto it:nums){
            sum+=it;
        }
        double avg = sum/nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        
        int hehe = floor(avg)+1;

        if(hehe<=0) hehe =1;

        while(true){
            if(st.count(hehe)==0)return hehe;
            hehe++;
        }
        return -1;
    }
};