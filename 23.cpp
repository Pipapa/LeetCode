#include <iostream>
#include <vector>
#include <queue>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeLists(ListNode *l1,ListNode *l2){
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* ret;
        if(l1->val <= l2->val){
            ret = l1;
            ret->next = mergeLists(l1->next,l2);
        }else{
            ret = l2;
            ret->next = mergeLists(l1,l2->next);
        }
        return ret;
    }

    struct CMP{
        bool operator()(const ListNode *l,const ListNode *r){
            return l->val > r->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *,vector<ListNode *>,CMP> listq;
        for(int i=0;i<lists.size();++i){
            if(lists[i]) listq.push(lists[i]);
        }
        if(lists.size() == 0) return NULL;
        if(listq.empty()) return NULL;
        ListNode *ret = listq.top();
        ListNode *loop = ret;
        listq.pop();
        if(loop->next) listq.push(loop->next);
        while(!listq.empty()){
            ListNode *t = listq.top();
            listq.pop();
            loop->next = t;
            loop = t;
            t = t->next;
            if(t) listq.push(t);
        }
        return ret;
    }
};

int main(){
    return 0;
}