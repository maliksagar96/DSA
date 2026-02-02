
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    deque<TreeNode*> dq;
    dq.push_back(root);
    bool flip = true;

    while (!dq.empty()) {
      int size = dq.size();
      vector<int> curr;

      if (flip) {
        for (int i = 0; i < size; ++i) {
          TreeNode* node = dq.front(); dq.pop_front();
          curr.push_back(node->val);
          if (node->left) dq.push_back(node->left);
          if (node->right) dq.push_back(node->right);
        }
      } else {
        for (int i = 0; i < size; ++i) {
          TreeNode* node = dq.back(); dq.pop_back();
          curr.push_back(node->val);
          if (node->right) dq.push_front(node->right);
          if (node->left) dq.push_front(node->left);
        }
      }

      flip = !flip;
      result.push_back(curr);
    }

    return result;
  }
};


int main() {



  return 0;
}