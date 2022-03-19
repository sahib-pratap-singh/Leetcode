// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int count(string a, string b, int m, int n)
{
    // If both first and second string is empty,
    // or if second string is empty, return 1
    if ((m == 0 && n == 0) || n == 0)
        return 1;
 
    // If only first string is empty and second
    // string is not empty, return 0
    if (m == 0)
        return 0;
 
    // If last characters are same
    // Recur for remaining strings by
    // 1. considering last characters of both strings
    // 2. ignoring last character of first string
    if (a[m - 1] == b[n - 1])
        return count(a, b, m - 1, n - 1) +count(a, b, m - 1, n);
    
    return count(a, b, m - 1, n);
}
    int countWays(string s1, string s2){
        // code here
        return count(s1,s2,s1.length(),s2.length());
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1;
        cin>>S2;
        
        Solution ob;
        cout<<ob.countWays(S1, S2)<<endl;
    }
    return 0;
}  // } Driver Code Ends