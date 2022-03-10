class Solution {
public:
    bool isvalid(vector<vector<char>>& board, int i, int j, char x){
        for(int q=0;q<board[0].size();q++){
            if((board[i][q])==x){
                return false;
            }
        }
        for(int q=0;q<board.size();q++){
            if((board[q][j])==x){
                return false;
            }
        }
        int r=(i/3)*3;
        int c=(j/3)*3;
        for(int e=0;e<3;e++){
            for(int t=0;t<3;t++){
                if(board[e+r][t+c]==x){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int i, int j) {
        if(i==board.size()-1 and j==board.size()){
            return true;
        }
        if(j==board[0].size()){
            i++;
            j=0;
        }
        if(board[i][j] != '.'){
            return solve(board,i,j+1);
        }else{
            for(char x='1';x<='9';x++){
                if(isvalid(board,i,j,x)){
                    board[i][j]=x;
                    if(solve(board,i,j+1)){
                        return true;
                    }
                    board[i][j]='.';
                }
                
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};