class Solution {
public:
    int halveArray(vector<int>& nums) {
        double sum=0;
        for(auto x:nums)
            sum+=x;
        double val=sum/2.0;
        priority_queue<double> pq;
        for(auto x:nums)
            pq.push(x);
        int cnt=0;
        while(sum>val){
            double d=pq.top();
            pq.pop();
            d=d/2;
            pq.push(d);
            sum-=d;
            cnt++;
        }
        return cnt;
    }
    
};