class Solution {
public:
    int solve(int n , int i , int paste ){
        if(i==n)return 0;
        if(i>n)return 1e8;

        int copy = INT_MAX;
        if(i!=paste){
            copy = 1+solve(n,i,i);
        }
        
        int pastekaro = INT_MAX;
        if(paste>0){
            pastekaro = 1+solve(n,i+paste,paste);
        }

        return min(pastekaro,copy);
    }
    int minSteps(int n) {
        return solve(n,1,0);
    }
};