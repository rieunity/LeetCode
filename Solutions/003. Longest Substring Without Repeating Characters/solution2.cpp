class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), ans = 0, i = 0;
        unordered_map<char, int> record;
        for(int j = 0; j < n; j++) {
            if(record.find(s[j]) != record.end()) {
                int tmp = (record.find(s[j]))->second + 1;
                i = tmp > i ? tmp : i;
            }
            ans = j - i + 1 > ans ? j - i + 1 : ans;
            record[s[j]] = j;
        }
        return ans;
    }
};