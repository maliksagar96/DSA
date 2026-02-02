/*
    The key idea behind DFS is that we pick one direction we go as far as possible in that direction until
    we find success or dead end. So this finding an island problem is a classic DFS problem.
*/

#include <iostream>
#include <vector>

using namespace std;

void convertIslandToWater(int i, int j, vector<vector<char>>& grid, int &islandsize, int &maxIslandSize) {
    if(i < 0 || i >= grid.size() || j < 0 || j>grid[0].size() || grid[i][j] == '0') {
        return;
    }

    grid[i][j] = '0';
    islandsize++;
    if(islandsize > maxIslandSize) maxIslandSize = islandsize;
    convertIslandToWater(i, j-1, grid, islandsize, maxIslandSize); // left
    convertIslandToWater(i, j+1, grid, islandsize, maxIslandSize); // right
    convertIslandToWater(i-1, j, grid, islandsize, maxIslandSize); //top
    convertIslandToWater(i+1, j, grid, islandsize, maxIslandSize); //bottom
}

int isIsland(vector<vector<char>>& grid, int &maxIslandSize) {

    int islandCount = 0;
    
    for(int i = 0;i<grid.size();i++) {
        
        for(int j = 0;j<grid[0].size();j++) {
            int islandsize = 0;    
            if(grid[i][j] == '1') {
                islandCount++;
                convertIslandToWater(i, j, grid, islandsize, maxIslandSize);
            }
        }
    }
    return islandCount;
}


int main() {

//     vector<vector<char>> grid = {
//   {'1','1','0','0','0'},
//   {'1','1','0','0','0'},
//   {'0','0','1','0','0'},
//   {'0','0','0','1','1'}
// };


// vector<vector<char>> grid = {
//     {'1','1','1','1','0'},
//     {'1','1','0','1','0'},
//     {'1','1','0','0','0'},
//     {'0','0','0','1','1'},
//     {'0','0','0','1','1'}
// };

    vector<vector<char>> grid = {
        {'1','1','1','0'},
        {'1','0','1','0'},
        {'1','1','1','0'},
        {'0','0','0','1'}
    };


    int maxIslandSize = 0;

    cout << isIsland(grid, maxIslandSize) << endl;
    cout<< "Max island size = "<<maxIslandSize<<endl;
    

    return 0;
}