class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string hehe = to_string(n);
        vector<int>ahhbaby(10,0);

        for(auto it:hehe){
            int i = it - '0';
            ahhbaby[i]++;
        }
        
        int mini = INT_MAX;
        int ch  = 10;
        
        for(int j = 0;j<10;j++){
            if(ahhbaby[j]==0)continue;
            if(mini>ahhbaby[j]){
                mini = ahhbaby[j];
                ch = j;
            }
            else if(ahhbaby[j]==mini && j<ch){
                ch = j;
            }
        }

        return ch;
    }
};