class Solution {
public:
    vector<vector<string>>ans;
    int t[17][17];
    void solve(string &s , int i , vector<string>&par){
        if(i==s.size()){
            ans.push_back(par);
        }

        for(int j= i;j<s.size();j++){
            if(t[i][j]){
                par.push_back(s.substr(i,j-i+1));
                solve(s,j+1,par);
                par.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        memset(t,0,sizeof(t));
        for(int l = 1 ; l<=s.size();l++){
            for(int i = 0;i+l-1<s.size();i++){
                int j = i+l-1;
                if(i==j)t[i][j]=true;

                else if(i+1==j){
                    if(s[i]==s[j])t[i][j]=true;
                }

                else{
                    if(s[i]==s[j] && t[i+1][j-1])t[i][j]=true;
                }
            }
        }

        vector<string>temp;
        solve(s,0,temp);


        return ans;
    }
};