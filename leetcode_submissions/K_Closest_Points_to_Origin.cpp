class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long , pair<int,int>>>hehe;

        for(auto it:points){
            int x = it[0];
            int y = it[1];
            long long he = ((long long)(x*x) + (long long)(y*y)) ;
            hehe.push_back({he,{x,y}});
        }

        sort(begin(hehe),end(hehe));
        int i = 0;
        vector<vector<int>>ans;
        while(k--){
            ans.push_back({hehe[i].second.first,hehe[i].second.second});
            i++;
        }

        return ans;
    }
};