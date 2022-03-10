class Solution {
public:
    bool is_safe(vector<string> &queen, int r, int c, int n){
        for(int i=0;i<c;i++){
            if(queen[r][i]=='Q'){
                return false;
            }
        }
        for(int i=r,j=c;i>=0 && j>=0 ; i--,j--){
            if(queen[i][j]=='Q'){
                return false;
            }
        }
        for(int i=r,j=c;i<n && j>=0 ; i++,j--){
            if(queen[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    void findposition(vector<string> &queen, int n, int col, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(queen);
        }
        for(int i=0;i<n;i++){
            if(is_safe(queen,i,col,n)){
                queen[i][col]='Q';
                findposition(queen,n,col+1,ans);
                queen[i][col]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> queen(n,string(n,'.'));
        findposition(queen,n,0,ans);
        return ans;
    }
};