class Solution {
public:
    bool check(int i){
        string ahh = to_string(i);
        vector<int>freq(10,0);
        for(auto it:ahh)freq[it-'0']++;
        
        for(int i = 0;i<10;i++){
            if(freq[i]>0 && freq[i]!=i)return false;
        }

        return true;
    }
    int nextBeautifulNumber(int n) {
        // 100 
        // 122

        // 113
        // 12

        // 211 212
        // 

        for(int i = n+1;i<=1224444;i++){
            if(check(i)){
                return i;
            }
        }

        return -1;
    }
};