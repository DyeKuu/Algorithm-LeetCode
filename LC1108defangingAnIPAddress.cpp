#include <string>
class Solution {
public:
    string defangIPaddr(string address) {
        std::string res = address;
        std::string::size_type position = 0;
        while( (position = res.find(".",position)) != string::npos){
            res.replace(position,1,"[.]");
            position += 2;
        }
        return res;
    }
};