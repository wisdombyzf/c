#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	while (1)
	{
		int k;
		int sum = 0;
		int n;
		cin >> n;
		if (n==0)
		{
			break;
		}
		int a[1008];
		for (int  i = 0; i <n; i++)
		{
			cin >> a[i];
		}
		for (k=0;k<n;k++)
		{	
			for (int i =0;i <(n-1); i++)
			{
				if (a[i] > a[i + 1])
				{
					int p;
					p = a[i];
					a[i] = a[i + 1];
					a[i + 1] = p;
					sum++;
				}
			}
		}
		cout << sum << endl;
	}
}