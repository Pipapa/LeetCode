#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ret = 0;
        vector<vector<bool>> visited;

        visited.resize(r);
        for(int i=0;i<r;++i){
            visited[i].resize(c);
            for(int j=0;j<c;++j) visited[i][j] = false;
        }

        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(grid[i][j] == 0) continue;
                if(visited[i][j]) continue;
                int cnt = 1;
                visited[i][j] = true;
                queue<int> vqueue;
                vqueue.push(i*c+j);

                while(!vqueue.empty()){
                    int nv = vqueue.front();
                    vqueue.pop();

                    int nr = nv / c;
                    int nc = nv % c;

                    for(int k=0;k<4;++k){
                        int nextr = nr + dx[k];
                        int nextc = nc + dy[k];
                        if(nextr < 0 || nextr >= r) continue;
                        if(nextc < 0 || nextc >= c) continue;
                        if(grid[nextr][nextc] == 0) continue;
                        if(visited[nextr][nextc]) continue;
                        visited[nextr][nextc] = true;
                        cnt++;
                        vqueue.push(nextr*c+nextc);
                    }

                }

                ret = max(ret,cnt);
            }
        }
        return ret;

    }
};

int main(){
    vector<vector<int>> test{
            {0,0,1,0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,1,1,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,1,0,0},
            {0,1,0,0,1,1,0,0,1,1,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    Solution s;
    s.maxAreaOfIsland(test);
    return 0;
}
