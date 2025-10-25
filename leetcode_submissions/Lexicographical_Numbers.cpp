class Solution {
public:
    vector<int>ans;
    void solve(int n , int i){
        if(i>n){
            return;
        }

        ans.push_back(i);

        for(int j = 0 ;j<=9 ;j++){
            int temp = i*10+j;
            solve(n , temp);
        }
    }
    vector<int> lexicalOrder(int n) {
        for(int i = 1;i<=9;i++){
            solve(n,i);
        }

        return ans;
    }
};