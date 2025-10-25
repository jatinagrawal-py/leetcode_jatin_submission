class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        int i = 1;
        while(n>0){
            int rem = n%10;
            if(rem!=0){
                ans.push_back(rem*i);
            }
            i = (long long)i*10;
            n /=10;
        }
        reverse(begin(ans),end(ans));

        return ans;
    }
};