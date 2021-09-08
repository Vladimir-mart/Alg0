#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
int main() {
    int iterator;
    cin >> iterator;
    while(iterator != 0) {
        int N;
        cin >> N;
        for(int divider = 2; divider <= sqrt(N); divider++) {
            while(N % divider == 0) {
                N /= divider;
                cout << divider << " ";
            }
        }
        if(N != 1) {
            cout << N <<" ";
        }
        cout << '\n';
        iterator--;
    }
    return 0;
}