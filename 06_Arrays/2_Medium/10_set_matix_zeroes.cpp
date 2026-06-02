//! ====================================== Brute Force ========================================
//* Time Complexity = O(m x n x (m+n)) 
//* Space Complexity = O(m+n)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> zero_rows;
        vector<int> zero_cols;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( matrix[i][j] == 0 ){
                    zero_rows.push_back(i);
                    zero_cols.push_back(j);
                }
            }
        }

        for(auto row : zero_rows){
            for(int j=0; j<n; j++){
                matrix[row][j] = 0;
            }
        }

        for(auto col : zero_cols){
            for(int i=0; i<m; i++){
                matrix[i][col] = 0;
            }
        }
    }
};

//! ===================================== Better Approach --> O(n^2) =====================================
//* Time Complexity = O(m x n) 
//* Space Complexity = O(m+n)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> row(m,0);
        vector<int> col(n,0);
    
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( matrix[i][j] == 0 ){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( row[i] == 1 || col[j] == 1 ){
                    matrix[i][j] = 0;
                }
            }
        }
        
    }
};


//! ====================================== Optimal Approach ======================================
//* Time Complexity = O(m x n) 
//* Space Complexity = O(1)


