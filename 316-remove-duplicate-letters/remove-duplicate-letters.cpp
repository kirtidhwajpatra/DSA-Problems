class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        vector<int> lastIndex(26);
        vector<bool> seen(26, false);
        stack<char> st;
        


        

        for(int i = 0; i < s.size(); i++){


            lastIndex[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < s.size(); i++){
            char current = s[i];
            
    
            if(seen[current - 'a']) continue;

            while(!st.empty() && 


                  st.top() > current && 
                  lastIndex[st.top() - 'a'] > i){
                
                seen[st.top() - 'a'] = false;
                st.pop();
            }


            
            st.push(current);
            seen[current - 'a'] = true;
        }


        
        string result = "";
        while(!st.empty()){
            result += st.top();
            st.pop();
        }


        
        reverse(result.begin(), result.end());
        return result;
    }
};
