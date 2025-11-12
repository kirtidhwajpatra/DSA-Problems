class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> result;
        string curr;
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(k);
                result.push(curr);
                k = 0;
                curr.clear();
            } else if (c == ']') {
                string temp = curr;
                curr = result.top();
                result.pop();
                int repeat = counts.top();
                counts.pop();
                while (repeat--) curr += temp;
            } else {
                curr += c;
            }
        }
        return curr;
    }
};
