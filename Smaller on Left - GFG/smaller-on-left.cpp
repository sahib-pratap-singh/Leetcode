// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{
    set<int> s;
    // insert -1 at the start of set
    s.insert(-1);
    vector<int> ans(n);
    for(int i=0; i < n; i++) {
        // push the element so that we can do .find without any errors
        s.insert(arr[i]); // set will maintain the sorted order of element
        // to .find to find the first index of arr[i]
        // out answer will be element before that because element are in sorted order
        
        // if arr[i] is the only element we have pushed out answer will automatically become -1
        // because initially we pushed -1 in the set.
        auto itr = s.find(arr[i]);
        itr--; // decrement itreator for answer
        ans[i] = (*itr); // value at itrerator itr
    }
    
    return ans;
}