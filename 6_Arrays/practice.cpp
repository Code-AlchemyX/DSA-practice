#include<bits/stdc++.h>
using namespace std;

class Pattern{
public : 
    void pattern(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i-1; j++){
                cout << " ";
            }

            for(int j=0; j<i+1; j++){
                cout << char('A'+j);
            }

            for(int j=i-1; j>=0; j--){
                cout << char('A'+j);
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