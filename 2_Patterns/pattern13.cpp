//  1 
//  2 3 
//  4 5 6 
//  7 8 9 10 
//  11 12 13 14 15

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    int count =1;
    void pattern13(int n){
        for(int i=0; i<n; i++){
            for(int j=0; j<i+1; j++){
                cout << count << " ";
                count++;
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
    p.pattern13(n);

    return 0;
}