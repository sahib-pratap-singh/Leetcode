class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int result=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
                if(!st.empty()){
                    result=max(result,i-st.top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return result;
    }
};