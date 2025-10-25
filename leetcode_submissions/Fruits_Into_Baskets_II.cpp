class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int cnt = 0;
        vector<int>isplaced(n,0);

        for(int i  = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isplaced[j]==1)continue;
                if(fruits[i]<=baskets[j]){
                    isplaced[j]=1;
                    cnt++;
                    break;
                }
            }
        }

        return n-cnt;
    }
};