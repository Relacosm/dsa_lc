class Solution {
public:
    vector<int> lexicalOrder(int n) {
         std::vector<int> result;
        
        // Depth-first search function
        std::function<void(int)> dfs = [&](int curr) {
            if (curr > n) return;
            result.push_back(curr);
            for (int i = 0; i < 10; ++i) {
                int next_num = curr * 10 + i;
                if (next_num > n) break;
                dfs(next_num);
            }
        };
        
        // Start DFS from 1 to 9
        for (int i = 1; i < 10; ++i) {
            dfs(i);
        }
        
        return result;
    }
};