class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int b) {
        int r=grid.size();
        int c=grid[0].size();
        int s=0;
        int e=r*c-1;;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(grid[mid/c][mid%c]==b){
                return 1;
            }
            if(grid[mid/c][mid%c]>b){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return 0;
    }
};