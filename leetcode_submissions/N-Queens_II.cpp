class Solution {
public:
int solve( unordered_set<int>&dl ,unordered_set<int>&dr,unordered_set<int>&ud , int i , int n){
    if(i>=n)return 1;
    int count = 0;
    for(int j = 0;j<n;j++){
        if(dl.count(i-j)==0 && dr.count(i+j)==0 && ud.count(j)==0){
            dl.insert(i-j);
            dr.insert(i+j);
            ud.insert(j);
            count+=solve(dl,dr,ud,i+1,n);
            dl.erase(i-j);
            dr.erase(i+j);
            ud.erase(j);
        }
    }
    return count;
}
    int totalNQueens(int n) {
        unordered_set<int>dl,dr,ud;
        return solve(dl,dr,ud,0,n);
    }
};