class Solution {
public:
    unordered_map<int,char> mp;
    void isValid(string s) {
        stack<pair<char,int>> st;
        int i=-1;
        for(auto x:s){
            i++;
            if(x=='(')
                st.push({x,i});
            
            else if(x==')'){
                if(st.empty())
                    continue;
                
                if(st.top().first=='(' and x!=')')
                    continue;
                
                else{
                    mp[st.top().second]=st.top().first;
                    mp[i]=x;
                    st.pop();
                }
            }
            //i++;
        }
    }
    string minRemoveToMakeValid(string s) {
        string ans="";
        isValid(s);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]==')'){
                if(mp.count(i))
                    ans+=s[i];
            }
            else
                ans+=s[i];
        }
        return ans;
    }
};