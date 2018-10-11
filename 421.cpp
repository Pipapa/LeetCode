#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
#define FATHER 2
    struct TrieNode{
        TrieNode *child[3];
        TrieNode(){for(int i=0;i<3;i++) child[i]=NULL;}
    };
    TrieNode *root;
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(int num : nums) buildTree(num);
        vector<pair<TrieNode*,TrieNode*>> ans;
        vector<pair<TrieNode*,TrieNode*>> zero;
        vector<pair<TrieNode*,TrieNode*>> one;
        int ox[2]={1,0},zx[2]={1,0};
        int oy[2]={0,1},zy[2]={1,0};
        TrieNode *loop = root;
        int level = 32;
        while((loop->child[0] == NULL || loop->child[1] == NULL) && level>0){
            if(loop->child[0]) loop = loop->child[0];
            else loop = loop->child[1];
            level--;
        }
        if(!level) return 0;
        ans.push_back(make_pair(loop->child[0],loop->child[1]));
        for(int i=1;i<level;i++){
            zero.clear(),one.clear();
            for(auto item_pair : ans){
                for(int i=0;i<2;i++){
                    if(item_pair.first->child[ox[i]] && item_pair.second->child[oy[i]])
                        one.push_back(make_pair(item_pair.first->child[ox[i]],item_pair.second->child[oy[i]]));
                    if(item_pair.first->child[zx[i]] && item_pair.second->child[zy[i]])
                        zero.push_back(make_pair(item_pair.first->child[zx[i]],item_pair.second->child[zy[i]]));
                }
            }
            if(one.empty()) ans=zero;
            else ans = one;
        }
        TrieNode *left = ans[0].first,*right = ans[0].second;
        int ret = 0;
        for(int i=0;i<32;i++){
            int left_num = left->child[FATHER]->child[1] == left ? 1 : 0;
            int right_num = right->child[FATHER]->child[1] == right ? 1 : 0;
            left = left->child[FATHER];
            right = right->child[FATHER];
            ret |= ((left_num^right_num) << i);
        }
        return ret;
    }
    bool buildTree(int num){
        TrieNode *loop = root;
        for(int n=31;n>=0;n--){
            int t = ((num&(1<<n))>>n)&1;
            if(loop->child[t] == NULL){
                TrieNode *n_node = new TrieNode();
                n_node->child[FATHER] = loop;
                loop->child[t] = n_node;
                loop = n_node;
            }else loop = loop->child[t];
        }
        return true;
    }
};

int main(){
    vector<int> nums={3,10,5,25,2,8};
    vector<int> nums_ = {12,86,52,58,13,63,64,18,40,73,44,94};
    Solution s;
    cout << s.findMaximumXOR(nums) << endl;

    return 0;
}
