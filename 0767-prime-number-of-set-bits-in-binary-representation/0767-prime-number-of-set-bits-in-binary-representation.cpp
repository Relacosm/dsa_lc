class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        // Precomputed bitmask for prime numbers up to 32 (binary: 10100010100010101100)
        const int primeMask = 0b10100010100010101100;
        int count = 0;

        for (int num = left; num <= right; num++) {
            // Count the number of set bits in `num`
            int setBits = __builtin_popcount(num); // Built-in function to count set bits
            // Check if the number of set bits is prime using the precomputed bitmask
            if (primeMask & (1 << setBits)) {
                count++;
            }
        }

        return count;
    }
};
