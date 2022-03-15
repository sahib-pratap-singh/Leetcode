class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                cnt++;
            else if(s[i]==')'){
                if(cnt==0){
                    s[i]='$';
                }
                else{
                    cnt--;
                }
            }
        }
        
        cnt=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')')
                cnt++;
            else if(s[i]=='('){
                if(cnt==0){
                    s[i]='$';
                }
                else{
                    cnt--;
                }
            }
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='$')
                ans+=s[i];
        }
        return ans;
    }
};