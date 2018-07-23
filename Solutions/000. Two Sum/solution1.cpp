class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        int length = nums.size();
        for(int i = 0; i < length; i++) {
            auto found = record.find(nums[i]);
            if(found != record.end())
                return {found -> second, i};
            record.emplace(target-nums[i], i);
        }
        return {-1, -1};
    }
};