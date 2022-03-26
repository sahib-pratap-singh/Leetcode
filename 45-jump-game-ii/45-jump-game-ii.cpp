class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1001);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int lastPos=min(i+nums[i],n-1);
            for(int j=i+1;j<=lastPos;j++){
                if(j==i+1){
                    dp[i]=dp[j]+1;
                }
                dp[i]=min(dp[i],dp[j]+1);
            }
            
        }
        return dp[0];
    }
};