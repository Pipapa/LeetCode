#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int tmparr[10];

    // merge the [l,m] and [m+1,r]
    int merge(int arr[],int l,int m,int r){
        int inversion = 0;
        int pl = l,pr = m+1,pos=0;
        while(pl<=m&&pr<=r){
            if(arr[pl]<=arr[pr]){
                tmparr[pos++] = arr[pl++];
            }else{
                tmparr[pos++] = arr[pr++];
                inversion += (m-pl+1);
            }
        }
        while(pl<=m) tmparr[pos++] = arr[pl++];
        while(pr<=m) tmparr[pos++] = arr[pr++];
        for(int i=0;i<pos;i++)
            arr[l+i] = tmparr[i];
        return inversion;
    }
    int mergesort(int arr[],int l,int r){
        int inversion = 0;
        if(l>=r) return inversion;
        int m = (l+r)/2;
        inversion += mergesort(arr,l,m);
        inversion += mergesort(arr,m+1,r);
        inversion += merge(arr,l,m,r);
        return inversion;
    }
    struct BoardMap{
        int arr[6];
        int white;
        int G;
        BoardMap():G(0){}
        BoardMap(vector<vector<int>>& board):G(0){
            int pos=0;
            for(int r=0;r<2;++r){
                for(int c=0;c<3;++c){
                    if(!board[r][c]) white = r*3+c;
                    arr[pos++] = board[r][c];
                }
            }
        }
        BoardMap move(int step){
            BoardMap nmap;
            nmap.G = G + 1;
            for(int i=0;i<6;i++){
                if(i==white) nmap.arr[white] = arr[white+step];
                else if(i==white+step) nmap.arr[white+step] = arr[white];
                else nmap.arr[i] = arr[i];
            }
            nmap.white = white+step;
            return nmap;
        }
        unsigned int toHash(){
            unsigned int hash=0;
            for(int i=0;i<6;i++)
                hash=hash*10+arr[i];
            return hash;
        }
    };
    // 判断是否能够还原,归并排序计算逆序数(偶数能够还原,奇数不能还原)
    bool judge(BoardMap& b){
        int pos = 0;
        int arr[5]={0};
        for(int i=0;i<6;i++){
            if(b.arr[i]) arr[pos++]=b.arr[i];
        }
        return bool(mergesort(arr,0,4)&1);
    }
    // dfs queue 搜索
    int slidingPuzzle(vector<vector<int>>& board) {
        BoardMap initm(board);
        if(judge(initm)) return -1;
        BoardMap m = initm.move(-3);
        queue<BoardMap> bmqueue;
        unordered_set<unsigned int> vis;
        vis.insert(initm.toHash());
        bmqueue.push(initm);
        unsigned int ansHash = 123450;
        while(!bmqueue.empty()){
            BoardMap tm = bmqueue.front();
            bmqueue.pop();
            if(tm.toHash() == ansHash) return tm.G;
            // 拓展路径
            if(tm.white-3>=0){
                BoardMap nm = tm.move(-3);
                if(vis.find(nm.toHash())==vis.end()) bmqueue.push(nm);
            }
            if(tm.white+3<=5){
                BoardMap nm = tm.move(3);
                if(vis.find(nm.toHash())==vis.end()) bmqueue.push(nm);
            }
            if((tm.white+1)%3){
                BoardMap nm = tm.move(1);
                if(vis.find(nm.toHash())==vis.end()) bmqueue.push(nm);
            }
            if(tm.white!=0 && tm.white!=3){
                BoardMap nm = tm.move(-1);
                if(vis.find(nm.toHash())==vis.end()) bmqueue.push(nm);
            }

        }
        return -1;
    }
};

int main(int argc,char *argv[]){
    Solution s;
    vector<vector<int>> test{
            {3,2,4},
            {1,5,0}
    };
    vector<vector<int>> test1{
            {1,2,3},
            {5,4,0}
    };
    vector<vector<int>> test2{
            {4,1,2},
            {5,0,3}
    };
    cout << s.slidingPuzzle(test) << endl;
    cout << s.slidingPuzzle(test1) << endl;
    cout << s.slidingPuzzle(test2) << endl;
    return 0;
}
