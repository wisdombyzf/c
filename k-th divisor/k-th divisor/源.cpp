#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int a, b,c;
	cin >> a >> b;
	int i;
	int x[1000000];
	for ( i = 1; i <=sqrt(a); i++)
	{
		if (a%i==0)
		{
			x[i-1] = i;
			x[(2 * i)-1] = a/i;
		}
	}
	sort(x, x + i);
	printf("%d", x[b - 1]);
	return 0;

}