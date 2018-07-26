class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int flag = 0;
        for (int i = n; i >= 1; i--) {
            for(int j = 0; j < n - i + 1; j++) {
                for(int k = 0; k < i; k++) {
                    if (s[j+k] != s[j+i-1-k]) {
                        break;
                    }
                    if (k == i - 1) {
                        return s.substr(j, i);
                    }
                }
            }
        }
        return "";
    }
};