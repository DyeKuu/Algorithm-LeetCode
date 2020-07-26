#include <vector>
using namespace std;
class Solution {
   public:
    int findMin(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }

   private:
    int binarySearch(vector<int>& nums, int begin, int end) {
        if (nums[begin] < nums[end] || begin == end) return nums[begin];
        int mid = (begin + end) / 2;
        if (nums[begin] <= nums[mid])
            return binarySearch(nums, mid + 1, end);
        else
            return binarySearch(nums, begin, mid);
    }
};
