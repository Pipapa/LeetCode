#include <iostream>
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
    int maxDepth(Node* root) {
        if(!root) return 0;
        if((root->children).empty()) return 1;
        int ans=maxDepth(root->children[0]);
        for(int i=1;i<root->children.size();i++) ans = max(ans,maxDepth(root->children[i]));
        return ans + 1;
        /*
        queue<Node*> nodeq;
        int ans=0,num=0;
        if(root) nodeq.push(root);
        num=1;

        while(!nodeq.empty()){
            ans++;
            int tnum=0;
            for(int i=1;i<=num;++i){
                Node *tnode = nodeq.front();nodeq.pop();
                for(Node* tn:tnode->children){
                    if(tn) nodeq.push(tn),tnum++;
                }
            }
            num = tnum;
        }
        return ans;*/
    }
};

int main(){
    return 0;
}