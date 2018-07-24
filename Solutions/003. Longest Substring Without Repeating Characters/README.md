# Longest Substring Without Repeating Characters
## Description
Given a string, find the length of the longest substring without repeating characters.
### Examples
>Given "abcabcbb", the answer is "abc", which the length is 3.
>
>Given "bbbbb", the answer is "b", with the length of 1.
>
>Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
## Solutions 
### solution
```cpp
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
```
solution1
```cpp
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
```
solution2
```cpp
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
```
solution3
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int* a = new int[257]();
        int ans = 0;
        int n = s.size();
        for (int j = 0, i = 0; j < n; j++) {
            i = i > a[s[j]] ? i : a[s[j]];
            ans = ans > j - i +1 ? ans : j - i + 1;
            a[s[j]] = j + 1;
        }
        return ans;
    }
};
```