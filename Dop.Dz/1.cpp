#include <iostream>
using namespace std;
void f(int n) {
    if (n == 1) {
        cout << "1\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << i;
        }
        cout << "\n";
        f(n - 1);
        for (int i =1; i <= n; i++) {
            cout << i;
        }
        cout << "\n";
    }
}

int main() {
    f(5);
    return 0;
}
