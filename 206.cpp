#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *result = NULL;
        while(head){
            ListNode *tmp = head->next;
            head->next = result;
            result = head;
            head = tmp;
        }
        return result;
    }
};