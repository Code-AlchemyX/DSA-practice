class Solution{
    public:    	
    int count(int n , vector<int>& nums, int k , int sum , vector<int>& temp , int index){
        if(index == n){
            if(sum == k){
                return 1;
            }
            return 0;
        }

        sum += nums[index];
        int l = count(n , nums , k , sum , temp , index+1);

        sum -= nums[index];
        int r = count(n , nums , k , sum , temp , index+1);

        return l + r;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	int n = nums.size();
        int sum = 0;
        int index = 0;
        vector<int> temp;

        int total_count = count(n , nums, k , sum , temp , index);

        return total_count;
    }
};

