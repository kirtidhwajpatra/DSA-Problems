
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        if(set<int>(nums.begin(),nums.end()).size() < nums.size()){
            return true;
        }
        return false;

    }
};


