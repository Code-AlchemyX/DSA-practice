//!     IN THIS PROBLEM WE CAN BE ASKED 3 TYPE OF QS --> 

//==========================================================================================================
//todo --> 1] Rows and Cols are given. Find the element at that address.

// Direct formula to find the element when number of rows(r) and cols(c) are given is ==> C(r-1 , c-1).

class Solution {
public:
    // Function to compute binomial coefficient (nCr)
    long long findPascalElement(int r, int c) {
        int n = r - 1;
        int k = c - 1;

        long long result = 1;

        for (int i = 0; i < k; i++) {
            result *= (n - i);
            result /= (i + 1);
        }

        return result;
    }
};


//==========================================================================================================
//todo --> 2] Print the nth row.

class Solution {
public:
    // Function to generate the Nth row of Pascal's Triangle
    vector<long long> getNthRow(int N) {
        // Result vector to store the row
        vector<long long> row;
        
        // First value of the row is always 1
        long long val = 1;
        row.push_back(val);
        
        // Compute remaining values using the relation:
        // C(n, k) = C(n, k-1) * (n-k) / k
        for (int k = 1; k < N; k++) {
            val = val * (N - k) / k;
            row.push_back(val);
        }
        
        return row;
    }
};


//==========================================================================================================
//todo -->  3] Print the Pascal's triangle.

// OPTIMAL APPROACH 1 ---->  using previous row (intuitive)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=0; i<numRows; i++){
            vector<int> row(i+1 , 1);

            for(int j=1; j<i; j++){
                row[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(row);
        }

        return ans;
    }
};


// OPTIMAL APPROACH 2 ---->  using formula C(n,k) (mathematical)

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        // C(n, k) = C(n, k-1) * (n-k) / k
        for(int i=0; i<numRows; i++){
            vector<int> row;
            int value = 1;
            row.push_back(value);
            
            for(int k=1; k<i+1; k++){
                value = value*(i-k+1) / k;
                row.push_back(value); 
            }
            ans.push_back(row);
        }
        
        return ans;
    }
};
//==========================================================================================================