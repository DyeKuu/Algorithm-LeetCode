class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int f[2]; //f[i] is the maximum subarray which ends at i
        int res;
        res = f[0] = nums[0];
        for (int i = 1; i<nums.size();i++){
            if ( (f[i%2] = (f[(i-1)%2] < 0)? nums[i] : nums[i] + f[(i-1)%2]) > res)
                res = f[i%2];
            
        }
        return res;
    }
};