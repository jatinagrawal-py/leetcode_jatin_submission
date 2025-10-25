class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)return {0};
        vector<int>ans;
        if(n%2==0){
            int key = -1;
            for(int i = 0;i<n/2;i++){
                ans.push_back(key);
                key--;
            }
            key = 1;
            for(int i = n/2;i<n;i++){
                ans.push_back(key);
                key++;
            }
            return ans;
        }
        int key = -1;
        for(int i = 0;i<n/2;i++){
            ans.push_back(key);
            key--;
        }
        ans.push_back(0);
        key=1;
        for(int i = n/2+1;i<n;i++){
            ans.push_back(key);
            key++;
        }

        return ans;
        
    }
};