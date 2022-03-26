// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
        int find(vector<int> v){
            int s=0;
            int e=v.size()-1;
            int ans=-1;
            while(s<=e){
                int mid=s+(e-s)/2;
                if(v[mid]==1){
                    ans=mid;
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }
            }
            return ans;
        }
        int maxOnes (vector <vector <int>> &mat, int n, int m)
        {
            int ans=0;
            int index;
            for(int i=0;i<n;i++){
                int val=find(mat[i]);
                if(val==-1){
                    val=m;
                }
                if((m-val)>ans){
                    ans=m-val;
                    index=i;
                }
            }
            return index;
        }
};

// { Driver Code Starts.

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        Solution ob;        
        cout << ob.maxOnes(arr, n, m) << endl;
    }
}  // } Driver Code Ends