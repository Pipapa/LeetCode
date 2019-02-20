#include <iostream>
#include <queue>
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

struct TreeNode{
    int val;
    TreeNode *left,*right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> searchQ;
        searchQ.push(root->left);
        searchQ.push(root->right);
        while(!searchQ.empty()){
            TreeNode* top1 = searchQ.front();
            searchQ.pop();
            TreeNode* top2 = searchQ.front();
            searchQ.pop();
            if(top1 == NULL && top2) return false;
            if(top1 && top2 == NULL) return false;
            if(top1 == NULL && top2 == NULL) continue;
            if(top1->val != top2->val) return false;
            searchQ.push(top1->left);
            searchQ.push(top2->right);
            searchQ.push(top1->right);
            searchQ.push(top2->left);
        }
        return true;
    }
};