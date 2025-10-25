class Solution {
public:
    int val = 0;
    void solve(int row , int col , int size , vector<vector<int>>&ans ){
        if(size==1){
            ans[row][col] = val;
            val++;
            return;
        }

        int subsize = size/2;
        
        solve(row,col+subsize,subsize,ans);
        solve(row+subsize,col+subsize,subsize,ans);
        solve(row+subsize,col,subsize,ans);
        solve(row,col,subsize,ans);

        return;
    }
    
    vector<vector<int>> specialGrid(int n) {
        if(n==0){
            return {{0}};
        }

        int size = 1;
        for(int i = 1;i<=n;i++){
            size = size*2;
        }
        
        vector<vector<int>>ans(size,vector<int>(size,-1));
        solve(0,0,size,ans);
       
        return ans;
        
    }
};