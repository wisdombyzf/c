#include <iostream>  
#include <cstdlib>  
#include <string>  
#include <fstream>  

using namespace std;

class Student//ѧ����  
{
public:
	Student();//���캯��  
	void SetInfo(string N, int A);//����ѧ������Ϣ(��������������)  
	void SetNo(int N);//����ѧ���ı��  
	void SetScore(int C, int M, int E);//����ѧ���ĳɼ�(C++��������Ӣ��)  
	void CountTotal();//�����ܷ�  
	void CountAve();//����ƽ����  
	void SetS(int S);//�������(��������)  
	void GetInfo(string *pN, int *pA);//�õ�ѧ������Ϣ(�õ�����������)  
	int GetNo();//�õ�ѧ���ı��  

				//�õ�ѧ���ķ���(C++ ���� Ӣ�� �ܷ� ƽ����)  
	void GetScore(int *pC, int *pM, int *pE, int *pT, int *pA);
	int GetS();//�õ����(��������)  

private:
	int len;          //ѧ��������  
	string Name;     //����  
	int Age;         //����  
	int No;          //ѧ��  
	int Cpp;         //C++�ɼ�  
	int Math;       //�����ɼ�  
	int English;    //Ӣ��ɼ�  
	int Total;     //�ܷ�  
	float Ave;      //ƽ����  
	int Sort;     //����  
};


//���캯��  
Student::Student()
{
	Sort = 0;
}


void Student::SetInfo(string N, int A)//����ѧ������Ϣ(��������������)  
{
	Name = N;
	Age = A;
}


void Student::SetNo(int N)//����ѧ���ı��  
{
	No = N;
}


void Student::SetScore(int C, int M, int E)//����ѧ���ĳɼ�(C++��������Ӣ��)  
{
	Cpp = C;
	Math = M;
	English = E;
}

void Student::CountTotal()//�����ܷ�  
{
	Total = Cpp + Math + English;
}


void Student::CountAve()//����ѧ����ƽ����  
{
	Ave = Total / 3;
}


void Student::SetS(int s)//�������(��������)  
{
	Sort = s;
}


void Student::GetInfo(string *pN, int *pA)//�õ�ѧ������Ϣ(�õ�����������)  
{
	*pN = Name;
	*pA = Age;
}


int Student::GetNo()//�õ�ѧ���ı��  
{
	return No;
}


//�õ�ѧ���ķ���(C++ ���� Ӣ�� �ܷ� ƽ����)  
void Student::GetScore(int *pC, int *pM, int *pE, int *pT, int *pA)
{
	*pC = Cpp;//�õ�C++�ɼ�  
	*pM = Math;//�õ���ѧ�ɼ�  
	*pE = English;//�õ�Ӣ��ɼ�  
	*pT = Total;//�õ��ܷ�  
	*pA = Ave;//�õ�ƽ����  
}


int Student::GetS()//�õ����(��������)  
{
	return Sort;
}


class Node//�����  
{
public:
	void InputStudent();//����ѧ����Ϣ  
	void OutputStudent();//���ѧ����Ϣ  
	Node* AddStudent();//����ѧ����Ϣ  
	bool DeleteStudent();//ɾ��ѧ����Ϣ  
	void ChangeStudent();//�޸�ѧ����Ϣ  
	void SearchStudent();//����ѧ����Ϣ  
	void SortCpp();//��C++�ɼ����մӴ�С����  
	void SortMath();//�������ɼ����մӴ�С����  
	void SortEnglish();//��Ӣ��ɼ����մӴ�С����  
	void SortTotal();//���ְܷ��մӴ�С����  
	void SetScort();//��������  
	void ChangeNo(Node *p);//�޸�ѧ����ѧ��  

private:
	Student st;//������  
	Node *pNext;//ָ����  
	Node *pHead;//ͷ���  
};
typedef Node NODE;
typedef Node* PNODE;
/*
NODE �൱��  Node
PNODE �൱�� Node*
*/


