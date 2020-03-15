#include <iostream>
#include <bitset>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		const int numBits = 32;
		uint32_t output = 0;
		for(int i = 0; i < numBits; ++i) {
			output |= (n & 1) << (numBits - i - 1);
			n >>= 1;
		}
		return output;
	}
};

int main() {
	uint32_t input = 1;
	input = input << 31;

	Solution sol;
	cout << sol.reverseBits(input);
}