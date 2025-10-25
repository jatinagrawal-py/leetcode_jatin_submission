class Solution {
public:
    int solve(vector<int>& nums , vector<bool>& visited , int ops , unordered_map< vector<bool> , int>&mp){

        if(mp.find(visited)!=mp.end()){
            return mp[visited];
        }

        int maxiscore = 0;
        for(int i = 0;i<=nums.size()-2;i++){
            if(visited[i]==true)continue;
            for(int j = i+1;j<nums.size();j++){
                if(visited[j])continue;
                visited[i] = true;
                visited[j] = true;
                int score = ops*__gcd(nums[i],nums[j]);
                int remainings = solve(nums,visited,ops+1,mp);
                visited[i] = false;
                visited[j] = false;
                maxiscore = max(maxiscore , score+remainings);
            }
        }

        return mp[visited]= maxiscore;
    }
    int maxScore(vector<int>& nums) {

        unordered_map< vector<bool> , int>mp;
        int n = nums.size()-1;
        vector<bool>visited(n,false);
        return solve(nums,visited,1,mp);
        
    }
};