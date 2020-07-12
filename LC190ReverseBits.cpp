#include <stdint.h>

#include <algorithm>
#include <bitset>
#include <string>
using namespace std;
class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> bit(n);
        string bitstring =
            bit.to_string<char, string::traits_type, string::allocator_type>();
        reverse(bitstring.begin(), bitstring.end());
        bitset<32> reverse_bit(bitstring);
        return (uint32_t)reverse_bit.to_ulong();
    }
};
