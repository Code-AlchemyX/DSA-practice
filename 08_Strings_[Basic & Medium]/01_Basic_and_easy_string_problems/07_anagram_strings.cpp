//! Sub-Optimal 1 --> TC = O(n) SC = O(k) k = number of unique chars.

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mapS;
        unordered_map<char,int> mapT;

        if(s.size() != t.size()) return false;
        
        for(int i=0; i<s.size(); i++){
            mapS[s[i]]++;
            mapT[t[i]]++;
        }

        if(mapS != mapT) return false;

        return true;
    }
};

//! Optimal 2 --> TC = O(n) and SC = O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int mapS[26] = {0};

        for (int i = 0; i < s.size(); i++) {
            mapS[s[i] - 'a']++;
            mapS[t[i] - 'a']--;
        }

        for (int count : mapS) {
            if (count != 0) return false;
        }

        return true;
    }
};