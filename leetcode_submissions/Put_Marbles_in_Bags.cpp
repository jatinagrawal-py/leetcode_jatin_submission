class Solution {
public:
    typedef long long ll;
    long long putMarbles(vector<int>& weights, int k) {
        // max-> max weights lene padenge 
        // min -> min weights lene padenge 
        // jo bhi hoga subarray ,mai hoga
        // k partition karne hai'
        // i and j can be same -> agar same hai toh do bar add karna hai

        vector<int>pair;
        for(int i = 0;i<weights.size()-1;i++){
            pair.push_back((weights[i]+weights[i+1]));
        }

        sort(pair.begin(),pair.end());

        ll maxi = 0;
        ll mini = 0;
        int n = pair.size();
        for(int i = 0;i<k-1;i++){
            maxi+=pair[n-1-i];
            mini +=pair[i];
        }
        ll ans = maxi-mini;
        return ans;
    }
};