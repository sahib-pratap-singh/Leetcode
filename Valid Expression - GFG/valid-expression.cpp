// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}// } Driver Code Ends


bool valid(string s)
{
    stack<char> st;
        for(auto x:s){
            if(x=='(' or x=='[' or x=='{')
                st.push(x);
            
            else if(x==')' or x==']' or x=='}'){
                if(st.empty())
                    return false;
                
                if(st.top()=='(' and x!=')')
                    return false;
                
                if(st.top()=='[' and x!=']')
                    return false;
                
                if(st.top()=='{' and x!='}')
                    return false;
                
                st.pop();
            }
        }
        return st.empty()?true:false;
}