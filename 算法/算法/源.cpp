#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>

using namespace std;
int main()
{
	int n = 0,y=0,k=0,z=0,yu=0;
	cin >> n;
	char a[1008], b[1008];
	char sum[1008];
	int len1, len2;
	for (int  i = 0; i <n; i++)
	{
		cin >> a;
		cin >> b;
		len1 =strlen(a);
		len2 =strlen(b);
		for (int x =min(len1,len2); x>=0;x--)
		{
			k =(a[len1]-'0') + (b[len2]-'0')+yu;
			z = k % 10;
			yu = k / 10;
			sum[y] =(z+'0') ;
			len1--;
			len2--;
			y++;
		}
		int len3 =strlen(sum);
		printf("Case %d:\n", i + 1);
		for (int p=(len3);p>=0;p--)
		{
			printf("%c", sum[p]);
		}
		printf("\n");


	}



}