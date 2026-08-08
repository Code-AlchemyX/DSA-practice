//! Optimal 1 - but bit messy

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int i = 0;
        int n = s.size();

        while (i < n) {
            // Check 2-character subtraction pairs first
            if (i + 1 < n && s[i] == 'I' && s[i+1] == 'V') { sum += 4; i += 2; }
            else if (i + 1 < n && s[i] == 'I' && s[i+1] == 'X') { sum += 9; i += 2; }
            else if (i + 1 < n && s[i] == 'X' && s[i+1] == 'L') { sum += 40; i += 2; }
            else if (i + 1 < n && s[i] == 'X' && s[i+1] == 'C') { sum += 90; i += 2; }
            else if (i + 1 < n && s[i] == 'C' && s[i+1] == 'D') { sum += 400; i += 2; }
            else if (i + 1 < n && s[i] == 'C' && s[i+1] == 'M') { sum += 900; i += 2; }
            
            // Single character values
            else if (s[i] == 'I') { sum += 1; i += 1; }
            else if (s[i] == 'V') { sum += 5; i += 1; }
            else if (s[i] == 'X') { sum += 10; i += 1; }
            else if (s[i] == 'L') { sum += 50; i += 1; }
            else if (s[i] == 'C') { sum += 100; i += 1; }
            else if (s[i] == 'D') { sum += 500; i += 1; }
            else if (s[i] == 'M') { sum += 1000; i += 1; }
        }

        return sum;
    }
};

//=================================================================================================


//! Optimal 2 -- but clean code

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman = { 
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000} 
        };

        int sum = 0;
        int n = s.size();
        
        for(int i=0; i<n; i++){
            if(i+1 < n && roman[s[i]] < roman[s[i+1]]){
                sum -= roman[s[i]];
            }
            else {
                sum += roman[s[i]];
            }
        }
        return sum;
    }
};

//=================================================================================================
//! Optimal 3 -- using switch 

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int current = getValue(s[i]);

            // Check subtraction rule against the next character
            if (i + 1 < n && current < getValue(s[i + 1])) {
                sum -= current;
            } else {
                sum += current;
            }
        }

        return sum;
    }

private:
    int getValue(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default:  return 0;
        }
    }
};