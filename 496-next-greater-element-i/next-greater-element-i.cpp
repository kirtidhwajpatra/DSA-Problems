class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;

        stack<int> st;
        

        for (int x : nums2) {


            while (!st.empty() && x > st.top()) {
                next[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }


        vector<int> ans;


        for (int x : nums1)
            ans.push_back(next.count(x) ? next[x] : -1);

        return ans;
    }
};
