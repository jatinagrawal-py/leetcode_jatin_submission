class Solution {
public:
    int maxProduct(int n) {
        vector<int>hehe;

        while(n>0){
            int hi = n%10;
            n = n/10;
            hehe.push_back(hi);
        }

        sort(hehe.begin(),hehe.end());
        int h = hehe.size();
        return hehe[h-1]*hehe[h-2];
        
    }
};