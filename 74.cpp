#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        if(matrix[0].size() == 0) return false;
        unsigned long row,col;
        row = matrix.size();
        col = matrix[0].size();
        int l = 0,r = row*col-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(target > matrix[mid/col][mid%col])
                l = mid+1;
            else if(target < matrix[mid/col][mid%col])
                r = mid-1;
            else
                return true;
        }
        return false;
    }
};


int main(int argc,char *argv[]){
    return 0;
}
