class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        int lo = 0, hi = m, half_len = (m + n +1) / 2;
        while (lo <= hi) {
            int i = (lo + hi) / 2;
            int j = half_len - i;
            if (i < m && nums2[j-1] > nums1[i])
                lo = i + 1;
            else if (i > 0 && nums1[i-1] > nums2[j])
                hi = i - 1;
            else {
                int max_left = 0;
                int min_right = 0;
                
                if (i == 0) max_left = nums2[j-1];
                else if (j == 0) max_left = nums1[i-1];
                else max_left = max(nums1[i-1], nums2[j-1]);
                
                if ((n + m) % 2 == 1) return max_left;
                
                if (i == m) min_right = nums2[j];
                else if (j == n) min_right = nums1[i];
                else min_right = min(nums1[i],nums2[j]);
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0;
    }
};