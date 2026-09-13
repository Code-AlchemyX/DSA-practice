class Solution {
public:
    bool check(int n, vector<int>& arr, int k, int sum, vector<int>& nums, int index){
        if(index == n){
            if(sum == k){
                return true;
            }
            return false;
        }

        nums.push_back(arr[index]);
        sum += nums[index];
        if(check(n , arr , k , sum , nums , index+1) == true) return true;

        sum -= nums[index];
        nums.pop_back();

        if(check(n , arr , k , sum , nums , index+1) == true) return true;

        return false;
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        int index = 0;
        int sum = 0;

        return check(n, nums, k, sum, arr, index);
    }
};