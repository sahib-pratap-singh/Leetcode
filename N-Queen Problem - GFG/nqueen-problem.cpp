// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
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
    void findposition(vector<string> &queen, int n, int col, vector<vector<int>> &ans){
        if(col==n){
            vector<int> v;
            for(int i=n-1;i>=0;i--){
                for(int j=0;j<n;j++){
                    if(queen[i][j]=='Q')
                        v.push_back(j+1);
                }
            }
            ans.push_back(v);
        }
        for(int i=0;i<n;i++){
            if(is_safe(queen,i,col,n)){
                queen[i][col]='Q';
                findposition(queen,n,col+1,ans);
                queen[i][col]='.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<string> queen(n,string(n,'.'));
        findposition(queen,n,0,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends