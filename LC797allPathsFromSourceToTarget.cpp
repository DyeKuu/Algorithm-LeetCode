#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> stack;
        dfs_visit(graph, 0, stack, res);
        return res;
    }

   private:
    void dfs_visit(vector<vector<int>>& graph, int start, vector<int>& stack,
                   vector<vector<int>>& res) {
        stack.push_back(start);
        if (start == graph.size() - 1)
            res.push_back(stack);
        else
            for (int next : graph[start]) dfs_visit(graph, next, stack, res);
        stack.pop_back();
    }
};
