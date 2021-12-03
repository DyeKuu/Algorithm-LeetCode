#include <string>

class Solution {
   public:
    inline bool check_overflow_pos(int a[], int i) {
        int b[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
        if (i < 10) return true;
        if (i > 10) return false;
        for (int p = 0; p < 10; p++) {
            if (a[p] < b[p]) {
                return true;
            } else if (a[p] > b[p]) {
                return false;
            }
        }
        return true;
    }
    inline bool check_overflow_neg(int a[], int i) {
        int b[10] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
        if (i < 10) return true;
        if (i > 10) return false;
        for (int p = 0; p < 10; p++) {
            if (a[p] < b[p]) {
                return true;
            } else if (a[p] > b[p]) {
                return false;
            }
        }
        return true;
    }
    inline bool check_overflow(int a[], int i, bool sign) {
        return sign ? check_overflow_pos(a, i) : check_overflow_neg(a, i);
    }
    int myAtoi(string s) {
        int j = 0, l = s.length(), k = 0, i[200];
        while (s[j] == ' ' && j < l) j++;
        if (s[j] != '+' && s[j] != '-' && (s[j] < 48 || s[j] > 57)) return 0;
        bool sign = true;
        switch (s[j]) {
            case '-':
                sign = false;
                j++;
                break;
            case '+':
                j++;
        }
        if (s[j] < 48 || s[j] > 57) return 0;
        while (s[j] == '0') j++;
        while (j < l && 48 <= s[j] && s[j] <= 57) i[k++] = s[j++] - 48;
        int res = 0;
        if (!check_overflow(i, k, sign)) return sign ? 2147483647 : -2147483648;
        for (int p = 0; p < k; p++) {
            res = sign ? (10 * res + i[p]) : (10 * res - i[p]);
        }
        return res;
    }
};
