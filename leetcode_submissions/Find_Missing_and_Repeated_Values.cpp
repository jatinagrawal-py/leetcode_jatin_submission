class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans ;

        //a-> 2 bar ata hai
        // b -> missing 

        // matsum-sum = a-b;
        // bit manipulation -> a^b;
        int b ;
        int a;
        int n = grid.size();

        int le = n*n;

        int sum = le*(le+1)/2;

        int matsum = 0;
        unordered_map<int,int> mp;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                matsum+=grid[i][j];
                mp[grid[i][j]]++;
            }
        }

        for(auto it : mp){
            if(it.second ==2) a = it.first;
        }

        b = a - matsum + sum;
        ans.push_back(a);
        ans.push_back(b);

        return ans;       

    }
};