#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    struct Position{
        int i,j;
        Position():i(0),j(0){}
        Position(int i,int j):i(i),j(j){}
    };
    vector<vector<bool>> vis;
    unsigned long row,col;
    int offsetr[4] = {-1,1,0,0};
    int offsetc[4] = {0,0,-1,1};
    unordered_map<char,vector<Position>> cmap;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        set<string> result;
        row=board.size(),col=board[0].size();
        // 初始化搜索表
        vis.resize(row);
        for(int i=0;i<row;++i){
            vis[i].resize(col);
            for(int c=0;c<col;++c) vis[i][c]=false;
        }
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(cmap.find(board[i][j])!=cmap.end()){
                    cmap[board[i][j]].push_back(Position(i,j));
                }else{
                    vector<Position> p;
                    p.emplace_back(Position(i,j));
                    cmap.insert(make_pair(board[i][j],p));
                }
            }
        }
        for(string str:words){
            unordered_map<char,vector<Position>>::iterator it;
            it = cmap.find(str[0]);
            if(it==cmap.end()) continue;
            vector<Position> tmpv = it->second;
            for(Position p:tmpv){
                if(search(board,p.i,p.j,str,1)){
                    result.insert(str);
                    continue;
                }
            }
        }
        vector<string> ans(result.begin(),result.end());
        return ans;
    }
    bool search(vector<vector<char>>& board,int x,int y,string& str,int pos){
        // 到达字符串最后一层 return true
        if(pos >= str.length()) return true;
        vis[x][y] = true;
        // 查找4周
        for(int i=0;i<4;i++){
            int dx = offsetc[i]+x,dy = offsetr[i]+y;
            if(dx>=0&&dx<row&&dy>=0&&dy<col&&board[dx][dy]==str[pos]&&vis[dx][dy]==false){
                if(search(board,dx,dy,str,pos+1)) {
                    vis[x][y] = false;
                    return true;
                }
            }
        }
        // 回溯
        vis[x][y] = false;
        return false;
    }
};

int main(int argc,char* argv[]){
    int arr[4][4] = {
        'o','a','a','n',
        'e','t','a','e',
        'i','h','k','r',
        'i','f','l','v'
    };
    vector<vector<char>> board;
    for(int i=0;i<4;i++){
        board.push_back(vector<char>(arr[i],arr[i]+4));
    }
    vector<string> words{"oath","pea","eat","rain","eat"};
    Solution s;
    vector<string> ans = s.findWords(board,words);
    for(string str:ans){
        cout << str << endl;
    }
    return 0;
}
