class Solution {
public:
    vector<string> ans;

    void generate(string curr, int open, int close, int n) {

        // Valid complete combination
        if (curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // We can add '('
        if (open < n) {
            generate(curr + '(', open + 1, close, n);
        }

        // We can add ')' only when it is safe
        if (close < open) {
            generate(curr + ')', open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return ans;
    }
};