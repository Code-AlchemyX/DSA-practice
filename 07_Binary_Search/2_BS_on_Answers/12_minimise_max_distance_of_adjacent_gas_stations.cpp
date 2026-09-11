class Solution {
  public:
    bool canPlaceStation(vector<int> &stations, int k, double mid){
        int stationReq = 0;

        for(int i = 1; i < stations.size(); i++){
            double gap = stations[i] - stations[i-1];
            stationReq += ceil(gap / mid) - 1;
        }
            
        if(stationReq <= k) return true;

        return false;
    }
    
    double minMaxDist(vector<int> &stations, int k) {
        int n = stations.size();
        
        double low = 0;
        double high = stations[n-1] - stations[0];
        
        for(int i=0; i<100; i++){
            double mid = low + (high - low)/2.0;
            
            bool check = canPlaceStation(stations, k , mid);
            
            if(check){
                high = mid;
            }
            else {
                low = mid;
            }
        }
        
        return low;
    }
};