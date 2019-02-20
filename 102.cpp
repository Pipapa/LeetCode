#include <vector>
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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root) return ret;
        queue<TreeNode*> searchQ;
        searchQ.push(root);
        int cnt = 1;
        while(!searchQ.empty()){
            int tcnt = 0;
            vector<int> larr;
            while(cnt--){
                TreeNode* top = searchQ.front();
                searchQ.pop();
                larr.push_back(top->val);
                if(top->left){
                    tcnt++;
                    searchQ.push(top->left);
                }
                if(top->right){
                    tcnt++;
                    searchQ.push(top->right);
                }
            }
            ret.push_back(larr);
            cnt = tcnt;
        }
        return ret;
    }
};
