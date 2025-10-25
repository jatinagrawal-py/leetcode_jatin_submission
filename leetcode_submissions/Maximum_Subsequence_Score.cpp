class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n = nums1.size();

        vector<pair<int,int>>mp;

        for(int i = 0;i<n;i++){
            mp.push_back({nums2[i],nums1[i]});
        }

        sort(mp.begin(),mp.end());
        reverse(mp.begin(),mp.end());
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum  = 0;

        for(int i = 0;i<k;i++){
            pq.push(mp[i].second);
            sum+=mp[i].second;
        }

        long long res = (long long)sum*mp[k-1].first;

        for(int i = k;i<n;i++){
            sum +=mp[i].second - pq.top();
            pq.pop();
            pq.push(mp[i].second);

            res = max(res,(long long)sum*mp[i].first);
        }


        return res;
    }
};