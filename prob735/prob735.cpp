#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> remaining_ast;

        

        for(int current_ast : asteroids) {
            bool destroyed = false;
            while(!remaining_ast.empty() && current_ast < 0 && remaining_ast.back() > 0) {
                if(abs(current_ast) == remaining_ast.back()) {
                    remaining_ast.pop_back();                    
                    destroyed = true;
                    break;
                }

                else if(abs(current_ast) < remaining_ast.back()) {
                    destroyed = true;
                    break;
                }

                else if(abs(current_ast) > remaining_ast.back()) {
                    remaining_ast.pop_back();
                }                
            }

            if(!destroyed) {
                remaining_ast.push_back(current_ast);
            }
        }

        return remaining_ast;
    }
};


int main() {

    Solution sol;
    vector<int> asteroids = {8, -8};

    vector<int> ans = sol.asteroidCollision(asteroids);
    for(int i = 0;i<asteroids.size();i++) {
        cout<<ans[i]<<endl;
    }

    




    return 0;
}