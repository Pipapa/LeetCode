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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> snode;
        vector<int> ans;
        if(!root) return ans;
        TreeNode *cur,*pre=NULL;
        snode.push(root);
        while(!snode.empty()){
            cur = snode.top();
            if((cur->left==NULL&&cur->right==NULL)||(pre&&(pre==cur->left||pre==cur->right))){
                ans.push_back(cur->val);
                snode.pop();
                pre = cur;
            }else{
                if(cur->right) snode.push(cur->right);
                if(cur->left) snode.push(cur->left);
            }
        }
        return ans;
    }
};
