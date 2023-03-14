
Энтони
Энтони 10:37

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
int n;
cin » n;
int m = n;
int* a = new int[n];
int* b = new int[m];
for (int i = 0; i < n; i++) {
cin » a[i];
}
int minim = 1000000;
int ind = 0;
for (int i = 0; i < m; i++) {
int h = 0;
for (int j = 0; j < n; j++) {
if (a[j] >= a[0]) {
h = a[j];
ind = j;
}
}
b[i] = h;
for (int j = ind; j < n-1; j++) {
a[j] = a[j + 1];
}
n--;
}
for (int j = 0; j < m; j++) {
cout « b[j] « " ";
}
}
