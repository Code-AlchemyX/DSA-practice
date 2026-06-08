//! =============================================== Brute Force ===============================================
//* Using Extra Space

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(m + n);
        int left = 0;
        int right = 0;
        int index = 0;
        
        while (left < m && right < n) {
            if (nums1[left] <= nums2[right]) {
                nums3[index] = nums1[left];
                index++;
                left++;
            } else {
                nums3[index] = nums2[right];
                index++;
                right++;
            }
        }
        
        while (left < m) {
            nums3[index++] = nums1[left++];
        }
        
        while (right < n) {
            nums3[index++] = nums2[right++];
        }
        
        //! If the qs HAS NOT given "nums1" extra size to store "nums2" into it.
        // for (int i = 0; i < m + n; i++) {
        //     if(i<m){
        //         nums1[i] = nums3[i];
        //     }
        //     else {
        //         nums2[i-n] = nums3[i];
        //     }
        // }

        //! If the qs HAS GIVEN "nums1" extra size to store "nums2" into it. [acc. to Leetcode qs]
        // for (int i = 0; i < m + n; i++) {
        //     nums1[i] = nums3[i];
        // }
    }
};

//! ========================================= Optimal Approach - 1 ========================================= 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;
        int right = 0;
        
        while (left >= 0 && right < n) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--, right++;
            } else {
                break;
            }
        }
        
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        
        // ONLY FOR LEETCODE qs : Manually move everything from nums2 into the back of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};

//! ========================================= Optimal Approach - 2 ========================================= 
//* Gap method.


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // m = nums1 size
        // n = nums2 size

        int len = m + n;
        int gap = (len / 2) + (len % 2);    // Round-up trick [ceiling function].
        
        while (gap > 0) {
            int left = 0;
            int right = left + gap;
            
            while (right < len) {
                // Case 1: left pointer is in nums1, right pointer is in nums2
                if (left < m && right >= m) {
                    if (nums1[left] > nums2[right - m]) {
                        swap(nums1[left], nums2[right - m]);
                    }
                }
                // Case 2: both pointers are in nums2
                else if (left >= m) {
                    if (nums2[left - m] > nums2[right - m]) {
                        swap(nums2[left - m], nums2[right - m]);
                    }
                }
                // Case 3: both pointers are in nums1
                else {
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                left++, right++;
            }
            
            if (gap == 1) break;
            gap = (gap / 2) + (gap % 2);
        }
        
        // ONLY FOF LEETCODE qs : Bring the elements from nums2 into the back of nums1
        for (int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }
    }
};