#include <iostream>  
#include <cstdlib>  
#include <string>  
#include <fstream>  

using namespace std;

class Student//学生类  
{
public:
	Student();//构造函数  
	void SetInfo(string N, int A);//设置学生的信息(设置姓名、年龄)  
	void SetNo(int N);//设置学生的编号  
	void SetScore(int C, int M, int E);//设置学生的成绩(C++、高数、英语)  
	void CountTotal();//计算总分  
	void CountAve();//计算平均分  
	void SetS(int S);//设置序号(用于排名)  
	void GetInfo(string *pN, int *pA);//得到学生的信息(得到姓名、年龄)  
	int GetNo();//得到学生的编号  

				//得到学生的分数(C++ 高数 英语 总分 平均分)  
	void GetScore(int *pC, int *pM, int *pE, int *pT, int *pA);
	int GetS();//得到序号(用于排名)  

private:
	int len;          //学生的人数  
	string Name;     //姓名  
	int Age;         //年龄  
	int No;          //学号  
	int Cpp;         //C++成绩  
	int Math;       //高数成绩  
	int English;    //英语成绩  
	int Total;     //总分  
	float Ave;      //平均分  
	int Sort;     //排名  
};


//构造函数  
Student::Student()
{
	Sort = 0;
}


void Student::SetInfo(string N, int A)//设置学生的信息(设置姓名、年龄)  
{
	Name = N;
	Age = A;
}


void Student::SetNo(int N)//设置学生的编号  
{
	No = N;
}


void Student::SetScore(int C, int M, int E)//设置学生的成绩(C++、高数、英语)  
{
	Cpp = C;
	Math = M;
	English = E;
}

void Student::CountTotal()//计算总分  
{
	Total = Cpp + Math + English;
}


void Student::CountAve()//计算学生的平均分  
{
	Ave = Total / 3;
}


void Student::SetS(int s)//设置序号(用于排名)  
{
	Sort = s;
}


void Student::GetInfo(string *pN, int *pA)//得到学生的信息(得到姓名、年龄)  
{
	*pN = Name;
	*pA = Age;
}


int Student::GetNo()//得到学生的编号  
{
	return No;
}


//得到学生的分数(C++ 高数 英语 总分 平均分)  
void Student::GetScore(int *pC, int *pM, int *pE, int *pT, int *pA)
{
	*pC = Cpp;//得到C++成绩  
	*pM = Math;//得到数学成绩  
	*pE = English;//得到英语成绩  
	*pT = Total;//得到总分  
	*pA = Ave;//得到平均分  
}


int Student::GetS()//得到序号(用于排名)  
{
	return Sort;
}


class Node//结点类  
{
public:
	void InputStudent();//输入学生信息  
	void OutputStudent();//输出学生信息  
	Node* AddStudent();//增加学生信息  
	bool DeleteStudent();//删除学生信息  
	void ChangeStudent();//修改学生信息  
	void SearchStudent();//查找学生信息  
	void SortCpp();//将C++成绩按照从大到小排序  
	void SortMath();//将高数成绩按照从大到小排序  
	void SortEnglish();//将英语成绩按照从大到小排序  
	void SortTotal();//将总分按照从大到小排序  
	void SetScort();//设置排名  
	void ChangeNo(Node *p);//修改学生的学号  

private:
	Student st;//数据域  
	Node *pNext;//指针域  
	Node *pHead;//头结点  
};
typedef Node NODE;
typedef Node* PNODE;
/*
NODE 相当于  Node
PNODE 相当于 Node*
*/


//输入学生信息  
void Node::InputStudent()
{
	//创建一个头结点  
	pHead = new NODE[sizeof(NODE)];

	if (NULL == pHead)
	{
		cout << "动态内存分配失败,程序终止!" << endl;

		exit(0);
	}

	PNODE pTail = pHead;//创建一个指向头结点的指针  
	pTail->pNext = NULL;//初始化指针的指针域为NULL  

						//将文件中的数据输入到程序中  
	ifstream infile("score.dat", ios::in);

	if (!infile)
	{
		cout << "文件打开失败,程序终止!" << endl;

		exit(0);
	}

	int num;//人数  
	string name;//姓名  
	int age;//年龄  
	int no;//学号  
	int cpp;//C++成绩  
	int math;//数学成绩  
	int english;//英语成绩  

	cout << "请输入学生的人数:";
	cin >> num;


	for (int i = 1; i <= num; i++)
	{
		//创建一个保存数据的新结点  
		PNODE pNew = new NODE[sizeof(NODE)];

		if (NULL == pNew)
		{
			cout << "动态内存分配失败,程序终止!" << endl;

			exit(0);
		}

		//读取文件中的数据  
		infile >> name >> age >> no >> cpp >> math >> english;

		//初始化结点  
		//pNew->st.SetLen(l);//学生的人数  
		pNew->st.SetInfo(name, age);//学生的姓名和年龄  
		pNew->st.SetNo(no);//学生的编号  
		pNew->st.SetScore(cpp, math, english);//设置学生的成绩(C++、高数、英语)  
		pNew->st.CountTotal();//计算学生的总分  
		pNew->st.CountAve();//计算学生的平均分  

		pTail->pNext = pNew;//将pNew挂在老结点的后面  
		pTail = pNew;//将指针pTail移到pNew上  
		pTail->pNext = NULL;//清空指针域  
	}

	//关闭文件  
	infile.close();

	cout << "已经成功的向程序中输入了" << num << "个学生的信息" << endl;
}


//遍历链表  
void Node::OutputStudent()
{
	PNODE p = pHead->pNext;

	cout << "姓名\t" << "年龄\t" << "学号\t" << "C++\t" << "数学\t" << "英语\t" << "总分\t" << "平均分\t" << "排名" << endl;

	string name;
	int age;
	int cpp;
	int math;
	int english;
	int total;
	int ave;

	//遍历学生信息  
	while (NULL != p)
	{
		p->st.GetInfo(&name, &age);
		p->st.GetScore(&cpp, &math, &english, &total, &ave);

		cout << name << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
			<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << "\t" << p->st.GetS() << endl;

		p = p->pNext;
	}
}


PNODE Node::AddStudent(void)//增加学生信息  
{
	PNODE p = pHead->pNext;
	Student st;//定义一个学生类  
	int i = 1000;
	int pos;
	string name;//姓名  
	int age;//年龄  
	int no;//学号  
	int cpp;//C++成绩  
	int math;//数学成绩  
	int english;//英语成绩  

	cout << "请输入一个学生的学号:";
	cin >> pos;

	cout << "你将在学号为" << pos << "的学生后增加一个学生" << endl;

	st.SetNo(pos + 1);//设置需要添加的学生的学号  

	cout << "增加的学生的学号为" << pos + 1 << endl;

	cout << "请输入学号为" << st.GetNo() << "的学生的姓名:";
	cin >> name;

	cout << "请输入学号为" << st.GetNo() << "的学生的年龄:";
	cin >> age;

	cout << "请输入学号为" << st.GetNo() << "的学生的C++成绩:";
	cin >> cpp;

	cout << "请输入学号为" << st.GetNo() << "的学生的数学成绩:";
	cin >> math;

	cout << "请输入学号为" << st.GetNo() << "的学生的英语成绩:";
	cin >> english;

	while (NULL != p && i<pos - 1)
	{
		p = p->pNext;
		i++;
	}

	if (NULL == p || i>pos)
	{
		cout << "程序错误!" << endl;

		exit(1);
	}

	PNODE pt = new NODE[sizeof(NODE)];

	if (NULL == pt)
	{
		printf("动态内存分配失败,程序终止!\n");
		exit(-1);
	}

	//初始化结点  
	pt->st.SetInfo(name, age);//学生的姓名和年龄  
	pt->st.SetNo(pos + 1);//学生的学号  
	pt->st.SetScore(cpp, math, english);//设置学生的成绩(C++、高数、英语)  
	pt->st.CountTotal();//计算学生的总分  
	pt->st.CountAve();//计算学生的平均分  

	PNODE q = p->pNext;
	p->pNext = pt;
	pt->pNext = q;

	return p->pNext;
}


bool Node::DeleteStudent()//删除学生信息  
{
	int i = 1000;
	int pos;
	PNODE p = pHead;

	cout << "请输入要删除的学生的学号:";
	cin >> pos;

	cout << "\n删除学号为" << pos << "后的学生信息:" << endl;

	while (NULL != p && i<pos - 1)
	{
		p = p->pNext;
		i++;
	}

	if (NULL == p || i>pos)
	{
		return true;
	}

	PNODE q = p->pNext;

	p->pNext = p->pNext->pNext;

	delete[]q;

	return true;
}


void Node::ChangeStudent()//修改学生信息  
{
	PNODE p = pHead->pNext;

	string name;//姓名  
	int age;//年龄  
	int no;//学号  
	int cpp;//C++成绩  
	int math;//数学成绩  
	int english;//英语成绩  
	int total;//总分  
	int ave;//平均分  

	int flag = 0;//标识符,初始化表示没找到  

	cout << "请输入你需要修改的学生的姓名:";
	cin >> name;

	string nm;//姓名  

			  //遍历学生信息  
	while (NULL != p)
	{
		//得到学生的姓名和年龄  
		p->st.GetInfo(&nm, &age);
		p->st.GetScore(&cpp, &math, &english, &total, &ave);

		if (name == nm)
		{
			flag = 1;

			cout << "\n修改前的学生信息:" << endl;

			cout << "姓名\t" << "年龄\t" << "学号\t" << "C++\t" << "数学\t" << "英语\t" << "总分\t" << "平均分\t" << "排名" << endl;

			cout << nm << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
				<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << endl;

			break;
		}

		p = p->pNext;
	}

	if (0 == flag)
	{
		cout << "没找到你需要修改的学生信息!\n" << endl;

		return;
	}

	cout << "\n你将修改学号为" << p->st.GetNo() << "的学生信息" << endl;

	no = p->st.GetNo();//得到学生的学号  

	cout << "请输入学号为" << p->st.GetNo() << "的学生的姓名:";
	cin >> name;

	cout << "请输入学号为" << p->st.GetNo() << "的学生的年龄:";
	cin >> age;

	cout << "请输入学号为" << p->st.GetNo() << "的学生的C++成绩:";
	cin >> cpp;

	cout << "请输入学号为" << p->st.GetNo() << "的学生的数学成绩:";
	cin >> math;

	cout << "请输入学号为" << p->st.GetNo() << "的学生的英语成绩:";
	cin >> english;

	//初始化结点  
	p->st.SetInfo(name, age);//学生的姓名和年龄  
	p->st.SetNo(no);//学生的编号  
	p->st.SetScore(cpp, math, english);//设置学生的成绩(C++、高数、英语)  
	p->st.CountTotal();//计算学生的总分  
	p->st.CountAve();//计算学生的平均分  

	cout << "\n修改后的学生信息:" << endl;
	cout << "姓名\t" << "年龄\t" << "学号\t" << "C++\t" << "数学\t" << "英语\t" << "总分\t" << "平均分\t" << "排名" << endl;

	//得到学生的姓名和年龄吧  
	p->st.GetInfo(&name, &age);

	//得到学生的成绩  
	p->st.GetScore(&cpp, &math, &english, &total, &ave);

	cout << name << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
		<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << endl;
}


void Node::SearchStudent()//查找学生信息  
{
	PNODE p = pHead->pNext;

	string name;//姓名  

	int flag = 0;//标识符,初始化表示没找到  

	cout << "请输入你需要查找的学生的姓名:";
	cin >> name;

	cout << "姓名\t" << "年龄\t" << "学号\t" << "C++\t" << "数学\t" << "英语\t" << "总分\t" << "平均分\t" << "排名" << endl;

	string nm;//姓名  
	int age;//年龄  
	int no;//学号  
	int cpp;//C++成绩  
	int math;//数学成绩  
	int english;//英语成绩  
	int total;//总分  
	int ave;//平均分  

			//遍历学生信息  
	while (NULL != p)
	{
		//得到学生的姓名和年龄  
		p->st.GetInfo(&nm, &age);

		//得到学生的成绩  
		p->st.GetScore(&cpp, &math, &english, &total, &ave);

		if (name == nm)
		{
			flag = 1;

			cout << name << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
				<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << endl;

			break;//退出循环  
		}

		p = p->pNext;
	}

	if (0 == flag)
	{
		cout << "没找到你需要的学生信息!" << endl;
	}
}


void Node::SortCpp()//将C++成绩按照从大到小排序  
{
	PNODE p, q;//定义两个指针  


	NODE temp;//定义一个临时结点  

	int cpp1, cpp2;//C++成绩  
	int math1, math2;//数学成绩  
	int english1, english2;//英语成绩  
	int total1, total2;//总分  
	int ave1, ave2;//平均分  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (cpp1 < cpp2)//当前一个学生的C++成绩小于后一个学生的C++成绩时  
			{
				temp.st = p->st;//交换学生的位置  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SortMath()//将高数成绩按照从大到小排序  
{
	PNODE p, q;//定义两个指针  

	NODE temp;//定义一个临时结点  

	int cpp1, cpp2;//C++成绩  
	int math1, math2;//数学成绩  
	int english1, english2;//英语成绩  
	int total1, total2;//总分  
	int ave1, ave2;//平均分  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (math1 < math2)//当前一个学生的高数成绩小于后一个学生的高数成绩时  
			{
				temp.st = p->st;//交换学生的位置(交换结点中的数据域)  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SortEnglish()//将英语成绩按照从大到小排序  
{
	PNODE p, q;//定义两个指针  

	NODE temp;//定义一个临时结点  

	int cpp1, cpp2;//C++成绩  
	int math1, math2;//数学成绩  
	int english1, english2;//英语成绩  
	int total1, total2;//总分  
	int ave1, ave2;//平均分  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (english1 < english2)//当前一个学生的英语成绩小于后一个学生的英语成绩时  
			{
				temp.st = p->st;//交换学生的位置(交换结点中的数据域)  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SortTotal()//将总分按照从大到小排序  
{
	PNODE p, q;//定义两个指针  

	NODE temp;//定义一个临时结点  

	int cpp1, cpp2;//C++成绩  
	int math1, math2;//数学成绩  
	int english1, english2;//英语成绩  
	int total1, total2;//总分  
	int ave1, ave2;//平均分  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (total1 < total2)//当前一个学生的总分小于后一个学生的总分时  
			{
				temp.st = p->st;//交换学生的位置(交换结点中的数据域)  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SetScort()//设置排名  
{
	PNODE p;//定义一个指向结点的指针  
	int i;//保存排名  

		  //给学生的排名赋值  
	for (p = pHead->pNext, i = 1; NULL != p; p = p->pNext, i++)
	{
		p->st.SetS(i);
	}
}


//修改学生的学号  
void Node::ChangeNo(PNODE p)
{
	int i = p->st.GetNo();//提供修改的数据  

						  //遍历学生信息  
	while (NULL != p)
	{
		p->st.SetNo(i);

		i++;

		p = p->pNext;
	}
}


void main()
{

	cout << "================================================================================\n" << endl;
	cout << "================================================================================\n" << endl;
	cout << "*************************欢迎使用学生成绩管理系统*******************************\n" << endl;
	cout << "-----------------------------------------------------------------制作人:梅沙小子\n" << endl;
	cout << "********************************************************************************\n" << endl;
	cout << "================================================================================\n" << endl;

	cout << "请按任意将进入学生管理系统:";
	getchar();
	system("cls");

	cout << "===============================================================================\n\n";
	cout << "------------------------ 请选择要操作的命令：----------------------------------\n\n";
	cout << "-------------------------- 1 输入学生信息--------------------------------------\n\n";
	cout << "-------------------------- 2 输出学生信息--------------------------------------\n\n";
	cout << "-------------------------- 3 增加学生信息--------------------------------------\n\n";
	cout << "-------------------------- 4 删除学生信息--------------------------------------\n\n";
	cout << "-------------------------- 5 修改学生信息--------------------------------------\n\n";
	cout << "-------------------------- 6 查找学生信息--------------------------------------\n\n";
	cout << "-------------------------- 7 将学生的C++成绩按从大到小排----------------------\n\n";
	cout << "-------------------------- 8 将学生的高数成绩按从大到小排----------------------\n\n";
	cout << "-------------------------- 9 将学生的英语成绩按从大到小排----------------------\n\n";
	cout << "--------------------------10 将学生的总成绩按从大到小排------------------------\n\n";
	cout << "===============================================================================\n\n";

	int Item;//操作命令  

	NODE pHead;//定义一个结点  

	while (1)
	{
		cout << "\n请选择操作命令:";
		cin >> Item;
		system("cls");//清屏    

		switch (Item)
		{
		case 1://输入学生信息    
		{
			//创建链表  
			pHead.InputStudent();
		}
		break;

		case 2://输出学生信息    
		{
			//遍历链表  
			pHead.OutputStudent();
		}
		break;

		case 3://增加学生信息    
		{
			PNODE q;
			q = pHead.AddStudent();
			pHead.ChangeNo(q);//修改学号8  
		}
		break;

		case 4://删除学生信息    
		{
			pHead.DeleteStudent();
			pHead.OutputStudent();
		}
		break;

		case 5://修改学生信息    
		{
			pHead.ChangeStudent();
		}
		break;

		case 6://查找学生信息    
		{
			pHead.SearchStudent();
		}
		break;


		case 7://对学生的C++成绩排序    
		{
			pHead.SortCpp();//C++排序  
			cout << "C++成绩排序后的结果:" << endl;
			pHead.SetScort();//设置排名  
			pHead.OutputStudent();//打印排序后的结果  
		}
		break;

		case 8://对学生的高数成绩排序    
		{
			pHead.SortMath();//高数排序  
			cout << "高数成绩排序后的结果:" << endl;
			pHead.SetScort();//设置排名  
			pHead.OutputStudent();//打印排序后的结果  
		}
		break;

		case 9://对学生的英语成绩排序    
		{
			pHead.SortEnglish();//英语排序  
			cout << "英语成绩排序后的结果:" << endl;
			pHead.SetScort();//设置排名  
			pHead.OutputStudent();//打印排序后的结果  
		}
		break;

		case 10://对学生的总分排序    
		{
			pHead.SortTotal();//总分排序  
			cout << "总分排序后的结果:" << endl;
			pHead.SetScort();//设置排序  
			pHead.OutputStudent();//打印排序后的结果  
		}
		break;
		default:
			break;
		}
	}

	system("pause");
}