#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool isPerfectSquare(int n) {
    if (n < 0) {
        return false;
    }
    int root = sqrt(n);
    return root * root == n;
}

int main() {
    int n;
    cin >> n;

    stack<int> primes;
    queue<int> squares;
    int otherCount = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (isPrime(num)) {
            primes.push(num);
        } else if (isPerfectSquare(num)) {
            squares.push(num);
        } else {
            otherCount++;
        }
    }

    while (!primes.empty()) {
        cout << primes.top() << " ";
        primes.pop();
    }
    cout << endl;

    while (!squares.empty()) {
        cout << squares.front() << " ";
        squares.pop();
    }
    cout << endl;

    cout << otherCount << endl;

    return 0;
}
