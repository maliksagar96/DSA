/*
	This is a clever solution. 
	The inital value of the root can be anything. But it is between -inf and inf or from LLONG_MIN to LLONG_MAX. 
	This interval will go on decreasing. It will start shrinking from both directions. The solve fucntion just makes sure that the values are 
	found in those intervals. Otherwise it returns false. 
	The if statement in the solve function has 2 argumnets. One of them will always be false. the other should be false in order to have correct
	
*/

#include <iostream>

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
    bool solve(TreeNode* root, long long mini, long long maxi){
			if (!root) return true;
			if (root->val <= mini || root->val >= maxi) return false;
			return solve(root->left, mini, root->val) && solve(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
			return solve(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {

  return 0;
}