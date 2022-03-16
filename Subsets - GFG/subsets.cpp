// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(int s,vector<int>& a,vector<int>& v,vector<vector<int>>& ans){
        //if(v.size()>0)
        ans.push_back(v);
        
        for(int i=s;i<a.size();i++){
            v.push_back(a[i]);
            solve(i+1,a,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int>& a)
    {
        vector<int> q;
        q.push_back(a[0]);
        for(int i=1;i<a.size();){
            while(a[i]==a[i-1]){
                i++;
            }
            if(i<a.size()){
                q.push_back(a[i]);
            }
            i++;
        }
        //sort(q.begin(),q.end());
        //vector<int> q(s.begin(),s.end());
        vector<int> v;
        vector<vector<int>> ans;
        solve(0,a,v,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}  // } Driver Code Ends