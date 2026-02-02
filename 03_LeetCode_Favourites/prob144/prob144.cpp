
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
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> result;
      get_bfs_values(result, root);
      return result;
    }

    void get_bfs_values(vector<int>& result, TreeNode* root) {
      if(!root) return;
      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()) {
        TreeNode *node = q.front();
        result.push_back(node->val);
        q.pop();
        if(q->left) q.push(node->left);
        if(q->right) q.push(node->right);
      }
    }

};

int main() {
  return 0;
}