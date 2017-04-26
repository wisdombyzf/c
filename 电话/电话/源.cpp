#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	int time,i;
	cin >> time;
	int a[120000];
	char b[50];
	int length;
	int x;
	int t;
	int sum;
	for ( i = 0; i < time; i++)
	{
		sum = 0;
		cin >> b;
		length = strlen(b);
		for (x= 0; x<length;x++)
		{
			switch (b[x])
			{
			case '0':t = 0;
				break;
			case '1':t = 1;
				break;
			case '2':t = 2;
				break;
			case '3':t = 3;
				break;
			case '4':t = 4;
				break;
			case '5':t = 5;
				break;
			case '6':t = 6;
				break;
			case '7':t = 7;
				break;
			case '8':t = 8;
				break;
			case '9':t = 9;
				break;
			case 'A':t = 2;
				break;
			case 'B':t = 2;
				break;
			case 'C':t = 2;
				break;
			case 'D':t = 3;
				break;
			case 'E':t = 3;
				break;
			case 'F':t = 3;
				break;
			case 'G':t = 4;
				break;
			case 'H':t = 4;
				break;
			case 'I':t = 4;
				break;
			case 'J':t = 5;
				break;
			case 'K':t = 5;
				break;
			case 'L':t = 5;
				break;
			case 'M':t = 6;
				break;
			case 'N':t = 6;
				break;
			case 'O':t = 6;
				break;
			case 'P':t = 7;
				break;
			case 'R':t = 7;
				break;
			case 'S':t = 7;
				break;
			case 'T':t = 8;
				break;
			case 'U':t = 8;
				break;
			case 'V':t = 8;
				break;
			case 'W':t = 9;
				break;
			case 'X':t = 9;
				break;
			case 'Y':t = 9;
				break;
			default:
				break;
			}
			sum = sum * 10 +t;
		}
		a[i] = sum;
	}
	sort(a, a + time);
	int repeat[100000],m[100000];
	int z = 0,k;
	for ( i = 0; i <time; i++)
	{
		if (a[i+1]==a[i])
		{
			repeat[z] = a[i];
			i++;
			for (k=2;a[i+1]==a[i];i++,k++)
			{
			}
			m[z] = k;
			z++;
		}	
		
	}
	if (z==0)
	{
		printf("No duplicates.");
	}
	int p = 1000000;
	int y ;
	int uuu;
	for(i=0;i<z;i++)
	{
		uuu = a[i];
		for (y = 1; y<= 3; y++)
		{
			printf("%d", uuu/ p);
			uuu = a[i] % p;
			p = p / 10;
		}
		printf("-");
		for (y= 1; y<= 4; y++) 
		{
			printf("%d", uuu/ p);
			uuu = a[i] % p;
			p = p / 10;
		}
		printf(" %d\n", m[i]);

	}
	return 0;
}