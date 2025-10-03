#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        bool collision = 1;        

        while(collision) {
            collision = 0;
            if(asteroids.size() > 0) {
                for(int i = 0;i<asteroids.size()-1;i++) {
                    if(asteroids[i] > 0 && asteroids[i+1] < 0) {
                        collision = 1;
                        if (abs(asteroids[i]) > abs(asteroids[i+1])) {
                            asteroids.erase(asteroids.begin() + i + 1);
                        } else if(abs(asteroids[i]) == abs(asteroids[i+1])) {
                            asteroids.erase(asteroids.begin() + i + 1);
                            asteroids.erase(asteroids.begin() + i);
                            i--;
                        }
                        else{
                            asteroids.erase(asteroids.begin() + i);
                        }
                        i--;
                    }
                }
            }
            
            // cout<<"Collisions = "<<collision<<endl;
        }
        
        return asteroids;
        
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