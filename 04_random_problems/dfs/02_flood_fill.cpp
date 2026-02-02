#include <iostream>
#include <vector>

using namespace std;

void floodfill(int i, int j, int oldColor, int newcolor, vector<vector<int>>& image) {    
    if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != oldColor) {
        return;
    }

    image[i][j] = newcolor;

    floodfill(i, j+1, oldColor, newcolor, image);
    floodfill(i, j-1, oldColor, newcolor, image);
    floodfill(i+1, j, oldColor, newcolor, image);
    floodfill(i-1, j, oldColor, newcolor, image);
}

int main() {

    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};

    int newcolor = 2;
    int change_x = 1, change_y = 1;

    int oldColor = image[change_x][change_y];

    floodfill(change_x, change_y, oldColor, newcolor, image);

    for (const auto& row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

}