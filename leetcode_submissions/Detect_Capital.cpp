class Solution {
public:
    bool detectCapitalUse(string word) {
        int left = 0;
        int right = 0;
        int n = word.size();

        if(int(word[0]<96))left = 1;

        for(int i = 1;i<n;i++){
            if(int(word[i])<96) right++;
        }

        if(left==1 && right == n-1)return true;
        if(left==0 && right == 0)return true;
        if(left ==1 && right ==0) return true;

        return false;
        
    }
};