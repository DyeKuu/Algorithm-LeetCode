class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 1;
        int len = 0;
        for (;count <= n; count++) {
            if (n%count == 0){
               len++;
               if (len==k) return count;
            }
        }
        return -1;
    }
};