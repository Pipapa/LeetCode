#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> nq;
        vector<vector<int>> ans;
        if(root) nq.push(root),ans.push_back(vector<int>{root->val});
        int num=1;

        while(!nq.empty()){
            int tnum=0;
            vector<int> level_num;
            for(int i=1;i<=num;i++){ /*THE LEVEL*/
                Node* tq = nq.front();nq.pop();
                for(Node* j:tq->children) tnum++,nq.push(j),level_num.push_back(j->val);
            }
            if(!level_num.empty()) ans.push_back(level_num);
            num = tnum;
        }
        return ans;
    }
};
