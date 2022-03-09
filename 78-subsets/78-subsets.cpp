class Solution {
public:
    void solve(int s, int n, vector<int>& nums, vector<int> &ans, vector<vector<int>>& result){
        result.push_back(ans);
        for(int i=s;i<n;i++){
            ans.push_back(nums[i]);
            solve(i+1,n,nums,ans,result);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ans;
        solve(0,nums.size(),nums,ans,result);
        return result;
    }
};