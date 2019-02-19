//@ a*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int boardmap[4][4];
vector<char> path;

const char* notsolve = "This puzzle is not solvable.";
const int ox[4] = {0,0,1,-1};
const int oy[4] = {1,-1,0,0};
const char dir[4] = {'R','L','D','U'};

int zr,zc;

inline int abs(int a){
    return a>=0?a:-a;
}

// 估值函数
int H(){
    int h=0;
    for(int r=0;r<4;++r){
        for(int c=0;c<4;++c){
            if(boardmap[r][c] == 0) continue;
            int er = (boardmap[r][c]-1)/4;
            int ec = (boardmap[r][c]-1)%4;
            h += abs(er-r) + abs(ec-c);
        }
    }
    return h;
}

// g 层数
// predir 移动方向
// bound 最大步数
bool dfs(int g,int predir,int bound){
    int h = H();
    if(h == 0) return true;
    if(h + g > bound) return false;

    for(int i=0;i<4;i++){
        // 不走回头路 1 - 3 0 - 2 相对
        if(i == (predir^1)) continue;
        int nr = zr + ox[i];
        int nc = zc + oy[i];
        if(nr<0 || nr>=4) continue;
        if(nc<0 || nc>=4) continue;
        path.push_back(dir[i]);

        swap(boardmap[zr][zc],boardmap[nr][nc]);
        swap(zr,nr);swap(nc,zc);

        if(dfs(g+1,i,bound)) return true;

        // 还原
        swap(zr,nr);swap(nc,zc);
        swap(boardmap[zr][zc],boardmap[nr][nc]);
        path.pop_back();
    }
    return false;
}

bool ida_star(){
     // 最多50步
    for(int limit = H();limit <= 50 ; ++limit){
        if(dfs(0,-1,limit)) return true;
    }
    return false;
}


bool solvable(){
    int N = 0;
    bool occur[16] = {false};
    for(int r=0;r<4;++r){
        for(int c=0;c<4;++c){
            if(boardmap[r][c] == 0){
                zr = r, zc = c;
            }else{
                N += count(occur+1,occur+boardmap[r][c], false);
                occur[boardmap[r][c]] = true;
            }
        }
    }
    return ((N+(zr+1))&1) == 0;
}

int main(int argc,char *argv[]){
    int n;
    scanf("%d",&n);
    while(n--){
        for(int r=0;r<4;++r) {
            for (int c = 0; c < 4; ++c) {
                scanf("%d", &boardmap[r][c]);
            }
        }

        path.clear();
        if(!solvable() || !ida_star()){
            printf("%s\n",notsolve);
        }else{
            for(int i=0;i<path.size();++i){
                printf("%c",path[i]);
            }
            printf("\n");
        }

    }
    return 0;
}
