#include <numeric>
#include <algorithm>
class Solution {
public:
    double average(vector<int>& salary) {
        size_t len = salary.size();
        int min = *std::min_element(salary.begin(),salary.end());
        int max = *std::max_element(salary.begin(),salary.end());
        int sum_of_elems = std::accumulate(salary.begin(), salary.end(), 0) - min - max;
        return sum_of_elems/(double)(len - 2);
    }
};