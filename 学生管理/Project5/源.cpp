#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



struct student							//ѧ���ṹ��
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

struct student* create()												//����
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
		printf("����������");
		scanf_s("%s", &r->name);									
		getchar();
		printf("����������");
		scanf_s("%s", &r->age);
		getchar();
		printf("������ѧ��");
		scanf_s("%s", &r->num);
		getchar();
		printf("���������");
		scanf_s("%s", &r->grade);
		getchar();
		r->next = s;
		printf("�Ƿ����");
		scanf("%d", &i);
	}

	FILE *write;
	if ((write = fopen("zf.txt", "r+")) == NULL)			//�ļ��Ƿ����
	{
		printf("���ܴ������ļ���\n");
		exit(1);
	}
	while (head)
	{
		fwrite(head, sizeof(struct student), 1, write);
		head =( head->next);
	}
	fclose(write);
	
}

void display()												//���
{

}

void shanchu()											//ɾ��
{

}

void help()							//����
{

}

void interface()										//������
{
	int choose;

	printf("ѧ������ϵͳ\n");
	printf("*************\n");
	printf("*	1.����	*\n");
	printf("*	2.���	*\n");
	printf("*	3.ɾ��	*\n");
	printf("*	4����	*\n");
	printf("*************\n");
	printf("���������ѡ��");
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
	default:printf("�������\n");				//û��
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

