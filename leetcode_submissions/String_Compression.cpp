class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int j = 1;
        int count =1;
        char ele = chars[0];

        for(int i = 1;i<chars.size();i++){
            if(ele==chars[i]){
                count++;
            }
            else{
                ans+=1;
                int si = 0;
                if(count>1){
                    si = log10(count)+1;
                    ans+=si;
                    string temp = to_string(count);
                    for(auto it:temp){
                        chars[j]=it;
                        j++;
                    }
                }
                ele = chars[i];
                count = 1;
                chars[j] = ele;
                j++;
            }
        }
        ans+=1;
                int si = 0;
                if(count>1){
                    si = log10(count)+1;
                    ans+=si;
                    string temp = to_string(count);
                    for(auto it:temp){
                        chars[j]=it;
                        j++;
                    }
                }

        return ans;
    }
};