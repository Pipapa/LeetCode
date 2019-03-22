
class Solution {
public:
    int F[202] = {0};

    int Find(int x){
        if(x == F[x]) return x;
        F[x]=Find(F[x]);
        return F[x];
    }

    void Union(int x,int y){
        x = Find(x);
        y = Find(y);
        F[x] = y;
    }

    int findCircleNum(vector<vector<int>>& M) {
        for(int i=0;i<202;++i) F[i]=i;
        int num = M.size();
        for(int r=0;r<M.size();++r){
            for(int c=0;c<M.size();++c){
                if(c == r) continue;
                if(M[r][c]){
                    Union(r,c);
                }
            }
        }
        int ret = 0;
        for(int i=0;i<num;++i){
            if(F[i] == i) ret++;
        }
        return ret;
    }
};
