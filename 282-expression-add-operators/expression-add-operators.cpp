class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        string path;
        backtrack(num, target, 0, 0, 0, path, result);
        return result;
    }
    
private:
    void backtrack(string& num, int target, int pos, long long eval, long long prev, string& path, vector<string>& result) {
        if (pos == num.length()) {
            if (eval == target) {
                result.push_back(path);
            }
            return;
        }
        
        for (int i = pos; i < num.length(); i++) {
            // Skip numbers with leading zeros
            if (i != pos && num[pos] == '0') break;
            
            string currStr = num.substr(pos, i - pos + 1);
            long long curr = stoll(currStr);
            int len = path.length();
            
            if (pos == 0) {


                // First number, no operator needed
                path += currStr;
                backtrack(num, target, i + 1, curr, curr, path, result);
                path.resize(len);


            } else {


                // Try '+'
                path += "+" + currStr;
                backtrack(num, target, i + 1, eval + curr, curr, path, result);
                path.resize(len);


                
                // Try '-'
                path += "-" + currStr;


                backtrack(num, target, i + 1, eval - curr, -curr, path, result);
                path.resize(len);
                
                // Try '*'
                path += "*" + currStr;
                backtrack(num, target, i + 1, eval - prev + prev * curr, prev * curr, path, result);
                path.resize(len);
            }
        }




        
    }
};