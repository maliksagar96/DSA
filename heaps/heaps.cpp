#include <iostream>

using namespace std;

struct Node {
  Node *left , Node *right;
  int val;
  Node():val(0), left(nullptr), right(nullptr);
  Node(int x):val(x),left(nullptr), right(nullptr);
  Node(int x, Node *left, Node *right):val(x), left(left), right(right);
}

void inorderTraversal(Node *node) {

  inorderTraversal(node->left);
  cout<<node->val

}

int main() {

}