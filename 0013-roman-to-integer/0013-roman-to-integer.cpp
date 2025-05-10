#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        for (char c : s) {
            int currentValue = romanValues[c];
            
            if (currentValue > prevValue) {
                total += currentValue - 2 * prevValue; // Adjust for the previously added value
            } else {
                total += currentValue;
            }
            
            prevValue = currentValue;
        }

        return total;
    }
};
