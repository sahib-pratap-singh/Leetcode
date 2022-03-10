class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1){
            return -1;
        }
        queue<pair<int,int>> q;
        q.push({0,0});
        int dir[8][2]={{-1,0},{0,-1},{0,1},{1,0},{-1,-1},{1,1},{-1,1},{1,-1}};
        int cnt=0;
        while(!q.empty()){
            int n=q.size();
            for(int t=0;t<n;t++){
                pair<int,int> p=q.front();
                if(p.first==grid.size()-1 and p.second==grid.size()-1)
                    return cnt+1;
                q.pop();
                for(int i=0;i<8;i++){
                    int x=p.first+dir[i][0];
                    int y=p.second+dir[i][1];
                    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==1){
                        continue;
                    }
                    q.push({x,y});
                    grid[x][y]=1;
                }
            }
            cnt++;
        }
        return -1;
    }
};