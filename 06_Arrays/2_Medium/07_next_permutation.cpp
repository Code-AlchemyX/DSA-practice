//! ============================================== Brute Force ==============================================
Generate all permutations of the array using recursion and backtracking. Sort them lexicographically. Find the current array in the sorted list. Return the permutation at the next index. If current is the last permutation, return the first (wrap around using modulo).

TC = O(n! × n), Space = O(n!).

//! ============================================ Better Approach ============================================

next_permutation(nums.begin(), nums.end());

//! ============================================ Optimal Approach ===========================================
