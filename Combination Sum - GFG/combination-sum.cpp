// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    void solve(int s, int &sum,vector<int>& cand, vector<int> &ans,vector<vector<int>> &result, int t){
        if(sum>=t){
            if(sum==t){
                result.push_back(ans);
            }
            return;
        }
        for(int i=s;i<cand.size();i++){
            sum+=cand[i];
            ans.push_back(cand[i]);
            solve(i,sum,cand,ans,result,t);
            ans.pop_back();
            sum-=cand[i];
        }
    }
    vector<vector<int> > combinationSum(vector<int> &cand, int t) {
        vector<int> ans;
        vector<vector<int>> result;
        int sum=0;
        sort(cand.begin(),cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        solve(0,sum,cand,ans,result,t);
        //sort(result.begin(),result.end());
        return result;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends