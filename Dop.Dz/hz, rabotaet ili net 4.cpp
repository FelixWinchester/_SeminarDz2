#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;
bool is_prime(int n) {
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

bool is_square(int n) {
    if (n < 0) {
        return false;
    }
    int root = sqrt(n);
    return root * root == n;
}

int main() {
    int n;
    cout << "Vvedite kol-vo chisel:" << " ";
    cin >> n;

    stack<int> primes;
    queue<int> squares;
    int other_count = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        cout << "Vvedite chislo: " << " ";
        cin >> num;

        if (is_prime(num)) {
            primes.push(num);
        } else if (is_square(num)) {
            squares.push(num);
        } else {
            ++other_count;
        }
        break;
    }
        
    cout << "Prostie chisla v napravlenii ot poslednego k pervomy" << endl;
    while (!primes.empty()) {
        cout << primes.top() << ' ';
        primes.pop();
    }
    cout << endl;

    cout << "Polnie kvadrati v tom poryadke, v kakom chisla vvodilis'" << endl;;
    while (!squares.empty()) {
        cout << squares.front() << ' ';
        squares.pop();
    }
    cout << endl;

    cout << "Kol-vo chisel, ne yavlyaushihsa no prostimim ni polnimi kvadratami" << endl << other_count << endl;

    return 0;
}
