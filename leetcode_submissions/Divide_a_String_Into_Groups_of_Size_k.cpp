class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;

        int i = 0;
        string hehe = "";

        while(i<s.size()){
            hehe+=s[i];
            i++;
            if(i%k==0){
                ans.push_back(hehe);
                hehe = "";
            }
        }

        if(hehe.size()>0 && hehe.size()!=k){
            for(int j = hehe.size();j<k;j++){
                hehe+=fill;
            }
            ans.push_back(hehe);
        }


        return ans;
        
    }
};