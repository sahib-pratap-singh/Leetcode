class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string st[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        if(digits.size()==0){
            return {};
        }
        
        for(int i=0;i<digits.size();i++){
            string cur=st[digits[i]-'0'];
            if(result.size()==0){
                for(int k=0;k<cur.size();k++){
                    string s="";
                    s+=cur[k];
                    result.push_back(s);
                }
            }
            else{
                int size=result.size();
                for(int j=0;j<size;j++){
                    string tmp=result[j];
                    for(auto x:cur){
                        result.push_back(tmp+x);
                    }
                }
                for(int j=0;j<size;j++){
                    result.erase(result.begin());;
                }
            }
        }
        return result;
    }
};