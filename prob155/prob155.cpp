/*
  This is an easy code except the part where we need a differnt stack to keep track of the min value as well. 
*/


#include <iostream>

using namespace std;

class MinStack {
public:
    MinStack() {
      
    }
    
    void push(int val) {
      stk.push_back(val);
      if(min_num.empty()) min_num.push(val);
      else {
        if(val <= min_num.top()) {          
          min_num.push(val);
        }
      }
    }
    
    void pop() {
      if(stk.back() == min_num.top()) {        
        min_num.pop();
      }
      stk.pop_back();
      
    }
    
    int top() {
        return stk[stk.size()-1];
    }
    
    int getMin() {
      return min_num.top();
    }

  private:
   vector<int> stk;
   stack<int> min_num;
};

int main() {

  return 0;
}