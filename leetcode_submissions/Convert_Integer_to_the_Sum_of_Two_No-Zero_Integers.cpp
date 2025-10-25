class Solution {
public:
    bool find(int n){
        string temp = to_string(n);
        for(auto it:temp){
            if(it-'0'==0){
                return false;
            }
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1;i<n;i++){
           if(find(i) && find(n-i)){
                return {i,n-i};
           }
        }
        return {};
    }
};