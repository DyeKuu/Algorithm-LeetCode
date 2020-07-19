#include <map>
#include <vector>

using namespace std;
class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> G;
        vector<int> visited(numCourses, -1);
        for (int i = 0; i < prerequisites.size(); i++) {
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
            visited[prerequisites[i][0]] = 0;
        }
        vector<int> res;
        if (!dfs(G, visited, res) || res.size() < numCourses) res.clear();
        reverse(res.begin(), res.end());
        return res;
    }

   private:
    bool dfs(map<int, vector<int>>& G, vector<int>& visited, vector<int>& res) {
        for (int i = 0; i < visited.size(); i++)
            if (visited[i] == -1 && !dfs_visit(G, i, visited, res))
                return false;
        return true;
    }
    bool dfs_visit(map<int, vector<int>>& G, int u, vector<int>& visited,
                   vector<int>& res) {
        visited[u] = 1;
        for (int i = 0; i < G[u].size(); i++) {
            if (visited[G[u][i]] == 1) return false;
            if (visited[G[u][i]] <= 0 && !dfs_visit(G, G[u][i], visited, res))
                return false;
        }
        visited[u] = 2;
        res.push_back(u);
        return true;
    }
};
