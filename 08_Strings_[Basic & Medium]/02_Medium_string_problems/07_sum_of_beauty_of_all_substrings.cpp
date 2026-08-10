class Solution {
public:
    int beautySum(string s) {
        unordered_map<char,int> freq;
        int n = s.size();
        int totalBeauty = 0;

        for(int i=0; i<n; i++){
            freq.clear();
            for(int j=i; j<n; j++){
                freq[s[j]]++;

                int max_freq = 0;
                int min_freq = INT_MAX;
                
                for(auto it : freq){
                        max_freq = max(max_freq , it.second);
                        min_freq = min(min_freq , it.second);
                }
                totalBeauty += (max_freq - min_freq);
            }
        }
        return totalBeauty;
    }
};