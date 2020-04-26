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

  bool IsExist(TreeNode* root, int level, int k) {
    TreeNode* loop = root;
    for(int i = level; i > 0; --i) {
      if( ( k >> (i - 1) ) & 0x1 ) {
        loop = loop->right;
      }else {
        loop = loop->left;
      }
    }
    return loop == NULL? false : true;
  }

  int countNodes(TreeNode* root) {
    int level = -1, ret = 0;

    TreeNode* loop = root;
    while(loop) {
      loop = loop->left;
      ++level;
    }

    if(level == -1 || level == 0) { return level + 1; }

    int l = 0;
    int count = 1 << level;
    ret = count - 1;
    
    while(count > 0) {
      int step = count / 2;
      int mid = l + step;
      if(!IsExist(root, level, mid)) {
        count = step;
      }else {
        l = mid + 1;
        count -= step + 1;
      }
    }

    return ret + l;
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
