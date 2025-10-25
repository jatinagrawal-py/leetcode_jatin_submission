class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        
        for(int i = 1;i<strs.size();i++){
            string temp = "";
            for(int j = 0;j<min(ans.size(),strs[i].size());j++){
                if(strs[i][j]==ans[j]){
                    temp+=ans[j];
                }
                else break;
            }
            if(temp=="")return temp;
            ans = temp;
        }
        return ans;
    }
};