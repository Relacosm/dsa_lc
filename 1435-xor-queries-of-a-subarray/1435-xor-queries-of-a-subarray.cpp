class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
         int n = arr.size();
    
    // Step 1: Compute the prefix XOR array
    vector<int> prefixXOR(n);
    prefixXOR[0] = arr[0];
    
    for (int i = 1; i < n; ++i) {
        prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
    }
    
    // Step 2: Process each query and store the result
    vector<int> answer;
    for (const auto& query : queries) {
        int left = query[0], right = query[1];
        if (left == 0) {
            answer.push_back(prefixXOR[right]);
        } else {
            answer.push_back(prefixXOR[right] ^ prefixXOR[left - 1]);
        }
    }
    
    return answer;
    }
};