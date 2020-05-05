#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool first = true;
  int prev = 0;
  bool isValidBST(TreeNode* root) {
    bool ret = true;
    if(root == NULL) { return true; }
    if( !isValidBST(root->left) ) {
      return false;
    }
    // visite
    if(first) {
      first = false;
    }else if(root->val <= prev) {
      return false;
    }
    prev = root->val;
    if( !isValidBST(root->right) ) {
      return false;
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
