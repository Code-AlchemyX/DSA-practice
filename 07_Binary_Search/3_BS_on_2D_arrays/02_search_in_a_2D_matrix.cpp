//! Brute Force ----> Linear search 

//! Better  approach --> Staircase method --> TC = O(log(m+n))

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] > target) {
                col--; 
            }
            else {
                row++; 
            }
        }

        return false;
    }
};

//!============================================ Optimal  Approach ============================================

//* Flatenning a 2D array ==> Conversion of 2D array to 1D array.
//* 2D matrix ==> (n * m) i.e, (row * col) ==> 
//* row = index / m  
//* col = index % m


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = (n*m)-1;

        while(low <= high){
            int mid = (low + high)/2;
            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid + 1;
            }
            else {
                high = mid -1;
            }
        }

        return false;
    }
};