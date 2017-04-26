#include<stdio.h>
#include<stdlib.h>
struct student							//学生结构体
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
	if ((write = fopen("zf.txt", "r+")) == NULL)			//文件是否存在
	{
		printf("不能打开数据文件。\n");
		exit(1);
	}
	while (i<3)
	{
		printf("输入a");
		scanf("%s", &a);
		fwrite(q, 6, 1, write);
		i++;
	}
	/*if ((read = fopen("zf.txt", "r+")) == NULL)			//文件是否存在
	{
		printf("不能打开数据文件。\n");
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