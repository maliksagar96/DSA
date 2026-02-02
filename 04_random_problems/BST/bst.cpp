#include <iostream>

using namespace std;

struct TreeNode{
  TreeNode *left, *right;
  int val;
  TreeNode():val(0), left(nullptr), right(nullptr){}
  TreeNode(int x):val(x), left(nullptr), right(nullptr){}
  TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

void printDFS(TreeNode *node) {
  if(!node) return;
  printDFS(node->left);
  cout<<node->val<<endl;
  printDFS(node->right);
}

void insertNode(TreeNode *node, int val) {  
  //if value is less then the node value go left
  if(val < node->val) {

    if(!node->left) node->left = new TreeNode(val);
    else insertNode(node->left, val);  
  }
  
  //if value is less then the node value go right
  if(val > node->val) {
    if(!node->right) node->right = new TreeNode(val);
    else insertNode(node->right, val);
  } 
}

//Finding the minimum value in the right subtree
TreeNode *findMin(TreeNode *node) {
  while(node->left) 
    node = node->left;
  return node;
}

//OR
//Finding maximum in the left subtree

TreeNode *findMax(TreeNode *node) {
  while(node->right) 
    node = node->right;
  return node;
}

TreeNode* deleteNode(TreeNode *node, int val) {
  if(!node) return nullptr;

  if(node->val == val) {
    //Case 1 - If the node is a leaf
    if(!node->left && !node->right) {
      delete node;
      return nullptr; 
    }

    //Case 2 - If one Child is missing.
    else if(!node->left || !node->right) {
      TreeNode *child = node->left? node->leaf:node->right;
      delete node;
      return child;
    }

    //Case 3 - If no child is missing
    else {
      TreeNode *succ = findMin(node->right);
      node->val = succ->val;
      node->right = deleteNode(node->right, succ->val);
    }
  }

  else if(val > node->val) {
    deleteNode(node->right, val);
  }

  else {
    deleteNode(node->left, val);
  }
  

}

int main() {

  TreeNode root{10};  
  insertNode(&root, 5);
  insertNode(&root, 12);
  
  printDFS(&root);

  return 0;
}