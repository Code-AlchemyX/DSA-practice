class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> spiral;

        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;

        while( top <= bottom && left <= right ){

            //left to right
            for(int i=left; i<=right; i++){
                spiral.push_back( matrix[top][i] );
            }
            top++;

            //top to bottom
            for(int i=top; i<=bottom; i++){
                spiral.push_back( matrix[i][right] );
            }
            right--;

            //right to left
            if( top <= bottom ){
                for(int i=right; i>=left; i--){
                    spiral.push_back( matrix[bottom][i] );
                } 
                bottom--;
            }

            //bottom to top
            if( left <= right ){
                for(int i=bottom; i>=top; i--){
                    spiral.push_back( matrix[i][left] );
                }
                left++;
            }
        }


        return spiral;
    }
};