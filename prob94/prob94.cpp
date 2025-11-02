
#include <iostrea>
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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder_vals(result, root);
    return result;
  }

  void inorder_vals(vector<int>& result, TreeNode *node){
    if(!node)  return;
    inorder_vals(result, node->left);
    result.push_back(node->val);
    inorder_vals(result, node->right);
  }
};

int main() {



  return 0;
}