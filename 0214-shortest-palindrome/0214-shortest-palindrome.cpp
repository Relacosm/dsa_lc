class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "#" + rev;
        vector<int> lps(temp.size(), 0);

        // Compute the LPS (Longest Prefix Suffix) array
        for (int i = 1; i < temp.size(); i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }

        // The length of the longest palindromic prefix
        int longestPalindromicPrefix = lps.back();
        string toAdd = rev.substr(0, s.size() - longestPalindromicPrefix);
        return toAdd + s;

    }
};