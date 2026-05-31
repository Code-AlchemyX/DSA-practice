//!========================================= Brute Force =========================================

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    int longest = 0;

    for(int i=0; i<n; i++){
        int current = nums[i];
        int count = 1;

        while(find(nums.begin(), nums.end(), current+1) != nums.end()){
            current++;
            count++;
        }

        longest = max(longest, count);
    }

    return longest;
}

//!======================================== Better Approach ========================================

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if(n == 0){
            return 0;
        }
        
        int longest = 1;
        int count = 0;
        int last_smaller = INT_MIN;

        sort(nums.begin() , nums.end());

        for(int i=0; i<n; i++){
            if(nums[i]-1 == last_smaller){
                count += 1;
                last_smaller = nums[i];
            } else if(nums[i] != last_smaller){
                count = 1;
                last_smaller = nums[i];
            }

            longest = max(count , longest);
        }

        return longest;
    }
};

//!========================================= Optimal Approach =========================================

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0; 
    
        int longest = 1; 
        unordered_set<int> st;
    
        for (int i = 0; i < n; i++) {
            st.insert(nums[i]);
        }
    
        for (auto it : st) {
            if (st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it; 

                while (st.find(x + 1) != st.end()) {
                    x = x + 1; 
                    cnt = cnt + 1; 
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};