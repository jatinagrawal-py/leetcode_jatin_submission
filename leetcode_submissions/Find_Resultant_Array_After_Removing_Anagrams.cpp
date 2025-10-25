class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        for(int i = 1;i<words.size();i++){
            string temp1 = ans.back();
            string temp2 = words[i];
            sort(temp1.begin(),temp1.end());
            sort(temp2.begin(),temp2.end());
            if(temp1==temp2){
                continue;
            }
            else{
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};