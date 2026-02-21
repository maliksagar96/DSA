#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        //Take the transpose
        int n = mat.size();
        for(int i = 0;i<n;i++){
            //To transpose a matrix we don't have to go full length. 
            for(int j = i+1;j<n;j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }
        
        //invert the column
        for(int j = 0;j<n;j++){
            for(int i = 0;i<n/2;i++) {
                int temp = mat[n-1-i][j];
                mat[n-1-i][j] = mat[i][j];
                mat[i][j] = temp;
            }
        }            
    }
};

int main() {

    vector<vector<int>> mat = {{0, 1, 2},{3, 4, 5} , {6, 7, 8}};
    Solution sol;
    sol.rotateMatrix(mat);
    
    return 0;
}