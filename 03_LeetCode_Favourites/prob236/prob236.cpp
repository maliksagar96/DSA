/*
  This is such an elegant problem. 
  So there are 3 cases the first case is that root is either p or q. If that is the case then root will be the common ancestor. 
  If one of them is on the left side of the node and other is on the right side of the node in that case also the common ancestor is root. 
  Now if both of them are one side then we'll return the node where we first hit our desired value.  

*/

#include <iostream>

using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root) return nullptr;
      if(root == p || root == q) return root;

      TreeNode *left = lowestCommonAncestor(root->left, p, q);
      TreeNode *right = lowestCommonAncestor(root->right, p, q);

      if(left && right) return root;

      else{
        return left?left:right;
      }
    }
};

int main() {

  return 0;
}