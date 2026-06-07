//! ============================================== Brute Force ==============================================

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        if(sum == (long long)target){
                            vector<int> quadruplet = {nums[i], nums[j], nums[k], nums[l]};
                            sort(quadruplet.begin(), quadruplet.end());
                            ans.insert(quadruplet);
                        }
                    }
                }
            }
        }

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};


//! ============================================ Better Approach ============================================

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                set<long long> hashset;
                for(int k=j+1; k<n; k++){
                    long long sum = (long long)nums[i] + nums[j] + nums[k];
                    long long fourth = (long long)target - sum; 
                    
                    if( hashset.find(fourth) != hashset.end() ){
                        vector<int> quadruplet = { nums[i] , nums[j] , nums[k] , int(fourth) };
                        sort( quadruplet.begin() , quadruplet.end() );
                        ans.insert(quadruplet);
                    }
                    
                    hashset.insert(nums[k]);
                }
            }
        }

        return vector<vector<int>> (ans.begin() , ans.end());
    }
};


//! ============================================ Optimal Approach ============================================


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }

            for(int j=i+1; j<n; j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }

                int k = j+1;
                int l = n-1;

                while(k < l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }
                    else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                        while(k < l && nums[k] == nums[k-1]){
                            k++;
                        }
                        while(k < l && nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }

        return ans;
    }
};