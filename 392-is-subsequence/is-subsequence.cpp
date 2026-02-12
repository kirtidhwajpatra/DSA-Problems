class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for s
        int j = 0; // Pointer for t
        
        // Loop while there are characters left to check in both strings
        while (i < s.length() && j < t.length()) {


            // If the characters match, move the s pointer forward
            if (s[i] == t[j]) {
                i++;
            }



            // Always move the t pointer forward
            j++;


            
        }
        
        // If i equals the length of s, we found all characters
        return i == s.length();
    }
};