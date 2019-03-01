#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        string result = "";
        stack<string> dir;
        int l=0,r=0;
        while(path[r++]!='\0'){
            if(path[r] == '/'){
                int len = r-l-1;
                if(len <= 0){

                }else if(len == 1 && path[l+1] == '.'){

                }else if(len == 2 && path[l+1] == '.' && path[l+2] == '.'){
                    if(!dir.empty()) dir.pop();
                }else{
                    dir.push(path.substr(l+1,len));
                }
                l = r;
            }
        }
        while(!dir.empty()){
            result =  "/" + dir.top() + result;
            dir.pop();
        }
        if(result.length() == 0) return "/";
        return result;
    }
};


int main(int argc,char* argv[]){
    Solution s;
    cout << s.simplifyPath("/home//foo/");
    cout << s.simplifyPath("/../");
    cout << s.simplifyPath("/home/");
    cout << s.simplifyPath("/a//b////c/d//././/../");
    return 0;
}
