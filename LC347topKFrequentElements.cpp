#include <algorithm>
#include <map>
#include <utility>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> M;
        for (int i = 0; i < nums.size(); i++) {
            M[nums[i]]++;
        }
        vector<pair<int, int>> V;
        for (auto i = M.begin(); i != M.end(); i++) {
            pair<int, int> p(i->second, i->first);
            V.push_back(p);
        }
        sort(V.begin(), V.end());
        vector<int> res;
        for (auto i = V.rbegin(); i != V.rend(); i++) {
            res.push_back(i->second);
            if (res.size() == k) break;
        }
        return res;
    }
};
