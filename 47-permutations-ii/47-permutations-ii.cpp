class Solution {
public:
    void findallpermut(int start, int n, vector<int>& nums, vector<int> &permute,vector<int>& chosen,vector<vector<int>> &result){
        if(permute.size()==n){
            result.push_back(permute);
        }
        else{
            for(int i=0;i<n;i++){
                if(chosen[i]){
                    continue;
                }
                if(i>0 and chosen[i-1] and nums[i]==nums[i-1]){
                    continue;
                }
                chosen[i]=1;
                permute.push_back(nums[i]);
                findallpermut(i+1,n,nums,permute,chosen,result);
                chosen[i]=0;
                permute.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> permute;
        int n=nums.size();
        vector<int> chosen(n,0);
        findallpermut(0,n,nums,permute,chosen,result);
        return result;
    }
};