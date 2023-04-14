//#define _CRT_SECURE_NO_WARNNINGS //避免警告
#include "Staff.h"
#include<iostream>
#include<windows.h>//控制台编程主要头文件
#include<iomanip>//用到setw()函数
#include<conio.h>//_getch()
using namespace std;

//保存文件函数   保存输入的数据到文件中
bool StaffSave(StaffNode* head)
{
	StaffNode* p = NULL;//用指针p依次指向链表各个结点
	FILE* fp;        //定义文件类型指针
	int i = 0;
	char isSave[10] = "0";//是否保存变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "是否保存？(Y/N):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> isSave;
	while (strcmp(isSave, "Y") != 0 && strcmp(isSave, "y") != 0 && strcmp(isSave, "N") != 0 && strcmp(isSave, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> isSave;
	}

	if (strcmp(isSave, "N") == 0 || strcmp(isSave, "n") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	else if (strcmp(isSave, "Y") == 0 || strcmp(isSave, "y") == 0)
	{
		fopen_s(&fp, "StaffData.txt", "w+");
		if (fp == NULL)
			//if (!fp)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "创建文件失败!" << endl;
			return 0;
		}
		i = 0;
		//将每个员工信息写入文件
		p = head;
		while (p != NULL)
			//while (i < size)
		{
			fprintf(fp, "%s\t", p->data.staffNumber);
			fprintf(fp, "%s\t", p->data.staffName);
			fprintf(fp, "%s\t", p->data.staffgender);
			fprintf(fp, "%d\t", p->data.staffMonthSaleQuantity);
			fprintf(fp, "%f\t", p->data.staffMonthSaleAmount);
			fprintf(fp, "%d\t", p->data.staffTotalSaleQuantity);
			fprintf(fp, "%f\t\n", p->data.staffTotalSaleAmount);
			p = p->next; //指针指向下一个节点
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "共输入" << i << "个员工的信息到文件中！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		fclose(fp);
		return 1;
	}
}

//读取数据函数   读取文件中的数据到内存中
StaffNode* StaffRead(StaffNode* head)
{
	head = NULL;  //头指针
	StaffNode* p1 = NULL;  //用指针p指向要插入的新结点
	StaffNode* p2 = NULL;  //用指针p指向要插入的新结点
	FILE* fp;               //定义文件类型指针
	int i = 0;//循环控制
	fopen_s(&fp, "StaffData.txt", "r");
	if (fp == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "读取文件失败!\n" << endl;
		return 0;
	}
	while (!feof(fp)) //表示没有指向文件末尾，没指向末尾为0
	{
		p1 = new StaffNode;
		fscanf_s(fp, "%s\t", &p1->data.staffNumber, 8);
		fscanf_s(fp, "%s\t", &p1->data.staffName, 20);
		fscanf_s(fp, "%s\t", &p1->data.staffgender, 20);
		fscanf_s(fp, "%d\t", &p1->data.staffMonthSaleQuantity, 20);
		fscanf_s(fp, "%f\t", &p1->data.staffMonthSaleAmount, 20);
		fscanf_s(fp, "%d\t", &p1->data.staffTotalSaleQuantity, 20);
		fscanf_s(fp, "%f\t\n", &p1->data.staffTotalSaleAmount, 20);
		//p->next = NULL;
		if (head == NULL)
		{
			head = p1;
			p2 = p1;
		}
		else
		{
			p2->next = p1;
			p2 = p1;
		}
		i++;
	}
	p2->next = NULL;
	//size = i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "共读取" << i << "个员工的信息到内存中！" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	fclose(fp);
	return head;
}


//员工数据初始化
StaffNode* StaffInit(StaffNode* head)
{
	head = NULL;
	StaffNode* p1 = NULL;
	StaffNode* p2 = NULL;
	int i = 0;
	p1 = new StaffNode;
	cout << "员工系统初始化！" << endl;
	strcpy(p1->data.staffNumber, "001");
	strcpy(p1->data.staffName, "曾浚峰");
	strcpy(p1->data.staffgender, "男");
	p1->data.staffMonthSaleQuantity = 2222;
	p1->data.staffMonthSaleAmount = 3333;
	p1->data.staffTotalSaleQuantity = 2777;
	p1->data.staffTotalSaleAmount = 5555;
	head = p1;
	p2 = p1;

	p1 = new StaffNode;
	strcpy(p1->data.staffNumber, "002");
	strcpy(p1->data.staffName, "匡婉莹");
	strcpy(p1->data.staffgender, "女");
	p1->data.staffMonthSaleQuantity = 2777;
	p1->data.staffMonthSaleAmount = 2222;
	p1->data.staffTotalSaleQuantity = 1122;
	p1->data.staffTotalSaleAmount = 2222;
	p2->next = p1;
	p2 = p1;

	p1 = new StaffNode;
	strcpy(p1->data.staffNumber, "003");
	strcpy(p1->data.staffName, "苟银颖");
	strcpy(p1->data.staffgender, "女");
	p1->data.staffMonthSaleQuantity = 1111;
	p1->data.staffMonthSaleAmount = 4777;
	p1->data.staffTotalSaleQuantity = 3333;
	p1->data.staffTotalSaleAmount = 1122;
	p2->next = p1;
	p2 = p1;

	p1 = new StaffNode;
	strcpy(p1->data.staffNumber, "004");
	strcpy(p1->data.staffName, "马辰");
	strcpy(p1->data.staffgender, "男");
	p1->data.staffMonthSaleQuantity = 3333;
	p1->data.staffMonthSaleAmount = 4555;
	p1->data.staffTotalSaleQuantity = 4777;
	p1->data.staffTotalSaleAmount = 2777;
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;

	StaffSave(head);
	cout << "员工系统初始化成功！" << endl;
	cout << "请按任意键继续" << endl;
	_getch();
	return head;
}

//创建员工信息
StaffNode* StaffCreate(StaffNode* head)
{
	head = NULL;
	StaffNode* p1 = NULL;
	StaffNode* p2 = NULL;
	int i = 0;//循环变量
	int m = 0;//员工的数量

	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******请确定是否为误操作！(Y or N)*******" << endl;
	cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
	cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       请输入您的选择:";
	char b[10] = "0";//确认误操作变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> b;
	while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0)
	{

		cout << "请输入需要输入的员工数量:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> m;
		system("cls");//清屏 

		if (m == 0)
		{
			return 0;
		}
		//链表为空即无结点时，p0作为链表的第一个结点
		for (int i = 0; i < m; i++)
		{
			p1 = new StaffNode;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "请输入第" << i + 1 << "个员工的编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的性别:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffgender;
			while (strcmp(p1->data.staffgender, "男") != 0 && strcmp(p1->data.staffgender, "女") != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "非法输入！请重新输入:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> p1->data.staffgender;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的当月销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffMonthSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的当月销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffMonthSaleAmount;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的累计销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffTotalSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的累计销售金额 :";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffTotalSaleAmount;
			cout << endl;
			if (head == NULL)
			{
				head = p1;
				p2 = p1;
			}
			else
			{
				p2->next = p1;
				p2 = p1;
			}
		}
		p2->next = NULL;//结束标志
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "共输入" << m << "个员工的信息！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		StaffSave(head); //保存数据到文件中
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	return head;
}

//增加员工的信息
StaffNode* StaffAdd(StaffNode* head)
{
	StaffNode* p1 = NULL;
	StaffNode* p2 = NULL;
	int i = 0;//循环变量
	int m = 0;//员工的数量

	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******请确定是否为误操作！(Y or N)*******" << endl;
	cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
	cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       请输入您的选择:";
	char b[10] = "0";//确认误操作变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> b;
	while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0)
	{

		cout << "请输入需要输入的员工数量:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> m;
		system("cls");//清屏 

		if (m == 0)
		{
			return 0;
		}

		p2 = head;
		while (p2->next != NULL)//判断是否为表尾，表尾的标志为p2->next == NULL
		{
			p2 = p2->next;
		}

		for (int i = 0; i < m; i++)
		{
			p1 = new StaffNode;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "请输入第" << i + 1 << "个员工的编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的性别:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffgender;
			while (strcmp(p1->data.staffgender, "男") != 0 && strcmp(p1->data.staffgender, "女") != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "非法输入！请重新输入:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> p1->data.staffgender;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的当月销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffMonthSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的当月销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffMonthSaleAmount;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的累计销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffTotalSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "员工的累计销售金额 :";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.staffTotalSaleAmount;
			cout << endl;
			p2->next = p1;
			p2 = p1;

		}
		p2->next = NULL;//结束标志
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "共输入" << m << "个员工的信息！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		StaffSave(head); //保存数据到文件中
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	return head;

}


//输出员工的信息
void StaffOutput(StaffNode* head)
{
	StaffNode* p = head;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
		<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
	cout << endl;

	if (p == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "很抱歉，文件中没有员工信息，请先添加员工信息！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请按任意键继续" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		_getch();
		return;
	}
	while (p != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
		cout << setw(3) << p->data.staffNumber << '\t'
			<< setw(3) << p->data.staffName << '\t'
			<< setw(3) << p->data.staffgender << '\t'
			<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
			<< setw(8) << p->data.staffMonthSaleAmount << '\t'
			<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
			<< setw(8) << p->data.staffTotalSaleAmount << '\t'
			<< endl;
		p = p->next;//指向下一个结点
	}
	cout << endl;
}

//删除员工信息
StaffNode* StaffDel(StaffNode* head)
{
	StaffOutput(head);
	StaffNode* p = head;//指向结点的指针
	if (p == NULL)
		return 0;
	StaffNode* q;//内循环结点
	int i = 0;//用于遍历找到所查询信息位置
	int k = 0;//用于判断是否有此员工
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	char choose[10] = "0";
	cout << "\t\t                            *****************************" << endl;
	cout << "\t\t                          *******  请选择删除依据:  *******" << endl;
	cout << "\t\t                        *******     1-->按员工编号    *******" << endl;
	cout << "\t\t                       *******      2-->按员工名称     *******" << endl;
	cout << "\t\t                        *******     3-->按员工性别    *******" << endl;
	cout << "\t\t                         *******    4-->返回主菜单   *******" << endl;
	cout << "\t\t                            *****************************" << endl;
	cout << "\t\t                       请输入您的选择（1-4）:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> choose;
	while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0 && strcmp(choose, "4") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "\t\t                    输入错误，请重新输入（1-4）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> choose;
	}
	system("cls");//清屏
	if (strcmp(choose, "1") == 0)
	{
		char Snum[8] = "0";//需要删除的员工编号 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请输入你需要删除的员工编号:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Snum;//输入需要删除的员工编号
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Snum, p->data.staffNumber) == 0)//判断与要删除的数据信息是否相等
			{
				int j = 1;
				if (i == 1)//需删除数据是第一个时
				{
					head = p->next;
					i--;//删除后记录位置减一，便于之后删除位置的正确
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//需删除位置的前一位
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//删除后记录位置减一，便于之后删除位置的正确
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//记录q指针指向位置，便于与i对比找到需进行操作的地方
					}
				}
				k++;//判断是否有所删除信息存在
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "\t\t                            *************     该员工不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t             *************       成功删除编号为" << Snum << "的" << k << "位员工信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "2") == 0)
	{
		char Snam[20];//需要删除的员工名称 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请输入你需要删除的员工名称:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Snam;//输入需要删除的员工名称
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Snam, p->data.staffName) == 0)//判断与要删除的数据信息是否相等
			{
				int j = 1;
				if (i == 1)//需删除数据是第一个时
				{
					head = p->next;
					i--;//删除后记录位置减一，便于之后删除位置的正确
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//需删除位置的前一位
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//删除后记录位置减一，便于之后删除位置的正确
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//记录q指针指向位置，便于与i对比找到需进行操作的地方
					}
				}
				k++;//判断是否有所删除信息存在
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "\t\t                            *************     该员工不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t             *************       成功删除名称为" << Snam << "的" << k << "位员工信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "3") == 0)
	{
		char Sgen[5];//需要删除的员工性别 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请输入你需要删除的员工性别:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Sgen;//输入需要删除的员工性别
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Sgen, p->data.staffgender) == 0)//判断与要删除的数据信息是否相等
			{
				int j = 1;
				if (i == 1)//需删除数据是第一个时
				{
					head = p->next;
					i--;//删除后记录位置减一，便于之后删除位置的正确
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//需删除位置的前一位
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//删除后记录位置减一，便于之后删除位置的正确
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//记录q指针指向位置，便于与i对比找到需进行操作的地方
					}
				}
				k++;//判断是否有所删除信息存在
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "\t\t                            *************     该员工不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t             *************       成功删除性别为" << Sgen << "的" << k << "位员工信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "4") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	if (k > 0)
		StaffSave(head);//保存到文件中

	char choi[10] = "0";
	i = 0; //用于判断在选择是否继续查找时，选择是否出错
	while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
	{
		if (i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "\t\t                                     非法输入！请重新输入！" << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                           *******    是否继续删除员工？  *******" << endl;
		cout << "\t\t                          *******       Y-->继续删除       *******" << endl;
		cout << "\t\t                           *******      N-->返回主菜单    *******" << endl;
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                          请输入您的选择(Y or N):";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> choi;
		system("cls");
		if (strcmp(choi, "N") == 0 || strcmp(choi, "n") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			return 0;
		}
		else if (strcmp(choi, "y") == 0 || strcmp(choi, "Y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			StaffDel(head);
		}
		i++;
	}
	return head;
}


//修改员工的信息
StaffNode* StaffModify(StaffNode* head)
{
	StaffOutput(head);
	StaffNode* p = NULL;
	char Number[4] = "0";
	char Name[20] = "0";
	char H = '0';
	char f[5] = "0";
	int q = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                        *******请选择您要查询的方式：*******" << endl;
	cout << "\t\t                       *******      1-->按编号查询    *******" << endl;
	cout << "\t\t                       *******      2-->按名称查询    *******" << endl;
	cout << "\t\t                        *******     3-->返回主菜单   *******" << endl;
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                      请输入您的选择(1-3):";
	char b[10] = "0";//确认误操作变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> b;
	while (strcmp(b, "1") != 0 && strcmp(b, "2") != 0 && strcmp(b, "3") != 0 )
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(b, "1") == 0)
	{
		cout << "请输入你需要修改员工编号" << endl;
		cin >> Number;
		system("cls");
		if (head == NULL)//如果是空链表
		{
			cout << "无商品信息！" << endl;
			StaffModify(head);
		}
		p = head;
		while (p != NULL && strcmp(Number, p->data.staffNumber) != 0)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t        该员工不存在!" << endl;
			StaffModify(head);
		}
		else
		{
			cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
				<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;

			cout << "\t\t                           ******************************" << endl;
			cout << "\t\t                        *******请选择您要修改的方式：*******" << endl;
			cout << "\t\t                       *******      1-->全局修改      *******" << endl;
			cout << "\t\t                        *******     2-->局部修改     *******" << endl;
			cout << "\t\t                           ******************************" << endl;
			cout << "\t\t                       请输入您的选择(1-2):";
			cin >> H;
			switch (H)
			{
			case '1'://全局修改
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "修改前员工编号：" << p->data.staffNumber << endl;
				cout << "请输入员工编号:";
				cin >> p->data.staffNumber;
				cout << "修改前员工名称：" << p->data.staffName << endl;
				cout << "请输入员工名称:";
				cin >> p->data.staffName;
				cout << "修改前员工性别：" << p->data.staffgender << endl;
				cout << "请输入员工性别:";
				cin >> p->data.staffgender;
				cout << "修改前员工当月销售数量：" << p->data.staffMonthSaleQuantity << endl;
				cout << "请输入员工当月销售数量:";
				cin >> p->data.staffMonthSaleQuantity;
				cout << "修改前当月销售金额：" << p->data.staffMonthSaleAmount << endl;
				cout << "请输入当月销售金额:";
				cin >> p->data.staffMonthSaleAmount;
				cout << "修改前累计销售数量：" << p->data.staffTotalSaleQuantity << endl;
				cout << "请输入累计销售数量:";
				cin >> p->data.staffTotalSaleQuantity;
				cout << "修改前累计销售金额：" << p->data.staffTotalSaleAmount << endl;
				cout << "请输入累计销售金额:";
				cin >> p->data.staffTotalSaleAmount;
				cout << "修改后信息为：" << "编号：" << p->data.staffNumber << endl << "姓名：" << p->data.staffName << endl << "性别：" << p->data.staffgender << endl << "当月销售数量：" << p->data.staffMonthSaleQuantity << endl << "当月销售金额：" << p->data.staffMonthSaleAmount << endl << "累计销售数量：" << p->data.staffTotalSaleQuantity << endl << "累计销售金额" << p->data.staffTotalSaleAmount << endl;
				system("cls");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******是否继续修改：*******" << endl;
				cout << "\t\t                       *******    1-->是      *******" << endl;
				cout << "\t\t                        *******   2-->否     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       请输入您的选择(1-2):";
				cin >> f;
				system("cls");
				if (strcmp(f, "1") == 0)
				{
					StaffModify(head);
				}
				else if(strcmp(f, "2") == 0)
				{
					return head;
				}
				else
				{
					cout << "输入错误！请重新输入!" << endl;
				}
				break;

			case '2'://局部修改
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "1.员工编号" << endl << "2.员工名称" << endl << "3.员工性别" << endl << "4.员工当月销售数量" << endl << "5.员工当月销售金额" << endl << "6.累计销售数量" << endl << "7.累计销售金额" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "修改前员工编号：" << p->data.staffNumber << endl;
					cout << "请输入员工编号:";
					cin >> p->data.staffNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "修改前员工名称：" << p->data.staffName << endl;
					cout << "请输入员工名称:";
					cin >> p->data.staffName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "修改前员工性别：" << p->data.staffgender << endl;
					cout << "请输入员工性别:";
					cin >> p->data.staffgender;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "修改前员工当月销售数量：" << p->data.staffMonthSaleQuantity << endl;
					cout << "请输入员工当月销售数量:";
					cin >> p->data.staffMonthSaleQuantity;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "修改前当月销售金额：" << p->data.staffMonthSaleAmount << endl;
					cout << "请输入当月销售金额:";
					cin >> p->data.staffMonthSaleAmount;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "修改前累计销售数量：" << p->data.staffTotalSaleQuantity << endl;
					cout << "请输入累计销售数量:";
					cin >> p->data.staffTotalSaleQuantity;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "修改前累计销售金额：" << p->data.staffTotalSaleAmount << endl;
					cout << "请输入累计销售金额:";
					cin >> p->data.staffTotalSaleAmount;
					cout << "修改后信息为：" << "编号：" << p->data.staffNumber << endl << "姓名：" << p->data.staffName << endl << "性别：" << p->data.staffgender << endl << "当月销售数量：" << p->data.staffMonthSaleQuantity << endl << "当月销售金额：" << p->data.staffMonthSaleAmount << endl << "累计销售数量：" << p->data.staffTotalSaleQuantity << endl << "累计销售金额" << p->data.staffTotalSaleAmount << endl;
				}
				else
				{
					cout << "输入错误" << endl;
				}
				system("cls");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******是否继续修改：*******" << endl;
				cout << "\t\t                       *******    1-->是      *******" << endl;
				cout << "\t\t                        *******   2-->否     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       请输入您的选择(1-2):";
				cin >> f;
				system("cls");
				if (strcmp(f, "1") == 0)
				{
					StaffModify(head);
				}
				else if (strcmp(f, "2") == 0)
				{
					return head;
				}
				else
				{
					cout << "输入错误！请重新输入!" << endl;
				}
				break;
			}
				
		}
		return head;
	}
	else if (strcmp(b, "2") == 0 )
	{
		cout << "请输入你需要修改员工名称" << endl;
		cin >> Name;
		system("cls");
		if (head == NULL)//如果是空链表
		{
			cout << "无员工信息！" << endl;
			StaffModify(head);
		}
		p = head;
		while (p != NULL && strcmp(Name, p->data.staffName) != 0)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t        该员工不存在!" << endl;
			StaffModify(head);
		}
		else
		{
			cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
				<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;

			cout << "\t\t                           ******************************" << endl;
			cout << "\t\t                        *******请选择您要修改的方式：*******" << endl;
			cout << "\t\t                       *******      1-->全局修改      *******" << endl;
			cout << "\t\t                        *******     2-->局部修改     *******" << endl;
			cout << "\t\t                           ******************************" << endl;
			cout << "\t\t                       请输入您的选择(1-2):";
			char h = '0';
			cin >> h;
			switch (h)
			{
			case '1':
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "修改前员工编号：" << p->data.staffNumber << endl;
				cout << "请输入员工编号:";
				cin >> p->data.staffNumber;
				cout << "修改前员工名称：" << p->data.staffName << endl;
				cout << "请输入员工名称:";
				cin >> p->data.staffName;
				cout << "修改前员工性别：" << p->data.staffgender << endl;
				cout << "请输入员工性别:";
				cin >> p->data.staffgender;
				cout << "修改前员工当月销售数量：" << p->data.staffMonthSaleQuantity << endl;
				cout << "请输入员工当月销售数量:";
				cin >> p->data.staffMonthSaleQuantity;
				cout << "修改前当月销售金额：" << p->data.staffMonthSaleAmount << endl;
				cout << "请输入当月销售金额:";
				cin >> p->data.staffMonthSaleAmount;
				cout << "修改前累计销售数量：" << p->data.staffTotalSaleQuantity << endl;
				cout << "请输入累计销售数量:";
				cin >> p->data.staffTotalSaleQuantity;
				cout << "修改前累计销售金额：" << p->data.staffTotalSaleAmount << endl;
				cout << "请输入累计销售金额:";
				cin >> p->data.staffTotalSaleAmount;
				cout << "修改后信息为：" << "编号：" << p->data.staffNumber << endl << "姓名：" << p->data.staffName << endl << "性别：" << p->data.staffgender << endl << "当月销售数量：" << p->data.staffMonthSaleQuantity << endl << "当月销售金额：" << p->data.staffMonthSaleAmount << endl << "累计销售数量：" << p->data.staffTotalSaleQuantity << endl << "累计销售金额" << p->data.staffTotalSaleAmount << endl;
				system("cls");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******是否继续修改：*******" << endl;
				cout << "\t\t                       *******    1-->是      *******" << endl;
				cout << "\t\t                        *******   2-->否     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       请输入您的选择(1-2):";
				cin >> f;
				system("cls");
				if (strcmp(f, "1") == 0)
				{
					StaffModify(head);
				}
				else if (strcmp(f, "2") == 0)
				{
					return head;
				}
				else
				{
					cout << "输入错误！请重新输入!" << endl;
				}
				break;

			case '2':
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "1.员工编号" << endl << "2.员工名称" << endl << "3.员工性别" << endl << "4.员工当月销售数量" << endl << "5.员工当月销售金额" << endl << "6.累计销售数量" << endl << "7.累计销售金额" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "修改前员工编号：" << p->data.staffNumber << endl;
					cout << "请输入员工编号:";
					cin >> p->data.staffNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "修改前员工名称：" << p->data.staffName << endl;
					cout << "请输入员工名称:";
					cin >> p->data.staffName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "修改前员工性别：" << p->data.staffgender << endl;
					cout << "请输入员工性别:";
					cin >> p->data.staffgender;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "修改前员工当月销售数量：" << p->data.staffMonthSaleQuantity << endl;
					cout << "请输入员工当月销售数量:";
					cin >> p->data.staffMonthSaleQuantity;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "修改前当月销售金额：" << p->data.staffMonthSaleAmount << endl;
					cout << "请输入当月销售金额:";
					cin >> p->data.staffMonthSaleAmount;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "修改前累计销售数量：" << p->data.staffTotalSaleQuantity << endl;
					cout << "请输入累计销售数量:";
					cin >> p->data.staffTotalSaleQuantity;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "修改前累计销售金额：" << p->data.staffTotalSaleAmount << endl;
					cout << "请输入累计销售金额:";
					cin >> p->data.staffTotalSaleAmount;
					cout << "修改后信息为：" << "编号：" << p->data.staffNumber << endl << "姓名：" << p->data.staffName << endl << "性别：" << p->data.staffgender << endl << "当月销售数量：" << p->data.staffMonthSaleQuantity << endl << "当月销售金额：" << p->data.staffMonthSaleAmount << endl << "累计销售数量：" << p->data.staffTotalSaleQuantity << endl << "累计销售金额" << p->data.staffTotalSaleAmount << endl;
				}
				else
				{
					cout << "输入错误" << endl;
				}
				system("cls");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******是否继续修改：*******" << endl;
				cout << "\t\t                       *******    1-->是      *******" << endl;
				cout << "\t\t                        *******   2-->否     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       请输入您的选择(1-2):";
				cin >> f;
				system("cls");
				if (strcmp(f, "1") == 0)
				{
					StaffModify(head);
				}
				else if (strcmp(f, "2") == 0)
				{
					return head;
				}
				else
				{
					cout << "输入错误！请重新输入!" << endl;
				}
				break;
			}	
		}
		return head;
	}
	else if (strcmp(b, "3") == 0 )
	{
		return head;
	}

}


