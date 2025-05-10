class Solution {
public:
    vector<string> simplifiedFractions(int n) {
         vector<string> result;
        
        for (int q = 2; q <= n; ++q) {
            for (int p = 1; p < q; ++p) {
                if (__gcd(p, q) == 1) {  // Check if p and q are co-prime
                    result.push_back(to_string(p) + "/" + to_string(q));
                }
            }
        }
        
        return result;
    }
};