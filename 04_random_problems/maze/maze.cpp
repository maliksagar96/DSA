/*
    The maze is simple. There is only one exit and one entry point. 

    0000017
    0000010
    0000010
    0000010
    0000070

    7 is the entry and the exit point.
    Find the total number of steps that are required to finish this maze.
*/

#include <iostream> 
#include <vector>

using namespace std;

void move(int currX, int currY, vector<vector<int>>& maze, int& steps) {
    
    //Move right
    if(maze[currX + 1][currY]) 
    {   steps++;
        move(currX + 1, currY, maze, steps);
    }

    //Move left
    if(maze[currX - 1][currY]) 
    {   steps++;
        move(currX - 1, currY, maze, steps);
    }

    //Move top
    if(maze[currX][currY+1]) 
    {   steps++;
        move(currX, currY+1, maze, steps);
    }

    //Move bottom
    if(maze[currX][currY-1]) 
    {   steps++;
        move(currX, currY - 1, maze, steps);
    }

}

int solve(vector<vector<int>>& maze) {

    int steps = 0;

    int startX = 0, startY = 0;

    bool foundEntry = 0;
    for(int i = 0;i<maze.size();i++) {
        for(int j = 0;j<maze[0].size();j++) {
            if(maze[i][j] == 7) {
                startX = i;
                startY = j;
                foundEntry = 1;
                break;
            }
            if(foundEntry) break;
        }
    }

    move(startX, startY, maze, steps);
    return steps;
}

int main() {
    
    std::vector<std::vector<int>> maze = {
        {0, 0, 0, 0, 0, 1, 7},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 7, 0}
    };

    cout<<solve(maze)<<endl;
    return 0;
}