class Solution {
public:
    bool maxSumPossible(vector<int> &nums, int k , int mid){
        int partition = 1;
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else {
                partition++;
                sum = nums[i];
            }
        }

        if(partition <= k) return true;

        return false;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = nums[0];
        int high = 0;
        for(int i=0; i<n; i++){
            low = max(low , nums[i]);
            high += nums[i];
        }

        while(low <= high){
            int mid = low + (high - low)/2;
            
            bool check = maxSumPossible(nums , k , mid);

            if(check){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};