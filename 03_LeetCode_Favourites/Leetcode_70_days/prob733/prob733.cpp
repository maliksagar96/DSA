#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

    int rows = image.size();
    int columns = image[0].size();
    int default_color = image[sr][sc];    
    if(default_color == color) return image;
    dfs(image, sr, sc, rows, columns, default_color, color);        
    return image;
  }

  void dfs(vector<vector<int>>& image, int i, int j, int rows, int columns, int default_color, int color) {
    if((i < 0) || (i>=rows) || (j < 0) || (j >= columns) || image[i][j] != default_color) {
      return;
    }

    image[i][j] = color;

    dfs(image, i+1, j, rows, columns, default_color, color);//Right neighbour
    dfs(image, i-1, j, rows, columns, default_color, color);//left neighbour
    dfs(image, i, j+1, rows, columns, default_color, color);//top neighbour
    dfs(image, i, j-1, rows, columns, default_color, color);//bottom neighbour
    
  }
};
