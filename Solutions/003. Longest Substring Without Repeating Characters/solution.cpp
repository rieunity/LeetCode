class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int max = 0;
        unordered_set<char> record;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                auto found = record.find(s[j]);
                if (found != record.end()) {
                    if(record.size() > max) {
                        max = record.size();
                    }
                    break;
                }
                if (j == n - 1) {
                    record.emplace(s[j]);
                    if(record.size() > max) {
                        max = record.size();
                    }
                } else {
                    record.emplace(s[j]);
                }
            }
            record.clear();
        }
        return max;
    }
};