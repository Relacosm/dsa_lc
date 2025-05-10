class Solution {
public:
    // Helper function to count how many numbers exist with the current prefix
    int countSteps(long curr, long n) {
        long steps = 0;
        long first = curr;
        long last = curr;
        
        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }
        
        return steps;
    }

    // Main function to find the k-th lexicographically smallest number
    int findKthNumber(int n, int k) {
        long curr = 1;  // Start at the smallest number (lexicographically smallest)
        k--;            // Because we count the first number (1) as already taken

        while (k > 0) {
            int steps = countSteps(curr, n);
            
            if (steps <= k) {  // If there are fewer than k steps, skip this whole subtree
                k -= steps;
                curr++;  // Move to the next prefix
            } else {     // Else, delve into this prefix
                curr *= 10;
                k--;  // Move down the tree (prefix "curr")
            }
        }

        return curr;
    }
};
