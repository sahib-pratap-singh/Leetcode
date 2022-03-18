//Will use greddy approach
//While iterating i will check if element at i greater than i+1
//and i is duplicated then we can remove element i

//Time complexity: O(N)
//Space complexity: O(N)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //Frequency of each character
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        vector<int> visited(26,0);
        string ans="";
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']--;
            if(!visited[s[i]-'a']){
                while(ans.length()>0 && ans.back()>s[i] && count[ans.back()-'a']>0){
                    visited[ans.back()-'a']=0;
                    ans.pop_back();
                }
                ans+=s[i];
                visited[s[i]-'a']=1;
            }
        }
        return ans;
    }
};