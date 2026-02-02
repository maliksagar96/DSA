#include <iostream>

using namespace std;

struct TreeNode {
  Node *left , Node *right;
  int val;
  Node():val(0), left(nullptr), right(nullptr);
  Node(int x):val(x),left(nullptr), right(nullptr);
  Node(int x, Node *left, Node *right):val(x), left(left), right(right);
}

class Solution {
public:
    TreeNode* findMin(TreeNode* node) {
        while (node->left)
            node = node->left;   
        return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Go left
        if (key < root->val)
            root->left = deleteNode(root->left, key);  

        // Go right
        else if (key > root->val)
            root->right = deleteNode(root->right, key);  

        else {
            // Case 1: No children
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: One child
            else if ((root->left == nullptr) ^ (root->right == nullptr)) {
                TreeNode* child = root->left ? root->left : root->right;  
                delete root;
                return child;
            }

            // Case 3: Two children
            else {
                TreeNode* succ = findMin(root->right);  
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);  
            }
        }
        return root;
    }
};


int main() {

}