class Solution {
   public:
    static inline int lengthOfLongestSubstring(string s) {
        vector<int> charmap(256, -1);
        int longest = 0, m = 0;

        for (int i = 0; i < s.length(); i++) {
            m = max(charmap[s[i]] + 1, m);
            charmap[s[i]] = i;
            longest = max(longest, i - m + 1);
        }
        return longest;
    }
};
