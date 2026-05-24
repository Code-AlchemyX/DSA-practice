//       *
//       **
//       ***
//       ****
//       *****
//       ****
//       ***
//       **
//       *

#include<bits/stdc++.h>
using namespace std;


class Pattern
{
public:
    void pattern10(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<i+1; j++){
                cout << "*";
            }
            cout << endl;
        }
        for(int i=n-1; i>0; i--){
            for(int j=0; j<i; j++){
                cout << "*";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter n : ";
    cin >> n;

    Pattern p;
    p.pattern10(n);

    return 0;
}