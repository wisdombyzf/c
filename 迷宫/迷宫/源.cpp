#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

char mp[123][123];
bool vis[123][123];
int f[4][2] = { 0,1,0,-1,1,0,-1,0 };
int n, m, k;
void init()
{
	memset(vis, false, sizeof(vis));
}
void DFS(int x, int y)
{
	if (x<0 || x >= n || y<0 || y >= m)
		return;
	if (mp[x][y] != '.') 
		return;
	if (vis[x][y])
		return;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		DFS(x + f[i][0], y + f[i][1]);
	}
	if (k) mp[x][y] = 'X', k--;
}
int main()
{
	
	int i;
	int x;
	while (scanf_s("%d%d%d", &n, &m, &k))
	{
		init();
		for (x= 0; x< n; x++)
		{
			for (int y=0;y<m;y++)
			{
				scanf_s("%s", &mp[x][y]);
			}	
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <m; j++)
			{
				DFS(i, j);
			}	
		}
		for (x = 0; x< n; x++)
		{
			for (int y = 0; y<m; y++)
			{
				printf("%s", &mp[x][y]);
			}
			printf("\n");
		}
	}
	return 0;
}
	



