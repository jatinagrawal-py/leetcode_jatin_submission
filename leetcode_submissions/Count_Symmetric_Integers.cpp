class Solution {
public:
    bool solve(string s){
        int n = s.size();
        int sum  =0;

        for(int i = 0;i<n;i++){
            if(i<n/2){
                sum = sum + (s[i]-'0');
            }
            else{
                sum = sum - (s[i]-'0');
            }
        }

        if(sum==0)return true;

        return false;
        
    }

    int countSymmetricIntegers(int low, int high) {
        
        int ans  = 0;

        for(int i = low ; i<=high ; i++){
            string s = to_string(i);
            if(s.size()%2==1){
                continue;
            }
            else{
                if(solve(s)){
                    ans++;
                }
            }
        }

        return ans;
    }
};