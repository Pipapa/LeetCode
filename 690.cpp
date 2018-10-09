#include <vector>
#include <map>
using namespace std;

class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};

class Solution {
public:
    map<int,Employee*> m_map;
    int getImportance(vector<Employee*> employees, int id) {
        for(Employee* e:employees) m_map.insert(make_pair(e->id,e));
        return dfs(id);
    }
    int dfs(int i){
        Employee* e = m_map[i];
        int ans = e->importance;
        for(int _e:e->subordinates) ans += dfs(_e);
        return ans;
    }
};