class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int len = strs[0].size();
        int m = strs.size();
        int count = 0;
        for(int i = 0;i<len;i++){
            string temp = "";
            for(int j = 0;j<m;j++){
                temp += strs[j][i];
            }
            string temp2 = temp;
            sort(temp2.begin(),temp2.end());
            if(temp!=temp2)count++;
        }

        return count;
    }
};