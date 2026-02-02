#include <iostream>
#include <vector>

using namespace std;

void solveMaze(int startx, int starty, int endx, int endy, vector<vector<int>>& maze, bool &solveFlag) {
    if(startx < 0 || startx >= maze.size() || starty < 0 || starty >= maze[0].size() || maze[startx][starty] == 1) {
        return;
    }

    if(startx == endx && starty == endy) 
    {
        solveFlag = true;
        return;
    }

    maze[startx][starty] = 1;
    solveMaze(startx + 1, starty, endx, endy, maze, solveFlag);
    solveMaze(startx - 1, starty, endx, endy, maze, solveFlag);
    solveMaze(startx, starty + 1, endx, endy, maze, solveFlag);
    solveMaze(startx, starty - 1, endx, endy, maze, solveFlag);
}

int main() {

    vector<vector<int>> maze = {
  {0,0,1,0},
  {1,0,0,0},
  {0,0,1,0},
  {0,1,0,0}
};

    int startx = 0, starty = 0;
    int endx = 3, endy = 3;

    bool solveFlag = false;

    solveMaze(startx, starty, endx, endy, maze, solveFlag);

    if(solveFlag) {
        cout<<"maze if solvable.\n";
    }
    else {
        cout<<"No solution for the maze.\n";
    }

    return 0;
}