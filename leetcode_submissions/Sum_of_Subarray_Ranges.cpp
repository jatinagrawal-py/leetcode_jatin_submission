class Solution {
public:
    long long solvesmaller(vector<int>& nums){
        int n = nums.size();
        vector<int>psee(n,-1);
        vector<int>nse(n,n);

        stack<int>st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            psee[i] = st.empty()?-1:st.top();
            st.push(i);
        }

        st = stack<int>(); 


        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            nse[i] = st.empty()? n : st.top();
            st.push(i);
        }

        long long sum = 0;
         for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long contribution = (left * right) * nums[i];
            sum = (sum + contribution);
        }

        return sum;
    }

    long long solvegreater(vector<int>& nums){
        int n = nums.size();
        vector<int>pgee(n,-1);
        vector<int>nge(n,n);

        stack<int>st;

        for(int i = 0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            pgee[i] = st.empty()?-1:st.top();
            st.push(i);
        }

        st = stack<int>();  


        for(int i = n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            nge[i] = st.empty()? n : st.top();
            st.push(i);
        }

        long long sum = 0;
         for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            long long contribution = (left * right) * nums[i];
            sum = (sum + contribution);
        }

        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return solvegreater(nums)-solvesmaller(nums);
    }
};