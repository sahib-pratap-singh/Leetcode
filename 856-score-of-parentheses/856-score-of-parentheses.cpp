class Solution {
public:
    int scoreOfParentheses(string s) {
        int cur=0;
        stack<int> sp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                sp.push(cur);
                cur=0;
            }
            else{
                cur=sp.top()+max(2*cur,1);
                sp.pop();
            }
        }
        return cur;
    }
};