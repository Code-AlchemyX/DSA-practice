//!=================================================== Brute Force ===================================================

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long n = nums.size();
        long long count = 0;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if( (long long)nums[i] > 2*(long long)nums[j] ){
                    count++;
                }
            }
        }

        return count;
    }
};

//!=============================================== Optimal Approach ===============================================

class Solution {
private:
    void merge(vector<int>& arr, int low, int mid, int high){
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }

        for(int i=low; i<=high; i++)
            arr[i] = temp[i - low];
    }

    int countPairs(vector<int>& arr, int low, int mid, int high){
        int right = mid + 1;
        int cnt = 0;

        for(int i=low; i<=mid; i++){
            while(right <= high && arr[i] > 2LL * arr[right]){
                right++;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high){
        int cnt = 0;
        if(low >= high){
            return cnt; 
        }

        int mid = low + (high - low) / 2;   //!----> !Prevents integer overflow when low and high are large numbers, which would cause a negative mid index and crash.

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);

        return cnt;
    }

public:
    int reversePairs(vector<int>& nums){
        if(nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }
};