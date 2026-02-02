#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      
    }
};

int main() {

  vector<int> asteroids = {5,10,-5};
  Solution sol;
  vector<int> answer = sol.asteroidCollision(asteroids);

  for(int i = 0;i<answer.size();i++) {
    cout<<asteroids[i]<<"\n";
  }

  return 0;
}