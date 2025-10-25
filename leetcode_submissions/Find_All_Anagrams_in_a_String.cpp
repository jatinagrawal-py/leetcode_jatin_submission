class Solution {
public:
    bool allzeroes(unordered_map<char,int>&mpp){
        for(auto it:mpp){
            if(it.second!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mpp;

        for(auto it:p){
            mpp[it]++;
        }
        int n = s.size();
        vector<int>ans;
        int k = p.size();
        int j = 0, i = 0;
        while(j<n){
            mpp[s[j]]--;

            if((j-i+1)==k){
                if(allzeroes(mpp)){
                    ans.push_back(i);
                }
                mpp[s[i]]++;
                i++;
            }
            j++;
        }

        return ans;
    }
};