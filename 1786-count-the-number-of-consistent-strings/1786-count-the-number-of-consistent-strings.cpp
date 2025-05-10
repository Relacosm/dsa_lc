class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
         unordered_set<char> allowedSet(allowed.begin(), allowed.end());
        int count = 0;

        for (const string& word : words) {
            bool consistent = true;
            for (char ch : word) {
                if (allowedSet.find(ch) == allowedSet.end()) {
                    consistent = false;
                    break;
                }
            }
            if (consistent) {
                count++;
            }
        }

        return count;
    }
};