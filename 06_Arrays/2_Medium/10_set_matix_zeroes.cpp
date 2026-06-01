//! ====================================== Brute Force ======================================

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


//! ====================================== Optimal Approach ======================================
