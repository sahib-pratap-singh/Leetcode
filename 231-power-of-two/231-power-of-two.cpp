class Solution {
public:
    bool isPowerOfTwo(long n) {
        return n and !(n&(n-1));
    }
};