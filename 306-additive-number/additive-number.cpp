 class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        // Try all possible first two numbers
        // i is the end index of the first number
        for (int i = 1; i <= n / 2; ++i) {
            if (num[0] == '0' && i > 1) break; // Leading zero check
            
            // j is the end index of the second number
            for (int j = i + 1; n - j >= max(i, j - i); ++j) {
                if (num[i] == '0' && j - i > 1) break; // Leading zero check
                
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i);
                if (isValid(s1, s2, j, num)) return true;
            }
        }
        return false;
    }

private:
    bool isValid(string num1, string num2, int start, string& num) {
        if (start == num.size()) return true;
        
        string sum = addStrings(num1, num2);
        if (num.substr(start, sum.size()) != sum) return false;
        
        return isValid(num2, sum, start + sum.size(), num);
    }

    // Helper to handle potential overflow for the follow-up
    string addStrings(string n1, string n2) {
        string res = "";
        int i = n1.size() - 1, j = n2.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry + (i >= 0 ? n1[i--] - '0' : 0) + (j >= 0 ? n2[j--] - '0' : 0);
            res += to_string(sum % 10);
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