//����ѧ����Ϣ  
void Node::InputStudent()
{
	//����һ��ͷ���  
	pHead = new NODE[sizeof(NODE)];

	if (NULL == pHead)
	{
		cout << "��̬�ڴ����ʧ��,������ֹ!" << endl;

		exit(0);
	}

	PNODE pTail = pHead;//����һ��ָ��ͷ����ָ��  
	pTail->pNext = NULL;//��ʼ��ָ���ָ����ΪNULL  

						//���ļ��е��������뵽������  
	ifstream infile("score.dat", ios::in);

	if (!infile)
	{
		cout << "�ļ���ʧ��,������ֹ!" << endl;

		exit(0);
	}

	int num;//����  
	string name;//����  
	int age;//����  
	int no;//ѧ��  
	int cpp;//C++�ɼ�  
	int math;//��ѧ�ɼ�  
	int english;//Ӣ��ɼ�  

	cout << "������ѧ��������:";
	cin >> num;


	for (int i = 1; i <= num; i++)
	{
		//����һ���������ݵ��½��  
		PNODE pNew = new NODE[sizeof(NODE)];

		if (NULL == pNew)
		{
			cout << "��̬�ڴ����ʧ��,������ֹ!" << endl;

			exit(0);
		}

		//��ȡ�ļ��е�����  
		infile >> name >> age >> no >> cpp >> math >> english;

		//��ʼ�����  
		//pNew->st.SetLen(l);//ѧ��������  
		pNew->st.SetInfo(name, age);//ѧ��������������  
		pNew->st.SetNo(no);//ѧ���ı��  
		pNew->st.SetScore(cpp, math, english);//����ѧ���ĳɼ�(C++��������Ӣ��)  
		pNew->st.CountTotal();//����ѧ�����ܷ�  
		pNew->st.CountAve();//����ѧ����ƽ����  

		pTail->pNext = pNew;//��pNew�����Ͻ��ĺ���  
		pTail = pNew;//��ָ��pTail�Ƶ�pNew��  
		pTail->pNext = NULL;//���ָ����  
	}

	//�ر��ļ�  
	infile.close();

	cout << "�Ѿ��ɹ����������������" << num << "��ѧ������Ϣ" << endl;
}


//��������  
void Node::OutputStudent()
{
	PNODE p = pHead->pNext;

	cout << "����\t" << "����\t" << "ѧ��\t" << "C++\t" << "��ѧ\t" << "Ӣ��\t" << "�ܷ�\t" << "ƽ����\t" << "����" << endl;

	string name;
	int age;
	int cpp;
	int math;
	int english;
	int total;
	int ave;

	//����ѧ����Ϣ  
	while (NULL != p)
	{
		p->st.GetInfo(&name, &age);
		p->st.GetScore(&cpp, &math, &english, &total, &ave);

		cout << name << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
			<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << "\t" << p->st.GetS() << endl;

		p = p->pNext;
	}
}


PNODE Node::AddStudent(void)//����ѧ����Ϣ  
{
	PNODE p = pHead->pNext;
	Student st;//����һ��ѧ����  
	int i = 1000;
	int pos;
	string name;//����  
	int age;//����  
	int no;//ѧ��  
	int cpp;//C++�ɼ�  
	int math;//��ѧ�ɼ�  
	int english;//Ӣ��ɼ�  

	cout << "������һ��ѧ����ѧ��:";
	cin >> pos;

	cout << "�㽫��ѧ��Ϊ" << pos << "��ѧ��������һ��ѧ��" << endl;

	st.SetNo(pos + 1);//������Ҫ��ӵ�ѧ����ѧ��  

	cout << "���ӵ�ѧ����ѧ��Ϊ" << pos + 1 << endl;

	cout << "������ѧ��Ϊ" << st.GetNo() << "��ѧ��������:";
	cin >> name;

	cout << "������ѧ��Ϊ" << st.GetNo() << "��ѧ��������:";
	cin >> age;

	cout << "������ѧ��Ϊ" << st.GetNo() << "��ѧ����C++�ɼ�:";
	cin >> cpp;

	cout << "������ѧ��Ϊ" << st.GetNo() << "��ѧ������ѧ�ɼ�:";
	cin >> math;

	cout << "������ѧ��Ϊ" << st.GetNo() << "��ѧ����Ӣ��ɼ�:";
	cin >> english;

	while (NULL != p && i<pos - 1)
	{
		p = p->pNext;
		i++;
	}

	if (NULL == p || i>pos)
	{
		cout << "�������!" << endl;

		exit(1);
	}

	PNODE pt = new NODE[sizeof(NODE)];

	if (NULL == pt)
	{
		printf("��̬�ڴ����ʧ��,������ֹ!\n");
		exit(-1);
	}

	//��ʼ�����  
	pt->st.SetInfo(name, age);//ѧ��������������  
	pt->st.SetNo(pos + 1);//ѧ����ѧ��  
	pt->st.SetScore(cpp, math, english);//����ѧ���ĳɼ�(C++��������Ӣ��)  
	pt->st.CountTotal();//����ѧ�����ܷ�  
	pt->st.CountAve();//����ѧ����ƽ����  

	PNODE q = p->pNext;
	p->pNext = pt;
	pt->pNext = q;

	return p->pNext;
}


