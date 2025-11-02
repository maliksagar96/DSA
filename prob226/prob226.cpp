#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
  int val;
  TreeNode *left, *right;

  TreeNode():val(0), left(nullptr), right(nullptr){}
  TreeNode(int x):val(x), left(nullptr), right(nullptr){}
  TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}

};

void printDFS(TreeNode *node) {
  if(!node) return;

  printDFS(node->left);
  cout<<node->val<<" "<<endl;
  printDFS(node->right);

}

void printBFS(TreeNode* root) {
  if (!root) return;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* node = q.front();
    q.pop();
    cout << node->val << " ";
    if (node->left) q.push(node->left);
    if (node->right) q.push(node->right);
  }
}

void swap_nodes(TreeNode *node) {
  if(!node) return;
  swap_nodes(node->left);
  swap_nodes(node->right);
  TreeNode *temp = node->left;
  node->left = node->right;
  node->right = temp;
}

int main() {
  
  TreeNode left_left(30);
  TreeNode left_right(40);
  TreeNode right_left(50);
  TreeNode right_right(60);

  TreeNode root_left(10, &left_left, &left_right);
  TreeNode root_right(20, &right_left, &right_right);
  TreeNode root(0, &root_left, &root_right);

  swap_nodes(&root);

  // printDFS(&root);
  printBFS(&root);

  return 0;
}