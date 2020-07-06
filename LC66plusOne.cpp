class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int overflow = 1;
        for (int i = digits.size() - 1; i >= 0; i--){
            int sum = digits[i] + overflow;
            digits[i] = sum % 10;
            overflow = sum / 10;
        }
        if (overflow != 0) {
            digits.emplace(digits.begin(), overflow);
        }
        return digits;
    }
};