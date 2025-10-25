class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>arr(26,0);
        for(auto it:magazine){
            arr[it-'a']++;
        }

        for(auto it:ransomNote){
            arr[it-'a']--;
            if(arr[it-'a']<0)return false;
        }

        return true;
    }
};