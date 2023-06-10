#include <iostream>
using namespace std;

void yolochka(int a, int b, int c) {
    if (a > 0) {
        yolochka(a - 1, b, c);
        int num = (c - (b - a + 1)) / 2;
        for (int i = 0; i < num; i++) {
            cout << " ";
        }
        for (int i = 0; i < b - a + 1; i++) {
            cout << "*";
        }
        cout << endl;
        yolochka(a - 1, b, c);
    }
}

int main() {
    yolochka(1, 1, 15);
    yolochka(1, 3, 15);
    yolochka(1, 1, 15);
    yolochka(1, 3, 15);
    yolochka(1, 5, 15);
    yolochka(1, 1, 15);
    yolochka(1, 3, 15);
    yolochka(1, 5, 15);
    yolochka(1, 7, 15);
    return 0;
}
