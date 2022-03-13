// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int open, int close, string s, vector<string> &v){
        if(open==0 && close==0)
            v.push_back(s);
        if(open!=0){
            string op1=s;
            op1+='(';
            solve(open-1,close,op1,v);
        }
        if(close>open){
            string op2=s;
            op2+=')';
            solve(open,close-1,op2,v);
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        vector<string> v;
        string s="";
        solve(n,n,s,v);
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends