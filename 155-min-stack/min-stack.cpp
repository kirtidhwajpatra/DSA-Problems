class MinStack {
    long long mn;
    std::vector<long long> st;

public:
      MinStack() {}

       void push(int val) {
        if (st.empty()) {

            mn = val;
            st.push_back(0);

        } else {
            long long diff = val - mn;
            st.push_back(diff);
            if (diff < 0) mn = val;
        }
    }



    void pop()  {
        long long diff = st.back();
        st.pop_back();
           if (diff < 0) mn -= diff;
    }

    int top() {

        
        long long diff = st.back();
        return diff < 0 ? mn : mn + diff;
    }

    int getMin() {
        return mn;
    }
};