bool Node::DeleteStudent()//ɾ��ѧ����Ϣ  
{
	int i = 1000;
	int pos;
	PNODE p = pHead;

	cout << "������Ҫɾ����ѧ����ѧ��:";
	cin >> pos;

	cout << "\nɾ��ѧ��Ϊ" << pos << "���ѧ����Ϣ:" << endl;

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


void Node::ChangeStudent()//�޸�ѧ����Ϣ  
{
	PNODE p = pHead->pNext;

	string name;//����  
	int age;//����  
	int no;//ѧ��  
	int cpp;//C++�ɼ�  
	int math;//��ѧ�ɼ�  
	int english;//Ӣ��ɼ�  
	int total;//�ܷ�  
	int ave;//ƽ����  

	int flag = 0;//��ʶ��,��ʼ����ʾû�ҵ�  

	cout << "����������Ҫ�޸ĵ�ѧ��������:";
	cin >> name;

	string nm;//����  

			  //����ѧ����Ϣ  
	while (NULL != p)
	{
		//�õ�ѧ��������������  
		p->st.GetInfo(&nm, &age);
		p->st.GetScore(&cpp, &math, &english, &total, &ave);

		if (name == nm)
		{
			flag = 1;

			cout << "\n�޸�ǰ��ѧ����Ϣ:" << endl;

			cout << "����\t" << "����\t" << "ѧ��\t" << "C++\t" << "��ѧ\t" << "Ӣ��\t" << "�ܷ�\t" << "ƽ����\t" << "����" << endl;

			cout << nm << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
				<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << endl;

			break;
		}

		p = p->pNext;
	}

	if (0 == flag)
	{
		cout << "û�ҵ�����Ҫ�޸ĵ�ѧ����Ϣ!\n" << endl;

		return;
	}

	cout << "\n�㽫�޸�ѧ��Ϊ" << p->st.GetNo() << "��ѧ����Ϣ" << endl;

	no = p->st.GetNo();//�õ�ѧ����ѧ��  

	cout << "������ѧ��Ϊ" << p->st.GetNo() << "��ѧ��������:";
	cin >> name;

	cout << "������ѧ��Ϊ" << p->st.GetNo() << "��ѧ��������:";
	cin >> age;

	cout << "������ѧ��Ϊ" << p->st.GetNo() << "��ѧ����C++�ɼ�:";
	cin >> cpp;

	cout << "������ѧ��Ϊ" << p->st.GetNo() << "��ѧ������ѧ�ɼ�:";
	cin >> math;

	cout << "������ѧ��Ϊ" << p->st.GetNo() << "��ѧ����Ӣ��ɼ�:";
	cin >> english;

	//��ʼ�����  
	p->st.SetInfo(name, age);//ѧ��������������  
	p->st.SetNo(no);//ѧ���ı��  
	p->st.SetScore(cpp, math, english);//����ѧ���ĳɼ�(C++��������Ӣ��)  
	p->st.CountTotal();//����ѧ�����ܷ�  
	p->st.CountAve();//����ѧ����ƽ����  

	cout << "\n�޸ĺ��ѧ����Ϣ:" << endl;
	cout << "����\t" << "����\t" << "ѧ��\t" << "C++\t" << "��ѧ\t" << "Ӣ��\t" << "�ܷ�\t" << "ƽ����\t" << "����" << endl;

	//�õ�ѧ���������������  
	p->st.GetInfo(&name, &age);

	//�õ�ѧ���ĳɼ�  
	p->st.GetScore(&cpp, &math, &english, &total, &ave);

	cout << name << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
		<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << endl;
}


void Node::SearchStudent()//����ѧ����Ϣ  
{
	PNODE p = pHead->pNext;

	string name;//����  

	int flag = 0;//��ʶ��,��ʼ����ʾû�ҵ�  

	cout << "����������Ҫ���ҵ�ѧ��������:";
	cin >> name;

	cout << "����\t" << "����\t" << "ѧ��\t" << "C++\t" << "��ѧ\t" << "Ӣ��\t" << "�ܷ�\t" << "ƽ����\t" << "����" << endl;

	string nm;//����  
	int age;//����  
	int no;//ѧ��  
	int cpp;//C++�ɼ�  
	int math;//��ѧ�ɼ�  
	int english;//Ӣ��ɼ�  
	int total;//�ܷ�  
	int ave;//ƽ����  

			//����ѧ����Ϣ  
	while (NULL != p)
	{
		//�õ�ѧ��������������  
		p->st.GetInfo(&nm, &age);

		//�õ�ѧ���ĳɼ�  
		p->st.GetScore(&cpp, &math, &english, &total, &ave);

		if (name == nm)
		{
			flag = 1;

			cout << name << "\t" << age << "\t" << p->st.GetNo() << "\t" << cpp
				<< "\t" << math << "\t" << english << "\t" << total << "\t" << ave << endl;

			break;//�˳�ѭ��  
		}

		p = p->pNext;
	}

	if (0 == flag)
	{
		cout << "û�ҵ�����Ҫ��ѧ����Ϣ!" << endl;
	}
}


void Node::SortCpp()//��C++�ɼ����մӴ�С����  
{
	PNODE p, q;//��������ָ��  


	NODE temp;//����һ����ʱ���  

	int cpp1, cpp2;//C++�ɼ�  
	int math1, math2;//��ѧ�ɼ�  
	int english1, english2;//Ӣ��ɼ�  
	int total1, total2;//�ܷ�  
	int ave1, ave2;//ƽ����  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (cpp1 < cpp2)//��ǰһ��ѧ����C++�ɼ�С�ں�һ��ѧ����C++�ɼ�ʱ  
			{
				temp.st = p->st;//����ѧ����λ��  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SortMath()//�������ɼ����մӴ�С����  
{
	PNODE p, q;//��������ָ��  

	NODE temp;//����һ����ʱ���  

	int cpp1, cpp2;//C++�ɼ�  
	int math1, math2;//��ѧ�ɼ�  
	int english1, english2;//Ӣ��ɼ�  
	int total1, total2;//�ܷ�  
	int ave1, ave2;//ƽ����  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (math1 < math2)//��ǰһ��ѧ���ĸ����ɼ�С�ں�һ��ѧ���ĸ����ɼ�ʱ  
			{
				temp.st = p->st;//����ѧ����λ��(��������е�������)  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SortEnglish()//��Ӣ��ɼ����մӴ�С����  
{
	PNODE p, q;//��������ָ��  

	NODE temp;//����һ����ʱ���  

	int cpp1, cpp2;//C++�ɼ�  
	int math1, math2;//��ѧ�ɼ�  
	int english1, english2;//Ӣ��ɼ�  
	int total1, total2;//�ܷ�  
	int ave1, ave2;//ƽ����  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (english1 < english2)//��ǰһ��ѧ����Ӣ��ɼ�С�ں�һ��ѧ����Ӣ��ɼ�ʱ  
			{
				temp.st = p->st;//����ѧ����λ��(��������е�������)  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SortTotal()//���ְܷ��մӴ�С����  
{
	PNODE p, q;//��������ָ��  

	NODE temp;//����һ����ʱ���  

	int cpp1, cpp2;//C++�ɼ�  
	int math1, math2;//��ѧ�ɼ�  
	int english1, english2;//Ӣ��ɼ�  
	int total1, total2;//�ܷ�  
	int ave1, ave2;//ƽ����  

	for (p = pHead->pNext; NULL != p; p = p->pNext)
	{
		for (q = p->pNext; NULL != q; q = q->pNext)
		{
			p->st.GetScore(&cpp1, &math1, &english1, &total1, &ave1);
			q->st.GetScore(&cpp2, &math2, &english2, &total2, &ave2);

			if (total1 < total2)//��ǰһ��ѧ�����ܷ�С�ں�һ��ѧ�����ܷ�ʱ  
			{
				temp.st = p->st;//����ѧ����λ��(��������е�������)  
				p->st = q->st;
				q->st = temp.st;
			}
		}
	}
}


void Node::SetScort()//��������  
{
	PNODE p;//����һ��ָ�����ָ��  
	int i;//��������  

		  //��ѧ����������ֵ  
	for (p = pHead->pNext, i = 1; NULL != p; p = p->pNext, i++)
	{
		p->st.SetS(i);
	}
}


//�޸�ѧ����ѧ��  
void Node::ChangeNo(PNODE p)
{
	int i = p->st.GetNo();//�ṩ�޸ĵ�����  

						  //����ѧ����Ϣ  
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
	cout << "*************************��ӭʹ��ѧ���ɼ�����ϵͳ*******************************\n" << endl;
	cout << "-----------------------------------------------------------------������:÷ɳС��\n" << endl;
	cout << "********************************************************************************\n" << endl;
	cout << "================================================================================\n" << endl;

	cout << "�밴���⽫����ѧ������ϵͳ:";
	getchar();
	system("cls");

	cout << "===============================================================================\n\n";
	cout << "------------------------ ��ѡ��Ҫ���������----------------------------------\n\n";
	cout << "-------------------------- 1 ����ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 2 ���ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 3 ����ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 4 ɾ��ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 5 �޸�ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 6 ����ѧ����Ϣ--------------------------------------\n\n";
	cout << "-------------------------- 7 ��ѧ����C++�ɼ����Ӵ�С��----------------------\n\n";
	cout << "-------------------------- 8 ��ѧ���ĸ����ɼ����Ӵ�С��----------------------\n\n";
	cout << "-------------------------- 9 ��ѧ����Ӣ��ɼ����Ӵ�С��----------------------\n\n";
	cout << "--------------------------10 ��ѧ�����ܳɼ����Ӵ�С��------------------------\n\n";
	cout << "===============================================================================\n\n";

	int Item;//��������  

	NODE pHead;//����һ�����  

	while (1)
	{
		cout << "\n��ѡ���������:";
		cin >> Item;
		system("cls");//����    

		switch (Item)
		{
		case 1://����ѧ����Ϣ    
		{
			//��������  
			pHead.InputStudent();
		}
		break;

		case 2://���ѧ����Ϣ    
		{
			//��������  
			pHead.OutputStudent();
		}
		break;

		case 3://����ѧ����Ϣ    
		{
			PNODE q;
			q = pHead.AddStudent();
			pHead.ChangeNo(q);//�޸�ѧ��8  
		}
		break;

		case 4://ɾ��ѧ����Ϣ    
		{
			pHead.DeleteStudent();
			pHead.OutputStudent();
		}
		break;

		case 5://�޸�ѧ����Ϣ    
		{
			pHead.ChangeStudent();
		}
		break;

		case 6://����ѧ����Ϣ    
		{
			pHead.SearchStudent();
		}
		break;


		case 7://��ѧ����C++�ɼ�����    
		{
			pHead.SortCpp();//C++����  
			cout << "C++�ɼ������Ľ��:" << endl;
			pHead.SetScort();//��������  
			pHead.OutputStudent();//��ӡ�����Ľ��  
		}
		break;

		case 8://��ѧ���ĸ����ɼ�����    
		{
			pHead.SortMath();//��������  
			cout << "�����ɼ������Ľ��:" << endl;
			pHead.SetScort();//��������  
			pHead.OutputStudent();//��ӡ�����Ľ��  
		}
		break;

		case 9://��ѧ����Ӣ��ɼ�����    
		{
			pHead.SortEnglish();//Ӣ������  
			cout << "Ӣ��ɼ������Ľ��:" << endl;
			pHead.SetScort();//��������  
			pHead.OutputStudent();//��ӡ�����Ľ��  
		}
		break;

		case 10://��ѧ�����ܷ�����    
		{
			pHead.SortTotal();//�ܷ�����  
			cout << "�ܷ������Ľ��:" << endl;
			pHead.SetScort();//��������  
			pHead.OutputStudent();//��ӡ�����Ľ��  
		}
		break;
		default:
			break;
		}
	}

	system("pause");
}