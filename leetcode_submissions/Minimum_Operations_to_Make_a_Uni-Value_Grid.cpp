class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int row = grid.size();
        int col = grid[0].size();

        //1 - 2 - 4 - 5
        // mleft wala lenge even mai toh 2-> 1+2+3 = 6
        // 3-> right wala le = 3-> 2+1+2 = 5

        vector<int>arr;

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col ; j++){
                arr.push_back(grid[i][j]);
            }
        }

        sort(arr.begin(),arr.end());
        int mid;
        if(arr.size()%2==0){
            mid = arr[arr.size()/2 - 1];
        }
        else{
            mid = arr[arr.size()/2];
        }

        int ans = 0;

        for (auto it : arr) {
            if ((abs(it - mid) % x) != 0) return -1;  // Ensure non-negative modulo
            ans += abs(it - mid) / x;                 // Use division instead of modulo for counting steps
        }


        return ans;
    }
};