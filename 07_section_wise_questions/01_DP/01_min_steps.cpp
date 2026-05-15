#include <iostream>

using namespace std;

/*
class Solution {
  
  public:

    void walk(int stepsRemaining, int p, int q, int count, int &answer) {
      if(stepsRemaining == 0) {
        answer = min(answer, count);
      }

      if(stepsRemaining - p >= 0) {
        walk(stepsRemaining - p, p, q, count + 1, answer);
      }

      if(stepsRemaining - q >= 0) {
        walk(stepsRemaining - q, p, q, count + 1, answer);
      }
    }

    int moves(int n, int p, int q) {
      
      int answer = INT_MAX;
      int count = 0;
      walk(n, p, q, count, answer);
      if(answer == INT_MAX) {
        return -1;
      }
      return answer;

    }
};
*/

class Solution {
  
  public:

    int moves(int n, int p, int q) {
      vector<int> steps(n+1, INT_MAX);

      step[0] = 0; //0 ways to reach 0. Even though we are at 0 we can't reach ther. 

      for(int i = 1;i<n;i++) {

        //action - take p steps
        if(i-p >= 0 && steps[i-p] != INT_MAX) {
          steps[i] = min(steps[i], steps[i-p] + 1);
        }

        //action - take q steps 
        if(i-q >= 0 && steps[i-q] != INT_MAX) {
          steps[i] = min(steps[i], steps[i-q] + 1);
        }
      }

      if(steps[n] == INT_MAX) {
        return -1;
      }

      return steps[n];

    }
  };

int main() {

  return 0;
}
