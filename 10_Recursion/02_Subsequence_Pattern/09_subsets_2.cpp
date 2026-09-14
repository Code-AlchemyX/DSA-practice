class Solution {
public:
    void generate(vector<int> &nums, vector<vector<int>> &result, vector<int> &temp, int index) {

        result.push_back(temp);

        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);

            generate(nums, result, temp, i + 1);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;

        sort(nums.begin(), nums.end());

        generate(nums, result, temp, 0);

        return result;
    }
};