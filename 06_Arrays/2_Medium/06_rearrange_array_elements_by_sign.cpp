//========================================== SOLUTION - 1 ============================================

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int posIndex = 0;
        int negIndex = 1;

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                result[posIndex] = nums[i];
                posIndex += 2;
            } else { 
                result[negIndex] = nums[i];
                negIndex += 2;
            }
        }

        return result;
    }
};


//========================================== SOLUTION - 2 ============================================


class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result , positive , negative ;

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }

        for(int i=0; i<positive.size(); i++){
            result.push_back(positive[i]);
            result.push_back(negative[i]);
        }


        return result;
    }
};