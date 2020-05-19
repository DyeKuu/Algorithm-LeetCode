#include <algorithm>
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxValue = *std::max_element(candies.begin(),candies.end());
        vector<bool> result;
        for (int i = 0; i < candies.size(); i++){
            if (candies[i] + extraCandies >= maxValue)
                result.push_back(true);
            else
                result.push_back(false);
        }
        return result;
    }
};