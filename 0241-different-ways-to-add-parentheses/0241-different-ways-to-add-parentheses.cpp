class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;

        // Iterate through the expression to find operators
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            // If the current character is an operator
            if (c == '+' || c == '-' || c == '*') {
                // Divide the expression into two parts: left and right
                string left = expression.substr(0, i);
                string right = expression.substr(i + 1);

                // Recursively compute all possible results for the left and right parts
                vector<int> leftResults = diffWaysToCompute(left);
                vector<int> rightResults = diffWaysToCompute(right);

                // Combine results from the left and right sides using the current operator
                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If no operator is found, it's a single number, so convert it and return
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        return result;
    }
};