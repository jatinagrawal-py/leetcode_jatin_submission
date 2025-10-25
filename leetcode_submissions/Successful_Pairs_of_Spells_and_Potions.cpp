class Solution {
public:
    int solve(int x , vector<int>& potions, long long success){
        int l = 0;
        int r = potions.size()-1;
        int ans = potions.size();
        while(l<=r){
            int mid = (l+r)/2;
            long long hehe = (long long)x*potions[mid];
            if(hehe>=success){
                ans=mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int>ans(n,0);
        sort(potions.begin(),potions.end());
        for(int i = 0;i<n;i++){
            ans[i] = m - solve(spells[i],potions,success);
        }
        return ans;
    }
};