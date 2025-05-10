class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0"; // Edge case: if the number is zero

        string hexChars = "0123456789abcdef";
        string hexStr;
        
        unsigned int n = static_cast<unsigned int>(num); // Convert to unsigned to handle negative numbers
        while (n > 0) {
            hexStr = hexChars[n % 16] + hexStr; // Prepend the character corresponding to the last 4 bits
            n /= 16; // Divide by 16 to shift right
        }
        
        return hexStr;
    }
};
