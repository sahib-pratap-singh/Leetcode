// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    int dp[101][101][201];
    bool solve(int i,int j,int k,string temp,string &s1,string &s2,string &s3){
        if(i == s1.length() and j == s2.length() and k == s3.length()) 
            return temp == s3;
        else if(dp[i][j][k] != -1) 
            return dp[i][j][k];
        
        bool op1 = false,op2 = false;
        
        if(i < s1.size() and s1[i] == s3[k]) op1 = solve(i+1,j,k+1,temp + s1[i],s1,s2,s3);
        
        if(j < s2.size() and s2[j] == s3[k]) op2 = solve(i,j+1,k+1,temp + s2[j],s1,s2,s3);
        
        bool res = op1 or op2;
        return dp[i][j][k] = res;
    } 
    
    bool isInterleave(string s1, string s2, string s3){
        int n1 = s1.size(),n2=s2.size(),n3=s3.size();
        if(n1 + n2 != n3) return false;
        memset(dp,-1,sizeof dp);
        return solve(0,0,0,"",s1,s2,s3);
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}  // } Driver Code Ends