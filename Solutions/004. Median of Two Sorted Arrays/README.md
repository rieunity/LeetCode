# Median of Two Sorted Arrays
## Description
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
### Examples
#### Example 1:
>nums1 = [1, 3]
>nums2 = [2]
>
>The median is 2.0
#### Example 2:
>nums1 = [1, 2]
>nums2 = [3, 4]
>
>The median is (2 + 3)/2 = 2.5
## Solutions
### solution
```cpp
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
```
### solution1
```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m) 
            return findMedianSortedArrays(nums2, nums1);
        int L1, R1, L2, R2, c1, c2, lo = 0, hi = 2 * n;
        while (lo <= hi) {
            c1 = (lo + hi) / 2;
            c2 = m + n -c1;
            L1 = (c1 == 0) ? INT_MIN : nums1[(c1-1)/2];
            R1 = (c1 == 2*n) ? INT_MAX : nums1[c1/2];
            L2 = (c2 == 0) ? INT_MIN : nums2[(c2-1)/2];
            R2 = (c2 == 2*m) ? INT_MAX : nums2[c2/2];
            
            if (L1 > R2)
                hi = c1 - 1;
            else if (L2 > R1)
                lo = c1 + 1;
            else 
                break;
        }
        return (max(L1,L2) + min(R1,R2)) / 2.0;
    }
};
```