//!============================================= Brute Force =============================================

class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size();
        int m = arr[0].size();
        
        int max_ones = 0;
        int index = -1;
        
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<m; j++){
                if(arr[i][j] == 1){
                    count++;
                }
            }
            
            if(count > max_ones){
                max_ones = count;
                index = i;
            }
        }
        
        return index;
    }
};

//!============================================ Optimal Approach ============================================


//* NOTE ---> Can be solved using lowerBound / upperBound / firstOccurence.

class Solution {
private:
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                // look for more small index on left
                high = mid - 1;
            } else {
                low = mid + 1; // look for right
            }
        }
        return ans;
    }

public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        int cnt_max = 0;
        int index = -1;

        for (int i = 0; i < n; i++) {
            int cnt_ones = m - lowerBound(matrix[i], m, 1);
            if (cnt_ones > cnt_max) {
                cnt_max = cnt_ones;
                index = i;
            }
        }
        return index;
    }
};