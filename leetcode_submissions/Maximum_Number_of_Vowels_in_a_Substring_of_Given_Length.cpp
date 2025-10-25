class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char>st{'a','e','i','o','u'};
        int count = 0;
        int i = 0;
        int j = 0;
        int n = s.size();
        int ans = INT_MIN;
        while(j<n){
            if(st.find(s[j])!=st.end()){
                count++;
            }
            if(j-i+1==k){
                ans = max(ans , count);
                if(st.find(s[i])!=st.end()){
                    count--;
                }
                i++;
            }
            j++;
        }
        if(ans==INT_MIN)return 0;
        return ans;
    }
};