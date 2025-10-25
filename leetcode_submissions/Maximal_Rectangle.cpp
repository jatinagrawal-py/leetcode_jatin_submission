class Solution {
public:
    int solve(vector<int>histo){
        stack < int > st;
        int maxA = 0;
        int n = histo.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>>psum(row,vector<int>(col,0));

        for(int j = 0;j<col;j++){
            int sum = 0;
            for(int i = 0;i<row;i++){
                sum+=(matrix[i][j] - '0');
                if(matrix[i][j]=='0')sum=0;
                psum[i][j] = sum;
            }
        }

        int ans = 0;

        for(int i = 0;i<row;i++){
            ans = max(ans,solve(psum[i]));
        }


        return ans;
    }
};