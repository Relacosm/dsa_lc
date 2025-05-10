class Solution {
public:
    int minBitFlips(int start, int goal) {
        int differingBits = start ^ goal;
        
        // Count the number of 1's in the differingBits
        int count = 0;
        while (differingBits > 0) {
            count += differingBits & 1;
            differingBits >>= 1;
        }
        
        return count;
    }
};