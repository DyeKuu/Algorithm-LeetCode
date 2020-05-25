class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto ps = s.begin();
        auto pt = t.begin();
        while (pt != t.end()){
            if(*pt++ == *ps)
                ps++;
        }
        return (ps == s.end())? true : false;
    }
};