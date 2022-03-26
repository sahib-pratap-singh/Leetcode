class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[n-1]=1;
        for(int i=n-1;i>=0;i--){
            int lastPos=min(i+nums[i],n-1);
            for(int j=i+1;j<=lastPos;j++){
                if(dp[j]==1){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};