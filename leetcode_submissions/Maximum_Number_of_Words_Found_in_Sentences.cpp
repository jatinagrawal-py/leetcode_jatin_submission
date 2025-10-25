class Solution {
public:
    int mostWordsFound(vector<string>& sent) {
        int n = sent.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int m = sent[i].size();
            int temp=0;
            for(int j=0;j<m;j++){
                if(int(sent[i][j])==32){
                    temp = temp +1;
                }
            }
            temp = temp +1;
            if(temp>ans){
                ans = temp;
            }
        }
        return ans;
    }
};