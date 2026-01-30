class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        if (nums1.empty() || nums2.empty() || k == 0) return result;

        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;


        for (int i = 0; i < min((int)nums1.size(), k); i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!pq.empty() && k--) {


            auto top = pq.top(); pq.pop();
            int i = top.second.first;
            int j = top.second.second;
            result.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size()) {

                pq.push({nums1[i] + nums2[j + 1], {i, j + 1}});

                
            }
        }

        return result;
    }
};