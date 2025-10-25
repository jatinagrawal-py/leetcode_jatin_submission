class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>>pq;
        vector<int>t;
        for(int i = 0;i<nums.size();i++){
            t.push_back(nums[i]);
        }
        int res = t[0];
        pq.push({t[0],0});

        for(int i = 1;i<nums.size();i++){
            while(!pq.empty() && (i-pq.top().second)>k)pq.pop();

            t[i] = max(t[i],t[i]+pq.top().first);
            pq.push({t[i],i});
            res = max(t[i],res);
        }

        return res;
    }
};