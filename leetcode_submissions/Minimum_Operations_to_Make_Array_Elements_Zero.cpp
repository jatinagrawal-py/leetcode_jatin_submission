class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for(auto it:queries){
           int l = it[0];
           int r = it[1];
            int L = 1;
            int R = 3;
            int s = 1;
            long long temp = 0;
            while(L<=r){
                int start = max(l,L);
                int end  = min(r,R);
                if(start<=end){
                    temp+=((long long)(end-start+1)*s);
                }
                L = (long long)L*4;
                R = ((long long)L*4-1);
                s++;
            }
            temp = (temp+1)/2;
            ans+=temp;
        }

        return ans;
    }
};