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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> snode;
        vector<int> ans;
        if(root == NULL) return ans;
        TreeNode *loop = root;
        while(loop || !snode.empty()){
            while(loop){
                snode.push(loop);
                loop = loop->left;
            }
            if(!snode.empty()){
                loop = snode.top();
                snode.pop();
                ans.push_back(loop->val);
                loop = loop->right;
            }
        }
        return ans;
    }
};