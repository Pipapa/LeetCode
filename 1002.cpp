class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int table[26] = {0};
        int tmp[26] = {0};
        for(int i=0;i<26;++i) table[i]=0;
        for(int i=0;i<A[0].length();++i){
            table[A[0][i]-'a']++;
        }

        //
        for(int i=1;i<A.size();++i){
            for(int j=0;j<26;++j) tmp[j]=0;
            for(int j=0;j<A[i].length();++j){
                tmp[A[i][j]-'a']++;
            }
            for(int j=0;j<26;j++){
                table[j] = min(table[j],tmp[j]);
            }
        }
        //
        vector<string> result;
        for(int i=0;i<26;++i){
            for(int c=0;c<table[i];++c){
                result.push_back(string(1,char(i+'a')));
            }
        }
        return result;
    }
};