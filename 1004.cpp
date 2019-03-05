#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int p = 0;
        int result = 0;
        int zero = 0;
        for(int i=0;i<A.size();++i){
            if(A[i] == 0) ++zero;
            while(zero > K){
                if(A[p] == 0) zero--;
                p++;
            }
            result = max(result,i-p+1);
        }
        return result;
    }
};


int main(int argc,char *argv[]){
    Solution s;
    vector<int> test{0,1,0,1,1,1,1,0,1,0,1,1};
    vector<int> test2{1,1,1,0,0,0,1,1,1,1,0};
    vector<int> test3{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    cout << s.longestOnes(test3,3) << endl;
    return 0;
}
