#include <iostream>
#include <cmath>
using namespace std;

int gee(int n, int *a)
{
	if (n == 0) return 1;
	return a[n-1] * gee(n-1, a);
}

int main()
{
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << gee(n, a);
}
