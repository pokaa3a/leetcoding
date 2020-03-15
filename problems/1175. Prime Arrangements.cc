#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

/* Solution */
class Solution {
public:
    int numPrimeArrangements(int n) {
        int prime_count = 0;
        for (int i = 1; i <= n; ++i) {
        	if (isPrime(i)) prime_count++;
        }
        long long a = factorial(prime_count);
        long long b = factorial(n - prime_count);
        long long res = (a * b) % MOD;
        return (int)res;
    }
    bool isPrime(int n) {
    	if (n == 1) return false;
    	for (int i = 2; i * i <= n; ++i) {
    		if (n % i == 0) return false;
    	}
    	return true;
    }
   	long long factorial(int n) {
   		long long ans = 1;
   		for (int i = 1; i <= n; ++i) {
   			ans = (ans * i) % MOD;
   		}
   		return ans % MOD;
   	}
};

int main() {
	Solution sol;
	cout << sol.numPrimeArrangements(100) << endl;
}