//! =========================================== Brute Force ===========================================

class Solution {
public:
    int func(vector<int>& weights , int capacity){
        int days = 1;
        int load = 0;

        for(int i=0; i<weights.size(); i++){
            if( load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = weights[0];

        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            
            if(weights[i] > maxi){
                maxi = weights[i];
            }
        }

        for(int capacity= maxi; capacity<=sum; capacity++){
            int daysReq = func(weights , capacity);

            if(daysReq <= days){
                return capacity;
            }
        }

        return sum;
    }
};


//! =========================================== Optimal Approach ===========================================

class Solution {
public:
    int func(vector<int>& weights , int capacity){
        int days = 1;
        int load = 0;

        for(int i=0; i<weights.size(); i++){
            if( load + weights[i] > capacity){
                days = days + 1;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maxi = weights[0];

        for(int i=0; i<weights.size(); i++){
            sum += weights[i];
            
            if(weights[i] > maxi){
                maxi = weights[i];
            }
        }

        int low = maxi;
        int high = sum;
        int ans = sum;

        while(low <= high){
            int mid = (low + high)/2;

            int daysReq = func(weights , mid);

            if(daysReq <= days){
                ans = mid;
                high = mid -1;
            }
            else { 
                low = mid +1;
            }
        }

//* Instead of taking extra variable ans we can directly return low. As low will stop when it finds min capacity where it's possible whereas high will stop at place where it's not possible.

        return ans;
    }
};