class Solution {
public:
    bool isValid(string S) {
        stack<char> test;
        for(int i=0;S[i]!='\0';++i){
            if(S[i] == 'c'){
                if(test.empty()) return false;
                if(test.top()!='b') return false;
                test.pop();
                if(test.empty()) return false;
                if(test.top()!='a') return false;
                test.pop();
                continue;
            }else
                test.push(S[i]);
        }
        if(test.empty()) return true;
        return false;
    }
};
