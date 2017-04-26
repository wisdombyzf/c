#include <iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

bool sign = false;
int num[9][9];
bool Check(int n, int q);
int DFS(int n);

int main()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> num[i][j];
		}
	}
	DFS(0);
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
	system("pause");
}


bool Check(int n, int q)
{
	
	for (int i = 0; i < 9; i++)
	{
		int j = n / 9;
		if (num[j][i] == q)
		{
			return false;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		int j = n % 9;
		if (num[i][j] == q) 
		{
			return false;
		}
	}
	int x = ((n / 9) / 3) * 3;
	int y =( (n % 9) / 3) * 3;
	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (num[i][j] == q)
			{
				return false;
			}
		}
	}
	return true;
}

int DFS(int n)
{
	if (n > 80)
	{
		sign = true;
	}
	if (num[n / 9][n % 9] != 0)
	{
		DFS(n + 1);
	}
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (Check(n, i) == true)
			{
				num[n / 9][n % 9] = i;
				DFS(n + 1);
				if (sign == true)
				{
					return 0;
				}
				num[n / 9][n % 9] = 0;
			}
		}
	}
}