class Solution {
public:
    int solve(int i , int n , int l){
        if (i == 2) {
            return (n >= 0 && n <= l) ? 1 : 0;
        }
        int sum = 0;
        for(int j = 0;j<=l;j++){
            sum+=solve(i+1,n-j,l);
        }
        return sum;
    }
    
    int distributeCandies(int n, int limit) {
        return solve(0 , n , limit);
    }
};