//!================================================ Brute Force ================================================

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            int product = 1;

            for (int j = i; j < nums.size(); j++) {
                product *= nums[j];
                max_product = max(max_product , product);
            }
        }

        return max_product;
    }
};

//!============================================= Optimal Approach 1 =============================================
//* Always give this is as the optimal solution in interview. Cuz the second one isn't intuitive and not expected.

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int pre = 1, suff = 1;
        int ans = INT_MIN;
        int n = arr.size();
        
        for (int i = 0; i < n; i++) {
            if (pre == 0) pre = 1;
            if (suff == 0) suff = 1;
            
            pre = pre * arr[i];    
            suff = suff * arr[n - i - 1]; 
            
            ans = max(ans, max(pre, suff));
        }
        return ans;
    }
};

//!============================================= Optimal Approach 2 =============================================

//* Using Kadane's Algo. ---> Not used.


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int maxProd = nums[0];
        int minProd = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            if (curr < 0) swap(maxProd, minProd);

            maxProd = max(curr, maxProd * curr);
            minProd = min(curr, minProd * curr);

            res = max(res, maxProd);
        }

        return res;
    }
};

