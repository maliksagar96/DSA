#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

  int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size();
    int columns = grid[0].size();
    int islands = 0;

    for(int i = 0;i<rows;i++) {
      for(int j = 0;j<columns;j++) {
        if(grid[i][j] == '1') {
          islands++;
          dfs(grid, i, j, rows, columns);
        }
      }
    }      
    return islands;
  }

  void dfs(vector<vector<char>>& grid, int i, int j, int rows, int columns) {
    if((i < 0) || (i >= rows) || (j < 0) || (j >= columns) || (grid[i][j] == '0')) {
      return;
    }

    grid[i][j] = '0';
    dfs(grid, i+1, j, rows, columns);//right neighbour
    dfs(grid, i-1, j, rows, columns);//left neighbour
    dfs(grid, i, j+1, rows, columns);//top neighbour
    dfs(grid, i, j-1, rows, columns);//bottom neighbour
  }
};