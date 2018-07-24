class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        unordered_set<char> record;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if(record.count(s[j]) == 0) {
                record.emplace(s[j++]);
                ans = ans > record.size() ? ans : record.size();
            } else {
                record.erase(s[i++]);
            }          
        }
        return ans;
    }
};