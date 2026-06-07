//! ============================================== Brute Force ==============================================
Generate all permutations of the array using recursion and backtracking. 
Sort them lexicographically.
Find the current array in the sorted list. Return the permutation at the next index.
If current is the last permutation, return the first (wrap around using modulo).

TC = O(n! × n), Space = O(n!).

//! ============================================ Better Approach ============================================

next_permutation(nums.begin(), nums.end());

//! ============================================ Optimal Approach ===========================================

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }

        if( index == -1 ){
            reverse(nums.begin() , nums.end());
            return;
        }

        for(int i=n-1; i>index; i--){
            if(nums[i] > nums[index]){
                swap( nums[index] , nums[i] );
                break;
            }
        }

        reverse(nums.begin() + 1 + index , nums.end());
    }
};