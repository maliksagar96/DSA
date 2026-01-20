/*
    The key idea behind DFS is that we pick one direction we go as far as possible in that direction until
    we find success or dead end. So this finding an island problem is a classic DFS problem.

*/

#include <iostream>
#include <vector>

using namespace std;

void convertIslandToWater(int i, int j, vector<vector<char>>& grid) {
    if(i < 0 || i >= grid.size() || j < 0 || j>grid.size() || grid[i][j] == '0') {
        return;
    }

    grid[i][j] = '0';
    convertIslandToWater(i, j-1, grid); // left
    convertIslandToWater(i, j+1, grid); // right
    convertIslandToWater(i-1, j, grid); //top
    convertIslandToWater(i+1, j, grid); //bottom
}

int isIsland(vector<vector<char>>& grid) {

    int islandCount = 0;

    for(int i = 0;i<grid.size();i++) {
        
        for(int j = 0;j<grid.size();j++) {
            if(grid[i][j] == '1') {
                islandCount++;
                convertIslandToWater(i, j, grid);
            }
        }
    }
    return islandCount;
}


int main() {

    vector<vector<char>> grid = {
  {'1','1','0','0','0'},
  {'1','1','0','0','0'},
  {'0','0','1','0','0'},
  {'0','0','0','1','1'}
};

    cout << isIsland(grid) << endl;

    return 0;
}