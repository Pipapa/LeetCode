#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;



class LRUCache {
public:
    struct ListNode{
        int v,k;
        ListNode *prev,*next;
        ListNode(int key,int value){
            k = key;
            v = value;
            prev = NULL;
            next = NULL;
        }
        ListNode():prev(NULL),next(NULL),v(0),k(-1){}
    };
    ListNode *head,*tail;
    LRUCache(int capacity){
        cap = capacity;
        tail = new ListNode();
        head = new ListNode();
        tail->next = head;
        tail->prev = head;
        head->next = tail;
        head->prev = tail;
    }

    int get(int key) {
        unordered_map<int,ListNode*>::iterator it;
        it = table.find(key);
        if(it != table.end()){
            ListNode *node = it->second;
            deletenode(node);
            appendtail(node);
            return node->v;
        }
        return -1;
    }

    void put(int key, int value) {
        unordered_map<int,ListNode*>::iterator it;
        it = table.find(key);
        if(it != table.end()){
            // exsit
            ListNode* node = it->second;
            node->v = value;
            deletenode(node);
            appendtail(node);
        }else{
            // not found add
            if(cap == 0){
                ListNode* node = head->next;
                if(node == tail)
                    return;
                deletenode(node);
                table.erase(node->k);
                delete node;
                ListNode* newnode = new ListNode(key,value);
                table.insert({key,newnode});
                appendtail(newnode);
            }else{
                --cap;
                ListNode* node = new ListNode(key,value);
                table.insert({key,node});
                appendtail(node);
            }
        }
    }

    void deletenode(ListNode *node){
        if(node == tail || node == head) return;
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void appendtail(ListNode *node){
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

private:
    int cap;
    unordered_map<int,ListNode*> table;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.get(1);       // returns 1
    cache.put(3, 3);    // evicts key 2
    cache.get(2);       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cache.get(1);       // returns -1 (not found)
    cache.get(3);       // returns 3
    cache.get(4);       // returns 4
    return 0;
}
