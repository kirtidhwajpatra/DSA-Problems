class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int r, int c, int n, int expVal){
        if(r<0 || c<0 || c>=n || r>=n || grid[r][c]!=expVal) return false;
        if(grid[r][c]==n*n-1) return true;

        //possible Knight moves
        int possibleMove1 = isValid(grid, r-2, c+1, n, expVal+1);
        int possibleMove2 = isValid(grid, r-1, c+2, n, expVal+1);
        int possibleMove3 = isValid(grid, r+1, c+2, n, expVal+1);
        int possibleMove4 = isValid(grid, r+2, c+1, n, expVal+1);
        int possibleMove5 = isValid(grid, r+2, c-1, n, expVal+1);
        int possibleMove6 = isValid(grid, r+1, c-2, n, expVal+1);
        int possibleMove7 = isValid(grid, r-1, c-2, n, expVal+1);
        int possibleMove8 = isValid(grid, r-2, c-1, n, expVal+1);

        return possibleMove1 || possibleMove2 || possibleMove3 || possibleMove4 || possibleMove5 || possibleMove6 || possibleMove7 || possibleMove8;


    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
        
    }
};