//       A
//      ABA
//     ABCBA
//    ABCDCBA
//   ABCDEDCBA

#include<bits/stdc++.h>
using namespace std;

class Pattern
{
public:
    void pattern17(int n){
        for(int i=0; i<n; i++){
            // spaces
            for(int j=0; j<n-i-1; j++){
                cout << " ";
            }

            // left: A to ith letter
            for(int j=0; j<i+1; j++){
                cout << (char)('A'+j);
            }

            // right: back to A
            for(int j=i-1; j>=0; j--){
                cout << (char)('A'+j);
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
    p.pattern17(n);

    return 0;
}