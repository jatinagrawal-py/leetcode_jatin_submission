class Solution {
public:
    vector<string> ans;

    void solve(string& num, int target, string path, long cursum, long prev, int i) {
        if (i == num.size()) {
            if (cursum == target) {
                ans.push_back(path);
            }
            return;
        }

        string curStr = "";
        for (int j = i; j < num.size(); j++) {
       
            if (j != i && num[i] == '0') break;

            curStr += num[j];
            long curNum = stol(curStr);

            if (i == 0) {
              
                solve(num, target, curStr, curNum, curNum, j + 1);
            } else {
                solve(num, target, path + "+" + curStr, cursum + curNum, curNum, j + 1);
                solve(num, target, path + "-" + curStr, cursum - curNum, -curNum, j + 1);
                solve(num, target, path + "*" + curStr, cursum - prev + prev * curNum, prev * curNum, j + 1);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        ans.clear();
        solve(num, target, "", 0, 0, 0);
        return ans;
    }
};
