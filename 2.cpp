/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int cnt = 0;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *ret = NULL;
        ListNode *loop = ret;
        while(l1 && l2){
            int sum = l1->val + l2->val + cnt;
            if(sum >= 10){
                sum -= 10;
                cnt = 1;
            }else cnt = 0;
            if(loop == NULL){
                loop = new ListNode(sum);
                ret = loop;
            }
            else{
                loop->next = new ListNode(sum);
                loop = loop->next;
            }
            l2 = l2->next;
            l1 = l1->next;
        }
        while(l1){
            int sum = l1->val  + cnt;
            if(sum >=10 ){
                sum -= 10;
                cnt = 1;
            }else cnt = 0;
            loop->next = new ListNode(sum);
            loop = loop->next;
            l1 = l1->next;
        }
        while(l2){
            int sum = l2->val + cnt;
            if(sum >= 10){
                sum -= 10;
                cnt = 1;
            }else cnt = 0;
            loop->next = new ListNode(sum);
            loop = loop->next;
            l2 = l2 -> next;
        }
        if(cnt){
            loop->next = new ListNode(cnt);
        }
        return ret;
    }
};