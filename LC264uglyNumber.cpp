#include <iostream>
#include <string>
class Solution {
   public:
    static inline int nthUglyNumber(int n) {
        if (n == 1) return 1;
        unsigned int res[1691] = {0}, l1[1691] = {0}, l2[1691] = {0},
                     l3[1691] = {0};
        short p = 0, p1 = 0, p2 = 0, p3 = 0;
        res[p++] = 1;
        while (p < n) {
            l1[p - 1] = res[p - 1] * 2, l2[p - 1] = res[p - 1] * 3,
                   l3[p - 1] = res[p - 1] * 5;
            res[p++] = whichIsSmaller(l1, l2, l3, &p1, &p2, &p3);
        }
        return res[n - 1];
    }

   private:
    static inline int whichIsSmaller(unsigned int* l1, unsigned int* l2,
                                     unsigned int* l3, short* p1, short* p2,
                                     short* p3) {
        if (l1[*p1] == l2[*p2]) ++*p1;
        if (l1[*p1] == l3[*p3]) ++*p3;
        if (l2[*p2] == l3[*p3]) ++*p2;
        return (l1[*p1] < l2[*p2])
                   ? (l3[*p3] < l1[*p1]) ? l3[(*p3)++] : l1[(*p1)++]
                   : (l3[*p3] < l2[*p2]) ? l3[(*p3)++] : l2[(*p2)++];
    }
};
