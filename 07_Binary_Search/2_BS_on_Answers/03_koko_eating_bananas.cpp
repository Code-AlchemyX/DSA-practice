//! ============================================== Brute Force ==============================================

class Solution {
public:
    int findMax(const vector<int>& piles) {
        int maxElement = piles[0];
        int n = piles.size();
        
        for (int i = 1; i < n; i++) {
            if (piles[i] > maxElement) {
                maxElement = piles[i];
            }
        }
        return maxElement;
    }

    long long calculateTotalHours(const vector<int>& piles, int i) {
        long long totalHours = 0;
        int n = piles.size();
        
        for (int index = 0; index < n; index++) {
            totalHours += ceil((double)piles[index] / (double)i);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = findMax(piles);
        
        for (int i = 1; i <= maxElement; i++) {
            long long reqTime = calculateTotalHours(piles, i);
            
            if (reqTime <= h) {
                return i;
            }
        }
        return maxElement;
    }
};

//! ============================================= Optimal Approach =============================================

class Solution {
public:
    int findMax(const vector<int>& piles) {
        int maxElement = piles[0];
        int n = piles.size();
        
        for (int i = 1; i < n; i++) {
            if (piles[i] > maxElement) {
                maxElement = piles[i];
            }
        }
        return maxElement;
    }

    long long calculateTotalHours(const vector<int>& piles, int i) {
        long long totalHours = 0;
        int n = piles.size();
        
        for (int index = 0; index < n; index++) {
            totalHours += ceil((double)piles[index] / (double)i);
        }
        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalHours = calculateTotalHours(piles, mid);
            
            if (totalHours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};