#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode{
     int val;
     ListNode *next;
     ListNode(int x):val(x),next(NULL){}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        /*ListNode *ret;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next,l2);
            ret = l1;
        }else{
            l2->next = mergeTwoLists(l1,l2->next);
            ret = l2;
        }
        return ret;*/

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *ret,*pre;
        if(l1->val < l2->val){
            pre = ret = l1;
            l1 = l1 -> next;
        } else{
            pre = ret = l2;
            l2 = l2 ->next;
        }
        while(l1 && l2){
            if(l1->val < l2->val){
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            }else{
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }
        if(l1) pre->next = l1;
        if(l2) pre->next = l2;
        return ret;
    }


};




int main(int argc,char *argv[]){
    return 0;
}
