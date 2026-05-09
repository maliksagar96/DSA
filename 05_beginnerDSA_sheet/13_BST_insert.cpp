#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
			data = val;
			left = right = nullptr;
    }
};

class Solution {
  public:

		void insertBST(Node *root, int key) {
			
			if(key > root->data) {
				if(root->right)
					insertBST(root->right, key);
				else {
					root->right = new Node(key);
					return;
				}
			}
			else {
				if(root->left) {
					insertBST(root->left, key);
				}
				else {
					root->left = new Node(key);
					return;
				}
				
			} 
			
		}

    Node* insert(Node* root, int key) {
      insertBST(root, key);
			return root;
    }
};

int main() {

    return 0;
}