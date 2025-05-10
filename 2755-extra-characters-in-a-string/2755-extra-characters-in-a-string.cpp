class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
    int n = s.size();
    
    // dp[i] will store the minimum number of extra characters for substring s[i..n-1]
    vector<int> dp(n + 1, 0);

    // Start filling dp array from the end of the string
    for (int i = n - 1; i >= 0; --i) {
        dp[i] = dp[i + 1] + 1; // Assume the current character is an extra character
        for (int j = i; j < n; ++j) {
            string substr = s.substr(i, j - i + 1);
            if (dict.find(substr) != dict.end()) {
                dp[i] = min(dp[i], dp[j + 1]);
            }
        }
    }
    
    return dp[0]; // Return the result for the entire string
    }
};