//!============================================== Brute Force ==============================================

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for(int i=0; i<n; i++){
            if(result.size() == 0 || result[0] != nums[i]){
                if(result.size() == 1 || result[1] != nums[i]){
                    int count = 0;
                    for(int j=0; j<n; j++){
                        if(nums[j] == nums[i])
                            count++;
                    }
                    if(count > n/3)
                        result.push_back(nums[i]);
                }
            }
            if(result.size() == 2) break;
        }

        return result;
    }
};

//!============================================ Better Approach ============================================

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int target = int(n/3);

        unordered_map<int,int> mp;
        vector<int> ans;

        for(auto it : nums){
            mp[it]++;
        }

        for(auto it : mp){
            if(it.second > target){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};

//!============================================ Optimal Approach ============================================
//* Moore's Voting Algorithm.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int counter1 = 0;
        int counter2 = 0;
        int element1 = INT_MIN;
        int element2 = INT_MIN;
    
        for(int i=0; i<n; i++){
            if( counter1 == 0  &&  element2 != nums[i] ){
                counter1 = 1;
                element1 = nums[i];
            }
            else if( counter2 == 0  &&  element1 != nums[i] ){
                counter2 = 1;
                element2 = nums[i];
            }
            else if( nums[i] == element1 ){
                counter1++;
            }
            else if( nums[i] == element2 ){
                counter2++;
            }
            else{
                counter1--;
                counter2--;
            }
        }

        vector<int> ans;
        counter1 = 0;
        counter2 = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == element1){
                counter1++;
            }
            if(nums[i] == element2){
                counter2++;
            }
        }

        int min = int(n/3) + 1;
        if(counter1 >= min){
            ans.push_back(element1);
        }
        if(counter2 >= min){
            ans.push_back(element2);
        }

        sort(ans.begin() , ans.end());

        return ans;
    }
};