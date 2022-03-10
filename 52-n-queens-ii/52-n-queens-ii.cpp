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
    void findposition(vector<string> &queen, int n, int col, int &ans){
        if(col==n){
            ans++;
        }
        for(int i=0;i<n;i++){
            if(is_safe(queen,i,col,n)){
                queen[i][col]='Q';
                findposition(queen,n,col+1,ans);
                queen[i][col]='.';
            }
        }
        
    }
    int totalNQueens(int n) {
        vector<string> queen(n,string(n,'.'));
        int ans=0;
        findposition(queen,n,0,ans);
        return ans;
    }
};