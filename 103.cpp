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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> nqueue;
        nqueue.push(root);
        int cnt = 1;
        int dir = 1;
        while(!nqueue.empty()){
            int num = 0;
            int pos = 0;

            if(dir == 1) pos = 0;
            else pos = cnt - 1;

            std::vector<int> thisv(cnt,0);
            while(cnt--){
                TreeNode *tnode = nqueue.front();
                nqueue.pop();
                thisv[pos] = tnode->val;
                if(dir == 1) pos++;
                else pos--;
                if(tnode->left){
                    num++;
                    nqueue.push(tnode->left);
                }
                if(tnode->right){
                    num++;
                    nqueue.push(tnode->right);
                }
            }
            cnt = num;
            dir = -dir;
            ans.push_back(thisv);
        }
        return ans;
    }
};