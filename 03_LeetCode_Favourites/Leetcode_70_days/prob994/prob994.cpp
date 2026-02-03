/*

  This is the first long kind of problem I completed. The logic is not that tough. 
  I was confused which kind of DS to use. Initially I was going for a set. However this is BFS kind of problem. Hence a queue would be good. 
*/


#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      
      deque<pair<int, int>> rottingPositions;
      int ROTTEN = 2, FRESH = 1;
      int freshOranges = 0;

      int rows = grid.size();
      int columns = grid[0].size();

      for(int i = 0;i<rows;i++) {
        for(int j = 0;j<columns;j++) {
          if(grid[i][j] == ROTTEN) {
            rottingPositions.push_back({i,j});
          }
          
          else if(grid[i][j] == FRESH) {
            freshOranges++;
          }
        }
      }

      if(freshOranges == 0) return 0;

      int minutes = -1;
      while(!rottingPositions.empty()) {
        minutes++;
        int rottenOranges = rottingPositions.size();
        
        for(int i = 0;i<rottenOranges;i++) {
          
          auto dq = rottingPositions.front();
          //if right orange is fresh
          if(dq.first + 1 < rows && grid[dq.first + 1][dq.second] == FRESH) {            
            grid[dq.first + 1][dq.second] = ROTTEN;
            rottingPositions.push_back({dq.first + 1, dq.second});
            freshOranges--;            
          }

          //if left orange is rotten
          if(dq.first - 1 >= 0 && grid[dq.first - 1][dq.second] == FRESH) {            
            grid[dq.first - 1][dq.second] = ROTTEN;
            rottingPositions.push_back({dq.first - 1, dq.second});
            freshOranges--;
            
          }

          //if top
          if(dq.second - 1 >= 0 && grid[dq.first][dq.second - 1] == FRESH) {            
            grid[dq.first][dq.second-1] = ROTTEN;
            rottingPositions.push_back({dq.first, dq.second-1});
            freshOranges--;          
          }

          //if bottom
          if(dq.second + 1 < columns && grid[dq.first][dq.second + 1] == FRESH) {            
            grid[dq.first][dq.second+1] = ROTTEN;
            rottingPositions.push_back({dq.first, dq.second+1});
            freshOranges--;            
          }

          rottingPositions.pop_front();
        }
        
      }

      if(freshOranges == 0)  return minutes;

      else return -1;
    }

    
};


int main() {
  return 0;
}