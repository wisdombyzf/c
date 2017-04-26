#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



struct student							//学生结构体
{
	char name[10];
	char age[3];
	char num[14];
	char grade[3];
	struct student *next;
};

struct student *Link_1()
{
	student*head;
	head = (student*)malloc(sizeof(student));
	return head;
}

struct student* create()												//创建
{
	int i = 1;
	student*head, *r, *s;
	head = Link_1();
	r = (student*)malloc(sizeof(student));
	head->next = r;
	s = r;
	while(i=1)
	{
		s = (student*)malloc(sizeof(student));
		printf("请输入名称");
		scanf_s("%s", &r->name);									
		getchar();
		printf("请输入年龄");
		scanf_s("%s", &r->age);
		getchar();
		printf("请输入学号");
		scanf_s("%s", &r->num);
		getchar();
		printf("请输入分数");
		scanf_s("%s", &r->grade);
		getchar();
		r->next = s;
		printf("是否继续");
		scanf("%d", &i);
	}

	FILE *write;
	if ((write = fopen("zf.txt", "r+")) == NULL)			//文件是否存在
	{
		printf("不能打开数据文件。\n");
		exit(1);
	}
	while (head)
	{
		fwrite(head, sizeof(struct student), 1, write);
		head =( head->next);
	}
	fclose(write);
	
}

void display()												//浏览
{

}

void shanchu()											//删除
{

}

void help()							//帮助
{

}

void interface()										//主界面
{
	int choose;

	printf("学生管理系统\n");
	printf("*************\n");
	printf("*	1.创建	*\n");
	printf("*	2.浏览	*\n");
	printf("*	3.删除	*\n");
	printf("*	4帮助	*\n");
	printf("*************\n");
	printf("请输入你的选择");
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:
		create();
		break;
	case 2:
		display();
		break;
	case 3:
		shanchu();
		break;
	case 4:
		help();
		break;
	default:printf("输入错误\n");				//没用
		system("pause");
		interface();
		break;
	}

}

int main()
{
	while (1)
	{
		interface();
	}
}

