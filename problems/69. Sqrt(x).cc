#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        
        // Binary search: 1 to x/2
        int left = 1;
        int right = x/2;
        
        while(left <= right) {
            double mid = (left + right) / 2;
            
            if(mid*mid <= x && (mid+1)*(mid+1) > x) {
                return mid;
            } else if ((mid+1)*(mid+1) <= x) {
                left = mid + 1;
            } else {    // mid*mid > x
                right = mid -1;
            }
        }
        
        return left;
    }
};

int main(){
    Solution sol;
    std::cout << sol.mySqrt(INT_MAX);
}