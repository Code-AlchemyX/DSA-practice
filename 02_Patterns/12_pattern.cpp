// 1        1
// 12      21
// 123    321
// 1234  4321
// 1234554321

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern12(int n){
        for(int i=0; i<n; i++){
            for(int j=1; j<=i+1; j++){
                cout << j;
            }
            for(int j=0; j<2*(n-1-i); j++){
                cout << " ";
            }
            for(int j=i+1; j>=1; j--){
                cout << j;
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
    p.pattern12(n);

    return 0;
}