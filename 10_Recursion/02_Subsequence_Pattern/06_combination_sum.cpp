//! -----------------------------------------------------------------------------------------------

//* All three are exponential backtracking approaches in the worst case. The third adds O(N log N) sorting but enables stronger pruning with break, so it is generally more efficient in practice while having the same asymptotic exponential nature.


//! -----------------------------------------------------------------------------------------------
//! The one sheet expects us todo -->  PICK / NOT PICK method

class Solution {
public:
    void generate(vector<int> &candidates , vector<vector<int>> &result , int target , vector<int> &temp , int sum , int index , int n){
        if(sum > target){
            return;
        }

        if(sum ==  target){
            result.push_back(temp);
            return;
        }

        if(index == n){
            return;
        }

        temp.push_back(candidates[index]);
        sum += candidates[index];
        
        generate(candidates , result , target , temp , sum , index , n);

        temp.pop_back();
        sum -= candidates[index];
        generate(candidates, result , target , temp , sum , index + 1 , n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        int index = 0;
        int n = candidates.size();
        vector<vector<int>> result;
        vector<int> temp;

        generate(candidates , result , target , temp , sum , index , n);

        return result;
    }
};


//! -----------------------------------------------------------------------------------------------
//! Similar version --> for loop + CONTINUE

class Solution {
public:
    void generate(vector<int>& candidates, int target, int index,
                  int sum, vector<int>& temp, vector<vector<int>>& result) {

        if(sum == target) {
            result.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            if(sum + candidates[i] > target)
                continue;

            temp.push_back(candidates[i]);

            generate(candidates, target, i,
                     sum + candidates[i], temp, result);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        generate(candidates, target, 0, 0, temp, result);

        return result;
    }
};


//! -----------------------------------------------------------------------------------------------
//! sort + for loop + break


class Solution {
public:
    void generate(vector<int>& candidates, int target, int index,
                  int sum, vector<int>& temp, vector<vector<int>>& result) {

        if(sum == target) {
            result.push_back(temp);
            return;
        }

        for(int i = index; i < candidates.size(); i++) {

            if(sum + candidates[i] > target)
                break;

            temp.push_back(candidates[i]);

            generate(candidates, target, i,
                     sum + candidates[i], temp, result);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        generate(candidates, target, 0, 0, temp, result);

        return result;
    }
};
