class Solution {
   public:
    int majorityElement(vector<int>& nums) {
        map<int, int> M;
        int res = nums[0];
        int times = 0;
        for (auto i = nums.begin(); i != nums.end(); i++) {
            if (M.find(*i) != M.end()) {
                if ((M[*i] = M[*i] + 1) >= times) {
                    times = M[*i];
                    res = *i;
                }
            } else {
                M.insert(pair<int, int>(*i, 1));
            }
        }
        return res;
    }
};