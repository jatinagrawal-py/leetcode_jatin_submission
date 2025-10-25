class Solution {
public:
    bool isPrefixAndSuffix(string str1, string str2){

        if(str1.size()>str2.size())return false;
        int n = str1.size();
        int k = str2.size();
        string prefix = str2.substr(0,n);
        string sufix = str2.substr(k-n,k);
        if(prefix==str1 && sufix == str1) return true;
        return false;

    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i = 0;i<words.size()-1;i++){
            for(int j = i+1;j<words.size();j++){
                if(isPrefixAndSuffix(words[i],words[j])==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};