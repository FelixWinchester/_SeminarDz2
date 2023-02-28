#include <iostream>
#include <cmath>
using namespace std;

int ass(int min, int max)
{
	if (min == 0) return max;
	return ass(max % min, min);
}

int main()
{
	int a, b, min, max;
	cin >> a >> b;
	if (a < b)
	{
		min = a; 
		max = b;
	}
	else
	{
		max = a;
		min = b;
	}
	cout << ass(min, max);
}
