class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int ans =0;
        for(int i =0;i<n;i++){
            char a = details[i][11];
            char b = details[i][12];
            if((a=='7'||a=='8'||a=='9')||(a=='6'&&b!='0')){
                ans++;
            }
        }
        return ans;
    }
};