#include <algorithm>
#include <vector>
using namespace std;
class Solution {
   public:
    int leastInterval(vector<char>& tasks, int n) {
        int dict[26] = {0};
        int mostFreq = 0;
        int numberMostFreq = 0;
        for (char c : tasks)
            mostFreq = (++dict[c - 65] > mostFreq) ? dict[c - 65] : mostFreq;
        for (int i : dict)
            if (i == mostFreq) numberMostFreq++;
        return tasks.size() +
               max(0, (mostFreq - 1) * (n - (numberMostFreq - 1)) -
                          ((int)tasks.size() - mostFreq * numberMostFreq));
    }
};
