#include <iostream>
#include <map>
#include <vector>
using namespace std;

class LFUCache {
private:
    struct Node {
        Node *next_;
        Node *prev_;
        int freq_;
        int key_;
        int value_;
        Node(int key, int value) {
            key_ = key;
            value_ = value;
            freq_ = 0;
            next_ = this;
            prev_ = this;
        }
    };

    vector<Node*> listHeads;

    void DeleteNode(Node *node) {
        node->prev_->next_ = node->next_;
        node->next_->prev_ = node->prev_;
    }

    void AppendToTail(Node *node, Node *head) {
        node->next_ = head;
        node->prev_ = head->prev_;
        head->prev_->next_ = node;
        head->prev_ = node;
    }

    Node* GetLastNode(Node *head) {
        Node *ret = head->next_;
        DeleteNode(ret);
        return ret;
    }
    
    bool IsVoidList(Node *node) {
        if(node->prev_ == node) return true;
        if(node->next_ == node) return true;
        return false;
    }

    void FreqNode(Node *node) {
        DeleteNode(node);
        if(IsVoidList(listHeads[node->freq_])) {
            freqSet.erase(node->freq_);
        }
        node->freq_++;
        AppendToTail(node, listHeads[node->freq_]);
        freqSet.insert(node->freq_);
    }
public:
    int cap_;
    
    map<int, Node*> nodeMap;
    set<int> freqSet;
    
    LFUCache(int capacity):listHeads(100, nullptr) {
        cap_ = capacity;
        nodeMap.clear();
        freqSet.clear();
        for(auto it = listHeads.begin(); it != listHeads.end(); ++it) {
            Node *node = new Node(0, 0);
            *it = node;
        }
    }
    
    int get(int key) {
        auto it = nodeMap.find(key);
        if(it == nodeMap.end()) return -1;
        Node *node = nodeMap[key];
        FreqNode(node);
        return node->value_;
    }
    
    void put(int key, int value) {
        auto it = nodeMap.find(key);
        // no key add
        if(it == nodeMap.end()) {
            if(cap_ == 0) {
                auto freqIt = freqSet.begin();
                if(freqIt == freqSet.end()) return;
                Node *toDelete = GetLastNode(listHeads[*freqIt]);
                nodeMap.erase(toDelete->key_);
                delete toDelete;
                if(IsVoidList(listHeads[*freqIt])) {
                    freqSet.erase(freqIt);
                }
                Node *nNode = new Node(key, value);
                nNode->freq_ = 1;
                freqSet.insert(1);
                AppendToTail(nNode, listHeads[1]);
                nodeMap.insert({key, nNode});
            }else{
                Node *nNode = new Node(key, value);
                nNode->freq_ = 1;
                freqSet.insert(1);
                AppendToTail(nNode, listHeads[1]);
                cap_--;
                nodeMap.insert({key, nNode});
            }
        }else {
        // has key refresh
            Node *node = nodeMap[key];
            node->value_ = value;
            FreqNode(node);
        }

    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
	LFUCache cache(3);
	cache.put(2, 2);
	cache.put(1, 1);
	cache.get(2);
	cache.get(1);
	cache.get(2);
	cache.put(3, 3);
	cache.put(4, 4);
	cache.get();
	return 0;
}
