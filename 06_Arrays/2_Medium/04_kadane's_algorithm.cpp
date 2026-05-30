//!========================================= Brute force method =========================================

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = INT_MIN;

        for(int i=0; i<n; i++){
            int sum = 0;

            for(int j=i; j<n; j++){
                sum = sum + nums[j];
                max_sum = max(max_sum , sum);  
            }
        }
        return max_sum;
    }
};


//!================================= Optimal method --> KADANE'S METHOD =================================

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int n = nums.size();
        int sum = 0;
        int start = 0, ansStart = 0, ansEnd = 0;

        for(int i=0; i<n; i++){

            if(sum == 0){
                start = i;
            }
            
            sum+=nums[i];

            if(sum > max_sum){
                max_sum = sum;
                ansStart = start; 
                ansEnd = i;          
            }

            if(sum < 0){
                sum = 0;
            }

            //* Print subarray --->
            // for(int i=ansStart; i<=ansEnd; i++){
            //     cout << nums[i] << " ";
            // }

        }

        return max_sum;
    }
};

int main(){
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> nums[i];

    Solution s;
    cout << "Max subarray sum: " << s.maxSubArray(nums) << endl;

    return 0;
}