// { Driver Code Starts
// C++ program to calculate sum of all numbers present
// in a string containing alphanumeric characters
#include <iostream>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to calculate sum of all numbers present in a string.
    int findSum(string str)
    {
    	
    	int sum=0;
    	int i=0;
    	int n=str.length();
    	while(i<n){
    	    string s="";
    	    while(i<n and isdigit(str[i])){
    	        s+=str[i];
    	        i++;
    	    }
    	    if(s.empty()){
    	        i++;
    	    }
    	    else{
    	        sum+=stoi(s);
    	    }
    	}
    	return sum;
    }
};

// { Driver Code Starts.

// Driver code
int main()
{
	// input alphanumeric string
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution obj;
	    cout << obj.findSum(str);
        cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends