#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<string.h>
#include<malloc.h>
using namespace std;

struct student
{
	char name[32];
	int birthday;
	int num;
	char zhuanye[32];
	struct student*next;
};

int main()
{
	int n = 31;
	student *head = NULL, *last = NULL, *first = NULL;
	while (n--)
	{
		first = (student*)malloc(sizeof(student));
		if (head == NULL)
		{
			head = last = first;
			continue;
		}
		cout << "姓名 生日 学号 作业" << endl;
		cin >> first->name >> first->birthday >> first->num >> first->zhuanye;
		last->next = first;
		first->next = NULL;
		last = first;
	}
	n = 3;
	first = head->next;
	n = 2;
	while (n--)
	{
		cout << first->name << endl << first->birthday << endl << first->num << endl << first->zhuanye << endl;
		if (first->next != NULL)
		{
			first = first->next;
		}
	}
	system("pause");


}