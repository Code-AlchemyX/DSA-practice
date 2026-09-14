//! Brute Force

class Solution {
public:
    vector<string> powerSet(string s) {

        vector<string> result;
        int n = s.size();

        int total = 1 << n;   // 2^n subsets

        for(int mask = 0; mask < total; mask++) {

            string temp = "";

            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    temp.push_back(s[i]);
                }
            }

            result.push_back(temp);
        }

        return result;
    }
};

//! Optimal Approach

class Solution {
  public:
    void generate(string s , string temp , vector<string> &result , int i){
        if(i == s.size()){
            result.push_back(temp);
            return;
        }
        
        temp.push_back(s[i]);
        generate(s, temp, result, i + 1);
        temp.pop_back();
        
        generate(s , temp , result , i + 1);
    }
    
    vector<string> powerSet(string s) {
        vector<string> result;
        string temp;
        int i = 0;
        
        generate(s , temp , result , i);
        return result;
    }
};
