// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool isvalid(int grid[N][N], int i, int j, char x){
        for(int q=0;q<N;q++){
            if((grid[i][q])==x){
                return false;
            }
        }
        for(int q=0;q<N;q++){
            if((grid[q][j])==x){
                return false;
            }
        }
        int r=(i/3)*3;
        int c=(j/3)*3;
        for(int e=0;e<3;e++){
            for(int t=0;t<3;t++){
                if(grid[e+r][t+c]==x){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(int grid[N][N], int i, int j) {
        if(i==N-1 and j==N){
            return true;
        }
        if(j==N){
            i++;
            j=0;
        }
        if(grid[i][j] != 0){
            return solve(grid,i,j+1);
        }else{
            for(char x=1;x<=9;x++){
                if(isvalid(grid,i,j,x)){
                    grid[i][j]=x;
                    if(solve(grid,i,j+1)){
                        return true;
                    }
                    grid[i][j]=0;
                }
                
            }
        }
        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        return solve(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
            //cout<<endl;
        } 
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends