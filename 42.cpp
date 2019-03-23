class Solution {
public:
    int trap(vector<int>& height) {
        int idx = 0;
        int ret = 0;
        for(int i=1;i<height.size();++i){
            if(height[i]>=height[idx]) idx=i;
        }
        int lh=0,rh=0;
        for(int l=0;l<idx;++l){
            if(height[l] >= lh) lh = height[l];
            else{
                ret += (lh-height[l]);
            }
        }
        for(int r=height.size()-1;r>idx;--r){
            if(height[r] >= rh) rh = height[r];
            else{
                ret += (rh-height[r]);
            }
        }
        return ret;
    }
};
