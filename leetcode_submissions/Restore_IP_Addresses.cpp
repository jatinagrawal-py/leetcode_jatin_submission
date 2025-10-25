class Solution {
public:
    int n ;
    vector<string> result;

    void solve(string &s,int id , int parts , string cur){
        if(id==n && parts == 4){
            cur.pop_back();
            result.push_back(cur);
            return;
        }
        if(id+1<=n){
            solve(s,id+1,parts+1,cur + s.substr(id,1)+".");
        }

        if(id+2<=n && isvalid(s.substr(id,2))){
            solve(s,id+2,parts+1,cur + s.substr(id,2)+".");
        }

        if(id+3<=n && isvalid(s.substr(id,3))){
            solve(s,id+3,parts+1,cur + s.substr(id,3)+".");
        }
        
    }

    bool isvalid(string st){
        if(st[0] == '0' && st.size() > 1)return false;

        if(stoi(st)<=255)return true;

        return false;
    }

    vector<string> restoreIpAddresses(string s) {
        n = s.size();

        if(n>12)return {};

        int parts = 0;
        string cur = "";
        int id = 0;

        solve(s,id,parts,cur);

        return result;
    }
};