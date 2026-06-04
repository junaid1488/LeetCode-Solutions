class Solution {
public:
    // Memoization map to store already computed results
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {

        // Return cached result if expression is already solved
        if (memo.count(expression))
            return memo[expression];

        vector<int> result;

        // Traverse the expression to find operators
        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            // If current character is an operator
            if (op == '+' || op == '-' || op == '*') {

                // Split expression into left and right parts
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);

                // Recursively compute all possible results
                // for left and right subexpressions
                vector<int> left = diffWaysToCompute(leftPart);
                vector<int> right = diffWaysToCompute(rightPart);

                // Combine every left result with every right result
                for (int l : left) {
                    for (int r : right) {

                        // Apply the current operator
                        if (op == '+')
                            result.push_back(l + r);
                        else if (op == '-')
                            result.push_back(l - r);
                        else
                            result.push_back(l * r);
                    }
                }
            }
        }

        // Base case:
        // If no operator is found, expression is a number
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        // Store result in memo and return
        return memo[expression] = result;
    }
};
