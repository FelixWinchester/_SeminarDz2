#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int frog(int n, int k) {
    if (n == k) {
        return 1;
    }
    else if (n > k) {
        return 0;
    }
    else
        return frog(n + 3, k) + frog(n + 5, k);
    
}

int main() {
    int x;
    cin >> x;
    cout << frog(0, x);
}
