#include<stdio.h>
#include<stdlib.h>
struct student							//ѧ���ṹ��
{
	//char name[10];
	int age;
	int num;
	int grade;
	struct student *next;
};
int main()
{
	/*char a[8] = { "2343253" };
	printf("%s",a);
	getchar();*/
	int i = 0;
	char a[6] , *q, *p;
	char b[6];
	p = b;
	q = a;
	//struct student*p;
	FILE*write;
	FILE*read;
	if ((write = fopen("zf.txt", "r+")) == NULL)			//�ļ��Ƿ����
	{
		printf("���ܴ������ļ���\n");
		exit(1);
	}
	while (i<3)
	{
		printf("����a");
		scanf("%s", &a);
		fwrite(q, 6, 1, write);
		i++;
	}
	/*if ((read = fopen("zf.txt", "r+")) == NULL)			//�ļ��Ƿ����
	{
		printf("���ܴ������ļ���\n");
		exit(1);
	}

	while (!feof(read))
	{
		fgets(p,5,read);
		printf("%s", b);
		
	}
	getchar();
	fclose(write);
	//fclose(read);*/

}