class Solution {
public:
    void solve(vector<string>&arr , vector<string>&ans , string &temp , string &digits , int i){
        if(i>=digits.size()){
            if(temp.empty())return;
            ans.push_back(temp);
            return;
        }

        int dig = digits[i]-'0';
        for(auto it:arr[dig-2]){
            temp.push_back(it);
            solve(arr,ans,temp,digits,i+1);
            temp.pop_back();
        }

        return;
    }

    vector<string> letterCombinations(string digits) {
        vector<string>arr = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>ans;
        string temp;
        solve(arr,ans,temp,digits,0);
        return ans;
    }
};