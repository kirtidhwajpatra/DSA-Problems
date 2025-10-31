class Solution {
public:
    vector<string> result;

    void backtrack(string current, int open, int close, int n) {
        // Base case: if the current string is of length 2*n, it’s valid
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we still have open brackets left
        if (open < n)
            backtrack(current + "(", open + 1, close, n);

        // Add ')' if we can close more than we've opened
        if (close < open)
            backtrack(current + ")", open, close + 1, n);
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return result;
    }
};
