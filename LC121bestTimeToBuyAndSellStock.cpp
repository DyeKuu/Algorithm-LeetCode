class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 || prices.size() == 1) return 0;
        int n = prices.size(), buyday = 0;
        int F[2];
        F[0] = 0;
        for (int i = 1; i < n; i++){
            if (prices[i-1] < prices[buyday]) buyday = i-1;
            F[i%2] = std::max(F[(i-1)%2], prices[i]-prices[buyday]);
        }
        return F[(n-1)%2];
    }
};