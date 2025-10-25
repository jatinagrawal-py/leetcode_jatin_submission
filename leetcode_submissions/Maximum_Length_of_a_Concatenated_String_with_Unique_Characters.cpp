class Solution {
public:
    bool find(string s){
        vector<int>hehe(26,0);
        for(auto it:s){
            if(hehe[it-'a'])return false;
            hehe[it-'a']++;
        }

        return true;
    }

    int maxi = INT_MIN;

    void solve(vector<string>& arr , int i,string s){
        if(i>=arr.size()){
            if(find(s)){
                maxi = max(maxi,(int)s.size());
            }
            return;
        }

        solve(arr,i+1,s+arr[i]);
        solve(arr,i+1,s);

        return;
    }
    int maxLength(vector<string>& arr) {
        solve(arr,0,"");

        return maxi;
    }
};