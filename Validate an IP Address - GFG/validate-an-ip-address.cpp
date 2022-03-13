// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            int n=s.length();
            if(n>15||n<7){
                return 0;
            }
            int cnt=0;
            string str="";
            for(int i=0;i<n;i++){
                if(s[i]=='.'){
                    if(str.length()==0 || str.length()>3){
                        return 0;
                    }
                    for(int k=0;k<str.length();k++){
                        if(!isdigit(str[k])){
                            return 0;
                        }
                    }
                    int val=stoi(str);
                    
                    string cmp=to_string(val);
                    if(cmp.length()!=str.length()){
                        return 0;
                    }
                    if(val>=0 and val<=255){
                        cnt++;
                    }
                    else{
                        return 0;
                    }
                    str="";
                }
                else
                    str+=s[i];
            }
            if(str.length()==0 || str.length()>3){
                return 0;
            }
            int val=stoi(str);
            string cmp=to_string(val);
            if(cmp.length()!=str.length()){
                return 0;
            }
            if(cnt!=3){
                return 0;
            }
            return 1;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends