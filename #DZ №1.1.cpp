#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int fib(int n, int *a)
{
	if (a[n] == -1)
	{
		if (n <= 1) a[n] = 0;
		if (n == 2) a[n] = 1;
		else a[n] = fib(n - 1, a) + fib(n - 2,a) + fib(n - 3,a);
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
	cout << fib(7, a);
}
