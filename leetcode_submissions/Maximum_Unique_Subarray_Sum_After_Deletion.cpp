class Solution {
public:
    int maxSum(vector<int>& nums) {        
        int sum = 0;
        int maxi = INT_MIN;
        unordered_set<int>st;
        for(auto it:nums){

            if(it>0){
                if(st.find(it)==st.end()){
                    sum+=it;
                    st.insert(it);
                }
            }
            else maxi = max(maxi,it);
        }

        return sum==0?maxi:sum;
    }
};