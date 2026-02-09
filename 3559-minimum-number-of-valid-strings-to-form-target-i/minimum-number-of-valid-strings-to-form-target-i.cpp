struct Node {
    vector<Node*> a;
    Node() { a.resize(26, nullptr); }
};

struct Trie {
    Node* head;
    Trie() { head = new Node(); }
    void addWord(string s) {
        Node* nd = head;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int v = s[i] - 'a';
            if (nd->a[v] == nullptr)
                nd->a[v] = new Node();
            nd = nd->a[v];
        }
    }
};

class Solution {
public:
    const int INF = 1e8;
    int minValidStrings(vector<string>& a, string s) {
        int n = a.size();
        int m = s.size();
        Trie t;
        for (int i = 0; i < n; i++)
            t.addWord(a[i]);
        vector<int> dp(m + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < m; i++) {
            if(dp[i] == INF) continue;
            int len = m - i;
            Node* nd = t.head;
            for (int k = 1; k <= len; k++) {
                if(nd -> a[s[i + k - 1] - 'a'] == nullptr) break;
                dp[i + k] = min(dp[i + k], dp[i] + 1);
                nd = nd -> a[s[i + k - 1] - 'a'];
            }
        }
        if(dp[m] == INF) return -1;
        return dp[m];
    }
};