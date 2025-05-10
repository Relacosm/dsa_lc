class Solution {
public:
    int findTheLongestSubstring(string s) {
        std::unordered_map<char, int> vowels = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};
    int mask = 0;
    int max_len = 0;
    // Map to store first occurrence of each bitmask
    std::unordered_map<int, int> pos;
    pos[0] = -1;  // Initialize with mask 0 at index -1
    
    for (int i = 0; i < s.size(); ++i) {
        if (vowels.count(s[i])) {
            // Toggle the bit corresponding to the vowel
            mask ^= (1 << vowels[s[i]]);
        }
        
        if (pos.count(mask)) {
            max_len = std::max(max_len, i - pos[mask]);
        } else {
            pos[mask] = i;
        }
    }
    
    return max_len;
    }
};