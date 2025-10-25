class Solution {
public:

    bool issafe(int row , int col , int num , vector<vector<char>>& board){

        for(int i = 0;i<9;i++){
            if(board[i][col]==(num+'0')){
                return false;
            }
            if(board[row][i]==(num+'0')){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==(num+'0')){
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                if(board[i][j]=='.'){

                    for(int k = 1;k<=9;k++){
                        if(issafe(i,j,k,board)){
                            board[i][j]=k+'0';

                            if(solve(board)){
                                return true;
                            }
                            
                            
                                board[i][j] = '.';
                                
                            
                        }

                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};