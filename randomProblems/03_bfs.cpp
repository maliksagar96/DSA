#include <iostream>
#include <queue>

using namespace std;

struct Node{

  Node(int val):val(val), left(nullptr), right(nullptr){}
  Node(int val,Node *left, Node *right):val(val), left(left), right(right) {}

  Node *left, *right;
  int val;

};

void printBFS(Node *root) {

  if(!root) return;
  queue<Node*> bfsQ;

  bfsQ.push(root);

  while(!bfsQ.empty()) {
    Node *curr = bfsQ.front();

    cout<<curr->val<<endl;
    if(curr->left) bfsQ.push(curr->left);
    if(curr->right) bfsQ.push(curr->right);
    bfsQ.pop();
  }

}

void printDFS(Node *root) {
  if(!root) return;

  if(root->left) printDFS(root->left);
  cout<<root->val<<endl;
  if(root->right) printDFS(root->right);
}


int main() {

  Node* root = new Node(1);

  root->left  = new Node(2);
  root->right = new Node(3);

  root->left->left   = new Node(4);
  root->left->right  = new Node(5);

  root->right->left  = new Node(6);
  root->right->right = new Node(7);


  printBFS(root);

  cout<<"*****************"<<endl;

  printDFS(root);

  return 0;
}