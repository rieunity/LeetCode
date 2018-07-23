# Two Sum
## Description
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.
### Example
>Given nums = [2, 7, 11, 15], target = 9,
>
>Because nums[0] + nums[1] = 2 + 7 = 9,
>return [0, 1].
## Solutions
### solution
```cpp

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        for(int i = 0; i < l; i++)
            for(int j = i + 1; j < l; j++)
                if(nums[i] + nums[j] == target)
                    return {i,j};
    }
};
```
### solution1
```cpp
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
```