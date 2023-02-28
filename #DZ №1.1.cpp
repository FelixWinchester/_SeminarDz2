#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int fiba(int n, int *a)
{
	if (a[n] == -1)
	{
		if (n <= 1) a[n] = 0;
		if (n == 2) a[n] = 1;
		else a[n] = fiba(n - 1, a) + fiba(n - 2,a) + fiba(n - 3,a);
	}
	return a[n];
}

int main()
{
	int n; cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i] = -1;
	}
	a[0] = 0;
	a[1] = 0;
	cout << fiba(7, a);
}
