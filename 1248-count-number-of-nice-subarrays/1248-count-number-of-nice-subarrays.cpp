class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefix(n+1,0);
        int odd=0;
        int ans=0;
        for(int i=0;i<n;i++){
            prefix[odd]++;
            if(nums[i]&1)
                odd++;
            if(odd>=k)
                ans+=prefix[odd-k];
        }
        return ans;
    }
};