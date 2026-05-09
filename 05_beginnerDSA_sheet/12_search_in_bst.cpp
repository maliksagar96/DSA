#include <iostream>

using namespace std;

class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
  public:
		bool dfs(Node *root, int key) {
			
			if(!root) return false;

			if(root->data == key) return true;

			if(root->data > key) return dfs(root->left, key);
			else return dfs(root->right, key);
		
		}

    bool search(Node* root, int key) {
			return dfs(root, key);

    }
};

int main() {

    return 0;
}