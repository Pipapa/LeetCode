#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    std::stack<std::pair<int, int>> stack_;
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(stack_.empty()) {
          stack_.push(std::make_pair(x, x));
          return;
        }
        auto t = std::move(stack_.top());
        int m  = min(x, t.second);
        stack_.push(std::make_pair(x, m));
    }
    
    void pop() {
        stack_.pop();
    }
    
    int top() {
        auto t = std::move(stack_.top());
        return t.first;
    }
    
    int getMin() {
        auto t = std::move(stack_.top());
        return t.second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main(int argc, char *argv[]) {
  Solution s;
  assert(1 == 1);
  return 0;
}