//员工查询
int Staffearch(StaffNode* head)
{
	StaffOutput(head);
	char ch[10] = "0";     //用于判断是否继续查找
	char choice[10] = "0";//选择查询方式
	char cho[10] = "0";//选择查询依据	
	int i = 0;//for循环遍历
	char snum[4] = "0";
	char snam[20] = "0";
	char sgen[5] = "0";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                        *******请选择您要查询的方式：*******" << endl;
	cout << "\t\t                       *******      1-->精确查找      *******" << endl;
	cout << "\t\t                       *******      2-->范围查找      *******" << endl;
	cout << "\t\t                        *******     3-->返回主菜单   *******" << endl;
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                      请输入您的选择(1-3):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> choice;
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		StaffOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                          *******  请选择查询依据:  *******" << endl;
		cout << "\t\t                         *******    1-->按员工编号    *******" << endl;
		cout << "\t\t                        ******      2-->按员工性别       *******" << endl;
		cout << "\t\t                         *******    3-->按员工名称    *******" << endl;
		cout << "\t\t                          *******   4-->返回主菜单   *******" << endl;
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                       请输入您的选择（1-3）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout << "          请输入员工编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> snum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			StaffNode* p = NULL;//p是查找位置
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无员工信息!" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}
			p = head;
			while (p != NULL && strcmp(snum, p->data.staffNumber) != 0)
			{
				p = p->next;
				i++;
			}
			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "\t\t        该员工不存在" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}
			else
			{
				cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
					<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
				cout << setw(3) << p->data.staffNumber << '\t'
					<< setw(3) << p->data.staffName << '\t'
					<< setw(3) << p->data.staffgender << '\t'
					<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
					<< setw(8) << p->data.staffMonthSaleAmount << '\t'
					<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
					<< setw(8) << p->data.staffTotalSaleAmount << '\t'
					<< endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          请输入员工性别:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> sgen;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			StaffNode* p = NULL;//p是查找位置
			int i = 0;//位置序号
			int length = 0;//员工链表长度
			if (head == NULL)//如果是空链表
			{
				cout << "无员工信息!" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}

			p = head;
			while (p != NULL && strstr(sgen, p->data.staffgender) != 0)
			{
				length = length + 1;
				p = p->next;
				i++;
			}
			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "\t\t        该员工不存在" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}
			else
			{
				cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
					<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
				cout << endl;
				int j = 0;
				for (p = head; p != NULL; p = p->next)
				{
					char* s = NULL;
					s = strstr(p->data.staffgender, sgen);
					j = j + 1;
					if (j == 0)
					{
						cout << "没有该员工" << endl;
					}
					else if (s != NULL)
					{

						cout << setw(3) << p->data.staffNumber << '\t'
							<< setw(3) << p->data.staffName << '\t'
							<< setw(3) << p->data.staffgender << '\t'
							<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
							<< setw(8) << p->data.staffMonthSaleAmount << '\t'
							<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
							<< setw(8) << p->data.staffTotalSaleAmount << '\t'
							<< endl;
					}
				}
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          请输入员工名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> snam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			StaffNode* p = NULL;//p是查找位置
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无员工信息!" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}
			p = head;
			while (p != NULL && strcmp(snam, p->data.staffName) != 0)
			{
				p = p->next;
				i++;
			}
			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "\t\t        该员工不存在" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}
			else
			{
				cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
					<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
				cout << setw(3) << p->data.staffNumber << '\t'
					<< setw(3) << p->data.staffName << '\t'
					<< setw(3) << p->data.staffgender << '\t'
					<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
					<< setw(8) << p->data.staffMonthSaleAmount << '\t'
					<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
					<< setw(8) << p->data.staffTotalSaleAmount << '\t'
					<< endl;

			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "\t\t                           返回主菜单!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			system("cls");
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "\t\t                         选择出错！\n" << endl;
		}
	}
	if (strcmp(choice, "2") == 0)
	{
		StaffOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		cout << "\t\t                          ***********************************" << endl;
		cout << "\t\t                        *******      请选择查询方式:    *******" << endl;
		cout << "\t\t                      *******    1-->按员工当月销售数量    *******" << endl;
		cout << "\t\t                      *******    2-->按员工当月销售金额   *******" << endl;
		cout << "\t\t                      *******    3-->按员工累计销售数量   *******" << endl;
		cout << "\t\t                       *******   4-->按员工累计销售金额  *******" << endl;
		cout << "\t\t                        *******  5-->返回主菜单         *******" << endl;
		cout << "\t\t                          ***********************************" << endl;
		cout << "\t\t                      请输入您的选择（1-5）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> cho;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");
		int sq1 = 0;//当月销售数量下限
		int sq2 = 0;//当月销售数量上限
		int tq1 = 0;//当月销售金额下限
		int tq2 = 0;//当月销售金额上限
		float ssq1 = 0;//累计销售数量下限 
		float ssq2 = 0;//累计销售数量上限 
		float ssa1 = 0;//累计销售金额下限 
		float ssa2 = 0;//累计销售金额上限 
		char a[10] = "0";
		if (strcmp(cho, "1") == 0)
		{
			cout << "          请输入最低当月销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> sq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "          请输入最高当月销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> sq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			while (sq1 > sq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "                       非法输入（最低>最高)！请重新输入!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* 是否继续范围查找？******" << endl;
				cout << "\t\t                      *******    Y-->继续查找    *******" << endl;
				cout << "\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "                 输入错误!请重新输入:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return 0;
				}
				cout << "          请输入最低当月销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> sq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "          请输入最高当月销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> sq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			struct StaffNode* p = NULL;//p是查找位置
			int length = 0;//员工的链表长度
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无员工信息！" << endl;
				_getch();
				return -1;//表示此时链表为空
			}

			p = head;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				if (sq1 <= p->data.staffMonthSaleQuantity && sq2 >= p->data.staffMonthSaleQuantity)
				{
					if (i == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						i++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "没有该范围内的员工" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          请输入最低当月销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> tq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "          请输入最高当月销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> tq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			while (tq1 > tq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "                       非法输入（最低>最高)！请重新输入!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* 是否继续范围查找？******" << endl;
				cout << "\t\t                      *******    Y-->继续查找    *******" << endl;
				cout << "\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "                 输入错误!请重新输入:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return 0;
				}
				cout << "          请输入最低当月销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> tq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "          请输入最高当月销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> tq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			struct StaffNode* p = NULL;//p是查找位置
			int length = 0;//员工的链表长度
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无员工信息！" << endl;
				_getch();
				return -1;//表示此时链表为空
			}

			p = head;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				if (tq1 <= p->data.staffMonthSaleAmount && tq2 >= p->data.staffMonthSaleAmount)
				{
					if (i == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						i++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "没有在该范围内的员工" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          请输入最低累计销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> ssq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "          请输入最高累计销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> ssq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			while (ssq1 > ssq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "                       非法输入（最低>最高)！请重新输入!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* 是否继续范围查找？******" << endl;
				cout << "\t\t                      *******    Y-->继续查找    *******" << endl;
				cout << "\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "                 输入错误!请重新输入:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return 0;
				}
				cout << "          请输入最低累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> ssq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "          请输入最高累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> ssq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			struct StaffNode* p = NULL;//p是查找位置
			int length = 0;//员工的链表长度
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无员工信息！" << endl;
				_getch();
				return -1;//表示此时链表为空
			}

			p = head;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				if (ssq1 <= p->data.staffTotalSaleQuantity && ssq2 >= p->data.staffTotalSaleQuantity)
				{
					if (i == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						i++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "没有在该范围内的员工" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          请输入最低累计销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> ssa1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "          请输入最高累计销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> ssa2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			while (ssa1 > ssa2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "                       非法输入（最低>最高)！请重新输入!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* 是否继续范围查找？******" << endl;
				cout << "\t\t                      *******    Y-->继续查找    *******" << endl;
				cout << "\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "                 输入错误!请重新输入:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return 0;
				}
				cout << "          请输入最低累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> ssa1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "          请输入最高累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> ssa2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			struct StaffNode* p = NULL;//p是查找位置
			int length = 0;//员工的链表长度
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无员工信息！" << endl;
				_getch();
				return -1;//表示此时链表为空
			}

			p = head;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				if (ssa1 <= p->data.staffTotalSaleAmount && ssa2 >= p->data.staffTotalSaleAmount)
				{
					if (i == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						i++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "没有在该范围内的员工" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "返回主菜单!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			system("cls");
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0 && strcmp(cho, "4") != 0 && strcmp(cho, "5") != 0 && strcmp(cho, "6") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "\t\t                                          选择出错!\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		}
	}
	else if (strcmp(choice, "3") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "返回主菜单!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		system("cls");
		return 0;
	}
	else if (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "3") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "\t\t                             选择出错!\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******        是否继续查询        *******" << endl;
	cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
	cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       请输入您的选择:";
	char b[10] = "0";//确认误操作变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> b;
	while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		Staffearch(head);
	}
	if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		return 0;
	}
}



