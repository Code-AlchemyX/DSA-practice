class Solution {
public:
    void generate(string digits , string s , vector<string> &temp , int index , int n , unordered_map<char, string> &mp){
        if(index == n){
            temp.push_back(s);
            return;
        }

        string letters = mp[digits[index]];

        for(int i=0; i<letters.size(); i++){
            s.push_back(letters[i]);
            generate(digits , s , temp , index + 1 , n , mp);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        string s;
        vector<string> temp;
        int index = 0;

        if( digits.empty() ) return temp;

        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";


        generate(digits , s , temp , index , n , mp);

        return temp;
    }
};