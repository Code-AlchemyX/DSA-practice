#include<bits/stdc++.h>
using namespace std;

class Pattern{
public : 
    void pattern(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==0 || i==n-1 || j==0 || j==n-1){
                    cout << "*";
                }else{
                    cout << " ";
                }
            }
            cout << endl;
        }
    }   
};

int main(){
    int n =5;

    Pattern p;
    p.pattern(n);

    return 0;
}