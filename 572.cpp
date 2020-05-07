#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  bool cmp(TreeNode* s, TreeNode* t) {
    if(s == NULL && t == NULL) { return true; }
    if(s == NULL || t == NULL) { return false; }
    if(s->val != t->val) { return false; }
    bool ret = true;
    ret &= cmp(s->left, t->left);
    if(!ret) { return false; }
    ret &= cmp(s->right, t->right);
    return ret;
  }

  bool isSubtree(TreeNode* s, TreeNode* t) {
    if(s == NULL && t == NULL) { return true; }
    if(s == NULL || t == NULL) { return false; }
    if(cmp(s, t)) {
      return true;
    }else {
      bool ret = false;
      ret |= isSubtree(s->left, t);
      if(ret) { return true; }
      ret |= isSubtree(s->right, t);
      return ret;
    }
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