//根据当月销售数量/当月销售金额/累计销售数量/累计销售金额降序排序
void StaffSelectionSort(StaffNode* head)
{
	system("cls");//清屏
	StaffNode* p = NULL;
	StaffNode* q = NULL;
	StaffNode* r = NULL;
	StaffNode* k = NULL;
	Staff temp1;
	Staff temp2;
	int i = 0;
	char cho[10] = "0";//排序依据选择
	char choi[10] = "0";//判断是否继续查看员工排序
	cout << "\t\t            *****************************************************************" << endl;
	cout << "\t\t           *******************            请选择排序依据:      ***************" << endl;
	cout << "\t\t          *****************         1-->按员工当月销售数量      ***************" << endl;
	cout << "\t\t         *****************          2-->按员工当月销售金额       ***************" << endl;
	cout << "\t\t         ******************         3-->按员工累计销售数量       ***************" << endl;
	cout << "\t\t           *****************        4-->按员工累计销售金额     ***************" << endl;
	cout << "\t\t            *****************       5-->返回主菜单            ***************" << endl;
	cout << "\t\t             ***************************************************************" << endl;
	cout << "\t\t         请输入您的选择（1-5）:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> cho;
	while (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0 && strcmp(cho, "4") != 0 && strcmp(cho, "5") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "\t\t                    输入错误，请重新输入（1-5）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> cho;
	}
	system("cls");//清屏
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(cho, "1") == 0) //按当月销售数量排序，采用直接插入排序
	{

		cout << "\t\t编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		//q = (StaffNode*)malloc(sizeof(StaffNode));//为结点分配内存单元
		q = new StaffNode;
		q->next = head;//q的下一节点指向头结点
		head = q;//将头结点设为空
		p = head->next->next;//用指针p保存下未排序元素的信息
		head->next->next = NULL;//使用原链表构造有序区，当前仅有一个元素
		while (p != NULL)//遍历无序区
		{
			k = p->next;//保存位置
			r = head;//用指针指向有序区
			while (r->next != NULL && r->next->data.staffMonthSaleQuantity > p->data.staffMonthSaleQuantity)//判断指针指向的下一个元素与无序区取出元素的大小
			{
				r = r->next;
			}
			p->next = r->next;//插入操作
			r->next = p;
			p = k;//将p值回复，指向无序区下一个节点
		}
		head = head->next;//去掉一开始加入的空数据
		//free(q);//释放当前结点的内存空间
		delete q;
		q = NULL;
		p = head;
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout <<"\t\t" << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;
			p = p->next;//指向下一个结点
		}
	}
	else if (strcmp(cho, "2") == 0)//按当月销售金额排序，采用冒泡排序（下沉法）
	{

		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		p = head;
		while (p != q)
		{
			while (p->next != q)
			{
				if (p->data.staffMonthSaleAmount < p->next->data.staffMonthSaleAmount) //比较相邻两个值，符合条件则交换
				{
					temp1 = p->data;
					p->data = p->next->data;
					p->next->data = temp1;
				}
				p = p->next;
			}
			q = p;//每次等于内while循环后最后一个值，达到每次少比较一个的目的
			p = head;
		}
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;
			p = p->next;//指向下一个结点
		}
	}
	else if (strcmp(cho, "3") == 0)//按累计销售数量排序，采用直接选择排序
	{

		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		q = p = head;
		while (q)//从第一个遍历
		{
			r = p;//保留无序区最大数据位置
			temp1 = p->data;//保留最大数据信息
			p = p->next;//指向无序区第二个节点
			while (p)
			{
				if (p->data.staffTotalSaleQuantity > temp1.staffTotalSaleQuantity)
				{
					r = p;//更新无序区最大数据位置
					temp1 = p->data;
				}
				p = p->next;
			}
			p = r;//指向最大值位置
			temp2 = p->data;//将最大值位置与当前位置交换
			p->data = q->data;
			q->data = temp2;
			q = q->next;//指向下一个节点位置
			p = q;//将p值回复，指向无序区第一个节点
		}
		p = head;
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;
			p = p->next;//指向下一个结点
		}
	}
	else if (strcmp(cho, "4") == 0) //按累计销售金额排序，采用直接选择排序
	{
		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		q = p = head;
		while (q)
		{
			r = p;
			temp1 = p->data;
			p = p->next;//指向无序区第一个节点
			while (p)
			{
				if (p->data.staffTotalSaleAmount > temp1.staffTotalSaleAmount)
				{
					r = p;
					temp1 = p->data;
				}
				p = p->next;
			}
			p = r;
			temp2 = p->data;
			p->data = q->data;
			q->data = temp2;
			q = q->next;
			p = q;//将p值回复，指向无序区第一个节点
		}
		p = head;
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;
			p = p->next;//指向下一个结点
		}
	}
	else if (strcmp(cho, "5") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		return;
	}
	i = 0; //用于判断在选择是否继续查找时，选择是否出错
	while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
	{
		if (i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "\t\t                                     非法输入！请重新输入！" << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                           *******  是否继续查看员工排序？*******" << endl;
		cout << "\t\t                          *******       Y-->继续查看       *******" << endl;
		cout << "\t\t                           *******      N-->返回主菜单    *******" << endl;
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                          请输入您的选择(Y or N):";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> choi;
		if (strcmp(choi, "N") == 0 || strcmp(choi, "n") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			return;
		}
		else if (strcmp(choi, "y") == 0 || strcmp(choi, "Y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			StaffSelectionSort(head);
		}
		i++;
	}
}
