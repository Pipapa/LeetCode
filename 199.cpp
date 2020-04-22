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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<TreeNode*> q;
        if(root) {
            q.push(root);
        }
        q.push(NULL);
        bool flag = true;
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(flag == true && top != NULL) {
                flag = false;
                ret.push_back(top->val);
            }
            if(top == NULL) {
                if(!q.empty()) {
                    q.push(NULL);
                }
                flag = true;
                continue;
            }
            if(top->right) {
                q.push(top->right);
            }
            if(top->left) {
                q.push(top->left);
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    assert(1 == 1);
    return 0;
}
