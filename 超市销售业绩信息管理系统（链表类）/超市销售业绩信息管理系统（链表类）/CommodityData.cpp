//#define _CRT_SECURE_NO_WARNNINGS //避免警告
#include "Commodity.h"
#include<iostream>
#include<windows.h>//控制台编程主要头文件
#include<iomanip>//用到setw()函数
#include<conio.h>//_getch()
#include<string.h>
using namespace std;

//保存文件函数   保存输入的数据到文件中
bool CommoditySave(CommodityNode* head)
{
	CommodityNode* p = NULL;//用指针p依次指向链表各个结点
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
		fopen_s(&fp, "./CommodityData.txt", "w+");
		if (fp == NULL)
		//if (!fp)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "创建文件失败!" << endl;
			return 0;
		}
		i = 0;
		//将每个商品信息写入文件
		p = head;
		while (p != NULL)
		//while (i < size)
		{
			fprintf(fp, "%s\t", p->data.commodityNumber);
			fprintf(fp, "%s\t", p->data.commodityName);
			fprintf(fp, "%s\t", p->data.commodityClass);
			fprintf(fp, "%s\t", p->data.commodityPlaceOfOrigin);
			fprintf(fp, "%s\t", p->data.commodityManufacturer);
			fprintf(fp, "%f\t", p->data.commodityPurchasePrice);
			fprintf(fp, "%f\t", p->data.commodityPrice);
			fprintf(fp, "%d\t", p->data.commodityPurchaseQuantity);
			fprintf(fp, "%d\t", p->data.commoditySoldQuantity);
			fprintf(fp, "%d\t", p->data.commodityInventoryQuantity);
			fprintf(fp, "%d\t\n", p->data.commodityInventoryAmount);
			p = p->next; //指针指向下一个节点
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "共输入" << i << "个商品的信息到文件中！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		fclose(fp);
		return 1;
	}
}


//读取数据函数   读取文件中的数据到内存中
CommodityNode* CommodityRead()
{
	CommodityNode* head = NULL;  //头指针
	CommodityNode* p1 = NULL;  //用指针p指向要插入的新结点
	CommodityNode* p2 = NULL;  //用指针p指向要插入的新结点
	FILE* fp;               //定义文件类型指针
	int i = 0;//循环控制
	fopen_s(&fp, "CommodityData.txt", "r");
	if (fp == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "读取文件失败!\n" << endl;
		return 0;
	}
	while (!feof(fp)) //表示没有指向文件末尾，没指向末尾为0
	{
		p1 = new CommodityNode;
		fscanf_s(fp,"%s\t",&p1->data.commodityNumber, 8);
		fscanf_s(fp, "%s\t", &p1->data.commodityName, 20);
		fscanf_s(fp, "%s\t", &p1->data.commodityClass, 20);
		fscanf_s(fp, "%s\t", &p1->data.commodityPlaceOfOrigin, 10);
		fscanf_s(fp, "%s\t", &p1->data.commodityManufacturer, 20);
		fscanf_s(fp, "%f\t", &p1->data.commodityPurchasePrice, 20);
		fscanf_s(fp, "%f\t", &p1->data.commodityPrice, 20);
		fscanf_s(fp, "%d\t", &p1->data.commodityPurchaseQuantity, 20);
		fscanf_s(fp, "%d\t", &p1->data.commoditySoldQuantity, 20);
		fscanf_s(fp, "%d\t", &p1->data.commodityInventoryQuantity, 20);
		fscanf_s(fp, "%d\t\n", &p1->data.commodityInventoryAmount, 20);
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "共读取" << i << "个商品的信息到内存中！" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	fclose(fp);
	return head;
}

//商品数据初始化
CommodityNode* CommodityInit(CommodityNode* head)
{
	head = NULL;
	CommodityNode* p1 = NULL;
	CommodityNode* p2 = NULL;
	int i = 0;

	cout << "商品系统初始化！" << endl;
	p1 = new CommodityNode;
	strcpy(p1->data.commodityNumber , "001");
	strcpy(p1->data.commodityName, "白菜");
	strcpy(p1->data.commodityClass, "蔬菜类");
	strcpy(p1->data.commodityPlaceOfOrigin, "重庆");
	strcpy(p1->data.commodityManufacturer, "菜市场");
	p1->data.commodityPurchasePrice = 20;
	p1->data.commodityInventoryAmount = 3000;
	p1->data.commodityInventoryQuantity = 500;
	p1->data.commodityPurchaseQuantity = 600;
	p1->data.commoditySoldQuantity = 100;
	p1->data.commodityPrice = 30;
	head = p1;
	p2 = p1;

	p1 = new CommodityNode;
	strcpy(p1->data.commodityNumber, "002");
	strcpy(p1->data.commodityName, "猪肉");
	strcpy(p1->data.commodityClass, "肉类");
	strcpy(p1->data.commodityPlaceOfOrigin, "重庆");
	strcpy(p1->data.commodityManufacturer, "菜市场");
	p1->data.commodityPurchasePrice = 40;
	p1->data.commodityInventoryAmount = 5000;
	p1->data.commodityInventoryQuantity = 300;
	p1->data.commodityPurchaseQuantity = 350;
	p1->data.commoditySoldQuantity = 50;
	p1->data.commodityPrice = 50;
	p2->next = p1;
	p2 = p1;

	p1 = new CommodityNode;
	strcpy(p1->data.commodityNumber, "003");
	strcpy(p1->data.commodityName, "辣条");
	strcpy(p1->data.commodityClass, "零食类");
	strcpy(p1->data.commodityPlaceOfOrigin, "重庆");
	strcpy(p1->data.commodityManufacturer, "卫龙");
	p1->data.commodityPurchasePrice = 5;
	p1->data.commodityInventoryAmount = 2000;
	p1->data.commodityInventoryQuantity = 300;
	p1->data.commodityPurchaseQuantity = 3000;
	p1->data.commoditySoldQuantity = 2700;
	p1->data.commodityPrice = 10;
	p2->next = p1;
	p2 = p1;

	p1 = new CommodityNode;
	strcpy(p1->data.commodityNumber, "004");
	strcpy(p1->data.commodityName, "饼干");
	strcpy(p1->data.commodityClass, "零食");
	strcpy(p1->data.commodityPlaceOfOrigin, "重庆");
	strcpy(p1->data.commodityManufacturer, "奥利奥");
	p1->data.commodityPurchasePrice = 10;
	p1->data.commodityInventoryAmount = 1500;
	p1->data.commodityInventoryQuantity = 200;
	p1->data.commodityPurchaseQuantity = 1000;
	p1->data.commoditySoldQuantity = 800;
	p1->data.commodityPrice = 15;
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;

	CommoditySave(head);
	cout << "商品系统初始化成功！" << endl;
	cout << "请按任意键继续" << endl;
	_getch();
	return head;
}

//创建商品信息
CommodityNode* CommodityCreate(CommodityNode* head)
{
	head = NULL;
	CommodityNode* p1 = NULL;
	CommodityNode* p2 = NULL;
	int i = 0;//循环变量
	int m = 0;//商品的数量
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

		cout << "请输入需要输入的商品数量:";
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

			p1 = new CommodityNode;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "请输入第" << i + 1 << "个商品的编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的类别:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityClass;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的产地:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPlaceOfOrigin;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的生产厂家:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityManufacturer;
			//加一个验证是否格式输入正确的环节
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的进价:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPurchasePrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的售价:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的进货数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPurchaseQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commoditySoldQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的库存数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityInventoryQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的库存金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityInventoryAmount;
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
		cout << "共输入" << m << "个商品的信息！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		CommoditySave(head); //保存数据到文件中
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	return head;
}


//增加商品的信息
CommodityNode* CommodityAdd(CommodityNode *head)
{
	CommodityNode* p1 = NULL;
	CommodityNode* p2 = NULL;
	int i = 0;//循环变量
	int m = 0;//商品的数量

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
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

		cout << "请输入需要输入的商品数量:";
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

			p1 = new CommodityNode;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "请输入第" << i + 1 << "个商品的编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的类别:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityClass;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的产地:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPlaceOfOrigin;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的生产厂家:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityManufacturer;
			//加一个验证是否格式输入正确的环节
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的进价:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPurchasePrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的售价:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的进货数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityPurchaseQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commoditySoldQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的库存数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityInventoryQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "商品的库存金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> p1->data.commodityInventoryAmount;
			cout << endl;
			p2->next = p1;
			p2 = p1;

		}
		p2->next = NULL;//结束标志
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "共输入" << m << "个商品的信息！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		CommoditySave(head); //保存数据到文件中
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	return head;

}


//输出商品的信息
void CommodityOutput(CommodityNode* head)
{
	CommodityNode* p = head;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t'
		<< "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
		<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t'
		<< "库存数量" << '\t' << "库存金额" << endl;
	cout << endl;
	if (p == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "很抱歉，文件中没有商品信息，请先添加商品信息！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请按任意键继续" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		_getch();
		return ;
	}
	while (p != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
		cout << setw(3) << p->data.commodityNumber << '\t'
			<< setw(3) << p->data.commodityName << '\t'
			<< setw(3) << p->data.commodityClass << '\t'
			<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
			<< setw(3) << p->data.commodityManufacturer << '\t'
			<< setw(10) << p->data.commodityPurchasePrice << '\t'
			<< setw(3) << p->data.commodityPrice << '\t'
			<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
			<< setw(8) << p->data.commoditySoldQuantity << '\t'
			<< setw(8) << p->data.commodityInventoryQuantity << '\t'
			<< setw(8) << p->data.commodityInventoryAmount << '\t'
			<< endl;
		p = p->next;//指向下一个结点
	}

	cout << endl;
}


//商品删除模块
CommodityNode* CommodityDel(CommodityNode* head)
{
	CommodityOutput(head);
	int i = 0;//用于遍历找到所查询信息位置
	int k = 0;//用于判断是否有此商品
	CommodityNode* q;//内循环结点
	CommodityNode* p = head;//指向结点的指针
	if (p == NULL)
		return 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	char choose[10] = "0";//定义一个选择字符
	cout << "\t\t                           *****************************" << endl;
	cout << "\t\t                          *******   请选择删除依据:  *******" << endl;
	cout << "\t\t                        *******     1-->按商品编号    *******" << endl;
	cout << "\t\t                       *******      2-->按商品名称     *******" << endl;
	cout << "\t\t                      *******       3-->按商品类别      *******" << endl;
	cout << "\t\t                       *******      4-->按产地         *******" << endl;
	cout << "\t\t                        *******     5-->按生产厂家    *******" << endl;
	cout << "\t\t                         *******    6-->返回主菜单   *******" << endl;
	cout << "\t\t                           *****************************" << endl;
	cout << "\t\t                      请输入您的选择（1-6）:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> choose;
	while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0 && strcmp(choose, "4") != 0 && strcmp(choose, "5") != 0 && strcmp(choose, "6") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "\t\t                   输入错误，请重新输入（1-6）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> choose;
	}
	system("cls");//清屏 
	if (strcmp(choose, "1") == 0)
	{
		char Cnum[8];//需要删除的商品编号 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "\t\t  请输入你需要删除的商品编号:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Cnum;//输入需要删除的商品编号
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Cnum, p->data.commodityNumber) == 0)//判断与要删除的数据信息是否相等
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
			cout << "\t\t                       *************     该商品不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t           *************       成功删除编号为" << Cnum << "的" << k << "个商品信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "2") == 0)
	{
		char Cname[20];//需要删除的商品名称 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "\t\t  请输入你需要删除的商品名称:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Cname;//输入需要删除的商品名称
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Cname, p->data.commodityName) == 0)//判断与要删除的数据信息是否相等
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
			cout << "\t\t                       *************     该商品不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t           *************       成功删除名称为" << Cname << "的" << k << "个商品信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "3") == 0)
	{
		char Ccla[20];//需要删除的商品类别 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "\t\t  请输入你需要删除的商品类别:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Ccla;//输入需要删除的商品类别
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Ccla, p->data.commodityClass) == 0)//判断与要删除的数据信息是否相等
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
			cout << "\t\t                       *************     该商品不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t           *************       成功删除类别为" << Ccla << "的" << k << "个商品信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "4") == 0)
	{
		char Cpla[10];//需要删除的商品产地 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "\t\t  请输入你需要删除的商品产地:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Cpla;//输入需要删除的商品产地
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Cpla, p->data.commodityPlaceOfOrigin) == 0)//判断与要删除的数据信息是否相等
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
			cout << "\t\t                       *************     该商品不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t           *************       成功删除产地为" << Cpla << "的" << k << "个商品信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "5") == 0)
	{
		char Cman[20];//需要删除的商品生产厂家 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "\t\t  请输入你需要删除的商品生产厂家:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> Cman;//输入需要删除的商品生产厂家
		while (p != NULL)
		{
			i++;//记录位置，用于删除与数据信息相等的数据
			if (strcmp(Cman, p->data.commodityManufacturer) == 0)//判断与要删除的数据信息是否相等
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
			cout << "\t\t                       *************     该商品不存在！   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t          *************       成功删除生产厂家为" << Cman << "的" << k << "个商品信息！      *************" << endl;
		}
	}
	else if (strcmp(choose, "6") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	if (k > 0)
		CommoditySave(head); //保存数据到文件中

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
		cout << "\t\t                           *******    是否继续删除商品？  *******" << endl;
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
			break;
		}
		else if (strcmp(choi, "y") == 0 || strcmp(choi, "Y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			CommodityDel(head);
		}
		i++;
	}
	return head;
}


/*void allmodify(CommodityNode* head)
{
	CommodityNode* p = NULL;
	cout << "修改前商品编号：" << p->data.commodityNumber << endl;
	cout << "请输入商品编号:";
	cin >> p->data.commodityNumber;
	cout << "修改前商品名称：" << p->data.commodityName << endl;
	cout << "请输入商品名称:";
	cin >> p->data.commodityName;
	cout << "修改前商品类别：" << p->data.commodityClass << endl;
	cout << "请输入商品类别:";
	cin >> p->data.commodityClass;
	cout << "修改前产地：" << p->data.commodityPlaceOfOrigin << endl;
	cout << "请输入产地:";
	cin >> p->data.commodityPlaceOfOrigin;
	cout << "修改前生产厂家：" << p->data.commodityManufacturer << endl;
	cout << "请输入生产厂家:";
	cin >> p->data.commodityManufacturer;
	cout << "修改前商品进价：" << p->data.commodityPurchasePrice << endl;
	cout << "请输入商品进价:";
	cin >> p->data.commodityPurchasePrice;
	cout << "修改前商品售价：" << p->data.commodityPrice << endl;
	cout << "请输入商品售价:";
	cin >> p->data.commodityPrice;
	cout << "修改前商品进货数量：" << p->data.commodityPurchaseQuantity << endl;
	cout << "请输入商品进货数量:";
	cin >> p->data.commodityPurchaseQuantity;
	cout << "修改前商品销售数量：" << p->data.commoditySoldQuantity << endl;
	cout << "请输入商品销售数量:";
	cin >> p->data.commoditySoldQuantity;
	cout << "修改前商品库存数量：" << p->data.commodityInventoryQuantity << endl;
	cout << "请输入商品库存数量:";
	cin >> p->data.commodityInventoryQuantity;
	cout << "修改前商品库存金额：" << p->data.commodityInventoryAmount << endl;
	cout << "请输入商品库存金额:";
	cin >> p->data.commodityInventoryAmount;
}*/


//修改商品的信息
CommodityNode* CommodityModify(CommodityNode* head)
{//1
	CommodityOutput(head);
	CommodityNode* p = NULL;
	char Name[20] = "0";
	char Number[8] = "0";
	char H = '0';
	char f[5] = "0";
	int i = 0;//遍历查找要修改的商品
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
	while (strcmp(b, "1") != 0 && strcmp(b, "2") != 0 && strcmp(b, "3") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(b, "1") == 0)
	{
		cout << "请输入你需要修改商品编号" << endl;
		cin >> Number;
		system("cls");
		if (head == NULL)//如果是空链表
		{
			cout << "无商品信息！" << endl;
			CommodityModify(head);
		}
		p = head;
		while (p != NULL && strcmp(Number, p->data.commodityNumber) != 0)
		{
			p = p->next;
			i++;
		}
		if (p == NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t        该商品不存在!" << endl;
			CommodityModify(head);
		}
		else
		{
			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout << setw(3) << p->data.commodityNumber << '\t'
				<< setw(3) << p->data.commodityName << '\t'
				<< setw(3) << p->data.commodityClass << '\t'
				<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
				<< setw(3) << p->data.commodityManufacturer << '\t'
				<< setw(10) << p->data.commodityPurchasePrice << '\t'
				<< setw(3) << p->data.commodityPrice << '\t'
				<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
				<< setw(8) << p->data.commoditySoldQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryAmount << '\t'
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
			case '1':
				//编号修改全局修改括号
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "修改前商品编号：" << p->data.commodityNumber << endl;
				cout << "请输入商品编号:";
				cin >> p->data.commodityNumber;
				cout << "修改前商品名称：" << p->data.commodityName << endl;
				cout << "请输入商品名称:";
				cin >> p->data.commodityName;
				cout << "修改前商品类别：" << p->data.commodityClass << endl;
				cout << "请输入商品类别:";
				cin >> p->data.commodityClass;
				cout << "修改前产地：" << p->data.commodityPlaceOfOrigin << endl;
				cout << "请输入产地:";
				cin >> p->data.commodityPlaceOfOrigin;
				cout << "修改前生产厂家：" << p->data.commodityManufacturer << endl;
				cout << "请输入生产厂家:";
				cin >> p->data.commodityManufacturer;
				cout << "修改前商品进价：" << p->data.commodityPurchasePrice << endl;
				cout << "请输入商品进价:";
				cin >> p->data.commodityPurchasePrice;
				cout << "修改前商品售价：" << p->data.commodityPrice << endl;
				cout << "请输入商品售价:";
				cin >> p->data.commodityPrice;
				cout << "修改前商品进货数量：" << p->data.commodityPurchaseQuantity << endl;
				cout << "请输入商品进货数量:";
				cin >> p->data.commodityPurchaseQuantity;
				cout << "修改前商品销售数量：" << p->data.commoditySoldQuantity << endl;
				cout << "请输入商品销售数量:";
				cin >> p->data.commoditySoldQuantity;
				cout << "修改前商品库存数量：" << p->data.commodityInventoryQuantity << endl;
				cout << "请输入商品库存数量:";
				cin >> p->data.commodityInventoryQuantity;
				cout << "修改前商品库存金额：" << p->data.commodityInventoryAmount << endl;
				cout << "请输入商品库存金额:";
				cin >> p->data.commodityInventoryAmount;
				cout << "修改后信息为：" << "商品编号：" << p->data.commodityNumber << "商品名称：" << p->data.commodityName << endl << "商品类别：" << p->data.commodityClass << endl << "产地：" << p->data.commodityPlaceOfOrigin << endl << "厂家：" << p->data.commodityManufacturer << endl << "商品进价：" << p->data.commodityPurchasePrice << endl << "商品售价：" << p->data.commodityPrice << endl << "商品进货数量：" << p->data.commodityPurchaseQuantity << endl << "商品销售数量：" << p->data.commoditySoldQuantity << endl << "商品库存数量：" << p->data.commodityInventoryQuantity << endl << "商品库存金额：" << p->data.commodityInventoryAmount << endl;
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
					CommodityModify(head);
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
				cout << "1.商品编号" << endl << "2.商品名称" << endl << "3.商品类别" << endl << "4.产地" << endl << "5.生产厂家" << endl << "6.商品进价" << endl << "7.商品售价" << endl << "8.商品进货数量" << endl << "9.商品销售数量" << endl << "10.商品库存数量" << endl << "11.商品库存金额" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "修改前商品编号：" << p->data.commodityNumber << endl;
					cout << "请输入商品编号:";
					cin >> p->data.commodityNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "修改前商品名称：" << p->data.commodityName << endl;
					cout << "请输入商品名称:";
					cin >> p->data.commodityName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "修改前商品类别：" << p->data.commodityClass << endl;
					cout << "请输入商品类别:";
					cin >> p->data.commodityClass;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "修改前产地：" << p->data.commodityPlaceOfOrigin << endl;
					cout << "请输入产地:";
					cin >> p->data.commodityPlaceOfOrigin;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "修改前生产厂家：" << p->data.commodityManufacturer << endl;
					cout << "请输入生产厂家:";
					cin >> p->data.commodityManufacturer;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "修改前商品进价：" << p->data.commodityPurchasePrice << endl;
					cout << "请输入商品进价:";
					cin >> p->data.commodityPurchasePrice;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "修改前商品售价：" << p->data.commodityPrice << endl;
					cout << "请输入商品售价:";
					cin >> p->data.commodityPrice;
				}
				else if (strcmp(g, "8") == 0)
				{
					cout << "修改前商品进货数量：" << p->data.commodityPurchaseQuantity << endl;
					cout << "请输入商品进货数量:";
					cin >> p->data.commodityPurchaseQuantity;
				}
				else if (strcmp(g, "9") == 0)
				{
					cout << "修改前商品销售数量：" << p->data.commoditySoldQuantity << endl;
					cout << "请输入商品销售数量:";
					cin >> p->data.commoditySoldQuantity;
				}
				else if (strcmp(g, "10") == 0)
				{
					cout << "修改前商品库存数量：" << p->data.commodityInventoryQuantity << endl;
					cout << "请输入商品库存数量:";
					cin >> p->data.commodityInventoryQuantity;
				}
				else if (strcmp(g, "11") == 0)
				{
					cout << "修改前商品库存金额：" << p->data.commodityInventoryAmount << endl;
					cout << "请输入商品库存金额:";
					cin >> p->data.commodityInventoryAmount;
				}
				else
				{
					cout << "输入错误" << endl;
					break;
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
					CommodityModify(head);
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

	else if (strcmp(b, "2") == 0)
	{

		//按名称修改括号
		cout << "请输入你需要修改商品名称" << endl;
		cin >> Name;
		system("cls");
		if (head == NULL)//如果是空链表
		{
			cout << "无商品信息！" << endl;
			CommodityModify(head);
		}
		p = head;
		while (p != NULL && strcmp(Name, p->data.commodityName) != 0)
		{
			p = p->next;
			i++;
		}
		if (p == NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "\t\t        该商品不存在!" << endl;
			CommodityModify(head);
		}
		else
		{
			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout << setw(3) << p->data.commodityNumber << '\t'
				<< setw(3) << p->data.commodityName << '\t'
				<< setw(3) << p->data.commodityClass << '\t'
				<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
				<< setw(3) << p->data.commodityManufacturer << '\t'
				<< setw(10) << p->data.commodityPurchasePrice << '\t'
				<< setw(3) << p->data.commodityPrice << '\t'
				<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
				<< setw(8) << p->data.commoditySoldQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryAmount << '\t'
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
				cout << "修改前商品编号：" << p->data.commodityNumber << endl;
				cout << "请输入商品编号:";
				cin >> p->data.commodityNumber;
				cout << "修改前商品名称：" << p->data.commodityName << endl;
				cout << "请输入商品名称:";
				cin >> p->data.commodityName;
				cout << "修改前商品类别：" << p->data.commodityClass << endl;
				cout << "请输入商品类别:";
				cin >> p->data.commodityClass;
				cout << "修改前产地：" << p->data.commodityPlaceOfOrigin << endl;
				cout << "请输入产地:";
				cin >> p->data.commodityPlaceOfOrigin;
				cout << "修改前生产厂家：" << p->data.commodityManufacturer << endl;
				cout << "请输入生产厂家:";
				cin >> p->data.commodityManufacturer;
				cout << "修改前商品进价：" << p->data.commodityPurchasePrice << endl;
				cout << "请输入商品进价:";
				cin >> p->data.commodityPurchasePrice;
				cout << "修改前商品售价：" << p->data.commodityPrice << endl;
				cout << "请输入商品售价:";
				cin >> p->data.commodityPrice;
				cout << "修改前商品进货数量：" << p->data.commodityPurchaseQuantity << endl;
				cout << "请输入商品进货数量:";
				cin >> p->data.commodityPurchaseQuantity;
				cout << "修改前商品销售数量：" << p->data.commoditySoldQuantity << endl;
				cout << "请输入商品销售数量:";
				cin >> p->data.commoditySoldQuantity;
				cout << "修改前商品库存数量：" << p->data.commodityInventoryQuantity << endl;
				cout << "请输入商品库存数量:";
				cin >> p->data.commodityInventoryQuantity;
				cout << "修改前商品库存金额：" << p->data.commodityInventoryAmount << endl;
				cout << "请输入商品库存金额:";
				cin >> p->data.commodityInventoryAmount;
				cout << "修改后信息为：" << "商品编号：" << p->data.commodityNumber << "商品名称：" << p->data.commodityName << endl << "商品类别：" << p->data.commodityClass << endl << "产地：" << p->data.commodityPlaceOfOrigin << endl << "厂家：" << p->data.commodityManufacturer << endl << "商品进价：" << p->data.commodityPurchasePrice << endl << "商品售价：" << p->data.commodityPrice << endl << "商品进货数量：" << p->data.commodityPurchaseQuantity << endl << "商品销售数量：" << p->data.commoditySoldQuantity << endl << "商品库存数量：" << p->data.commodityInventoryQuantity << endl << "商品库存金额：" << p->data.commodityInventoryAmount << endl;
				system("pause");
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
					CommodityModify(head);
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
				cout << "1.商品编号" << endl << "2.商品名称" << endl << "3.商品类别" << endl << "4.产地" << endl << "5.生产厂家" << endl << "6.商品进价" << endl << "7.商品售价" << endl << "8.商品进货数量" << endl << "9.商品销售数量" << endl << "10.商品库存数量" << endl << "11.商品库存金额" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "修改前商品编号：" << p->data.commodityNumber << endl;
					cout << "请输入商品编号:";
					cin >> p->data.commodityNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "修改前商品名称：" << p->data.commodityName << endl;
					cout << "请输入商品名称:";
					cin >> p->data.commodityName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "修改前商品类别：" << p->data.commodityClass << endl;
					cout << "请输入商品类别:";
					cin >> p->data.commodityClass;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "修改前产地：" << p->data.commodityPlaceOfOrigin << endl;
					cout << "请输入产地:";
					cin >> p->data.commodityPlaceOfOrigin;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "修改前生产厂家：" << p->data.commodityManufacturer << endl;
					cout << "请输入生产厂家:";
					cin >> p->data.commodityManufacturer;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "修改前商品进价：" << p->data.commodityPurchasePrice << endl;
					cout << "请输入商品进价:";
					cin >> p->data.commodityPurchasePrice;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "修改前商品售价：" << p->data.commodityPrice << endl;
					cout << "请输入商品售价:";
					cin >> p->data.commodityPrice;
				}
				else if (strcmp(g, "8") == 0)
				{
					cout << "修改前商品进货数量：" << p->data.commodityPurchaseQuantity << endl;
					cout << "请输入商品进货数量:";
					cin >> p->data.commodityPurchaseQuantity;
				}
				else if (strcmp(g, "9") == 0)
				{
					cout << "修改前商品销售数量：" << p->data.commoditySoldQuantity << endl;
					cout << "请输入商品销售数量:";
					cin >> p->data.commoditySoldQuantity;
				}
				else if (strcmp(g, "10") == 0)
				{
					cout << "修改前商品库存数量：" << p->data.commodityInventoryQuantity << endl;
					cout << "请输入商品库存数量:";
					cin >> p->data.commodityInventoryQuantity;
				}
				else if (strcmp(g, "11") == 0)
				{
					cout << "修改前商品库存金额：" << p->data.commodityInventoryAmount << endl;
					cout << "请输入商品库存金额:";
					cin >> p->data.commodityInventoryAmount;
				}
				else
				{
					cout << "输入错误" << endl;
				}
				system("pause");
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
					CommodityModify(head);
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
		
	else if (strcmp(b, "3") == 0)
	{
		return head;
	}
}
  


//商品查询
int CommoditySearch(CommodityNode* head)
{
	CommodityOutput(head);
	char choice[10] = "0";
	char choi[10] = "0";//用于判断是否继续查找
	char commoditynumber[8] = "0";//要查找的信息编号
	char commodityname[20] = "0";//要查找的名称
	char commodityclass[10] = "0";//要查找的类别
	char commodityplaceoforigin[10] = "0";//要查找的产地
	char commoditymanufacturer[20] = "0";//要查找的厂家
	char cho[10] = "0";//查询的选择
	int i = 0;//for循环中使用
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色

	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                        *******请选择您要查询的方式：*******" << endl;
	cout << "\t\t                       *******      1-->精确查找      *******" << endl;
	cout << "\t\t                      *******       2-->模糊查找       *******" << endl;
	cout << "\t\t                        *******     3-->返回主菜单   *******" << endl;
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                     请输入您的选择(1-3):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> choice;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		CommodityOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		cout << "\t\t                           *******************************" << endl;
		cout << "\t\t                          *******  请选择查询依据:  *******" << endl;
		cout << "\t\t                        *******     1-->按商品编号    *******" << endl;
		cout << "\t\t                       *******      2-->按商品名称     *******" << endl;
		cout << "\t\t                         *******    3-->返回主菜单   *******" << endl;
		cout << "\t\t                           *******************************" << endl;
		cout << "\t\t                     请输入您的选择（1-6）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout << "\t\t          请输入商品编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> commoditynumber;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色

			CommodityNode* p = NULL;//p是查找位置
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无商品信息！" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}

			p = head;
			while (p != NULL && strcmp(commoditynumber, p->data.commodityNumber) != 0)
			{
				p = p->next;
				i++;
			}

			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        该商品不存在!" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}
			else
			{
				cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
					<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
				cout << setw(3) << p->data.commodityNumber << '\t'
					<< setw(3) << p->data.commodityName << '\t'
					<< setw(3) << p->data.commodityClass << '\t'
					<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
					<< setw(3) << p->data.commodityManufacturer << '\t'
					<< setw(10) << p->data.commodityPurchasePrice << '\t'
					<< setw(3) << p->data.commodityPrice << '\t'
					<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
					<< setw(8) << p->data.commoditySoldQuantity << '\t'
					<< setw(8) << p->data.commodityInventoryQuantity << '\t'
					<< setw(8) << p->data.commodityInventoryAmount << '\t'
					<< endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          请输入商品名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> commodityname;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			struct CommodityNode* p = NULL;//p是查找位置
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无商品信息！" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}

			p = head;
			while (p != NULL && strcmp(commodityname, p->data.commodityName) != 0)
			{
				p = p->next;
				i++;
			}

			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        该商品不存在" << endl;
				cout << "请按任意键继续" << endl;
				_getch();
			}
			else
			{
				cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
					<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
				cout << setw(3) << p->data.commodityNumber << '\t'
					<< setw(3) << p->data.commodityName << '\t'
					<< setw(3) << p->data.commodityClass << '\t'
					<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
					<< setw(3) << p->data.commodityManufacturer << '\t'
					<< setw(10) << p->data.commodityPurchasePrice << '\t'
					<< setw(3) << p->data.commodityPrice << '\t'
					<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
					<< setw(8) << p->data.commoditySoldQuantity << '\t'
					<< setw(8) << p->data.commodityInventoryQuantity << '\t'
					<< setw(8) << p->data.commodityInventoryAmount << '\t'
					<< endl;
			}
		}

		else if (strcmp(cho, "3") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "\t\t                            选择出错！\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		}
	}
	if (strcmp(choice, "2") == 0)
	{
		CommodityOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                      ************   请选择查询依据:  *********" << endl;
		cout << "\t\t                    *************   1-->按商品名称     *******" << endl;
		cout << "\t\t                     **********     2-->按商品类别     *******" << endl;
		cout << "\t\t                     *********      3-->按产地          *******" << endl;
		cout << "\t\t                        *******     4-->按生产厂家    *******" << endl;
		cout << "\t\t                         *******    5-->返回主菜单   *******" << endl;
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                      请输入您的选择（1-6）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");

		if (strcmp(cho, "1") == 0)
		{
			cout << "          请输入想查询的商品名称:" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			char commodityclass[20] = "0";
			cin >> commodityname;
			int length = 0;//商品的链表长度
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			struct CommodityNode* p = NULL;//p是查找位置
			int i = 0;//位置序号

			if (head == NULL)//如果是空链表
			{
				cout << "无商品信息！" << endl;
				return -1;//表示此时链表为空
			}

			p = head;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				char* s = NULL;
				s = strstr(p->data.commodityName, commodityname);
				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						i++;
					}
					cout << setw(3) << p->data.commodityNumber << '\t'
						<< setw(3) << p->data.commodityName << '\t'
						<< setw(3) << p->data.commodityClass << '\t'
						<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
						<< setw(3) << p->data.commodityManufacturer << '\t'
						<< setw(10) << p->data.commodityPurchasePrice << '\t'
						<< setw(3) << p->data.commodityPrice << '\t'
						<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
						<< setw(8) << p->data.commoditySoldQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryAmount << '\t'
						<< endl;
					j++;
				}
			}

			if (j == 0)
			{
				cout << "没有该类别的商品" << endl;
				_getch();
			}
		}
		if (strcmp(cho, "2") == 0)
		{
			cout << "          请输入想查询的商品类别:" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			char commodityclass[20] = "0";
			cin >> commodityclass;
			int length = 0;//商品的链表长度
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			struct CommodityNode* p = NULL;//p是查找位置
			int i = 0;//位置序号

			if (head == NULL)//如果是空链表
			{
				cout << "无商品信息！" << endl;
				return -1;//表示此时链表为空
			}

			p = head;

			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				char* s = NULL;
				s = strstr(p->data.commodityClass, commodityclass);
				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						i++;
					}
					cout << setw(3) << p->data.commodityNumber << '\t'
						<< setw(3) << p->data.commodityName << '\t'
						<< setw(3) << p->data.commodityClass << '\t'
						<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
						<< setw(3) << p->data.commodityManufacturer << '\t'
						<< setw(10) << p->data.commodityPurchasePrice << '\t'
						<< setw(3) << p->data.commodityPrice << '\t'
						<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
						<< setw(8) << p->data.commoditySoldQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryAmount << '\t'
						<< endl;
					j++;
				}
			}

			if (j == 0)
			{
				cout << "没有该类别的商品" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          请输入产地:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> commodityplaceoforigin;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			struct CommodityNode* p = NULL;//p是查找位置
			int length = 0;//商品的链表长度
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无商品信息！" << endl;
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
				char* s = NULL;
				s = strstr(p->data.commodityPlaceOfOrigin, commodityplaceoforigin);
				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						i++;
					}
					cout << setw(3) << p->data.commodityNumber << '\t'
						<< setw(3) << p->data.commodityName << '\t'
						<< setw(3) << p->data.commodityClass << '\t'
						<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
						<< setw(3) << p->data.commodityManufacturer << '\t'
						<< setw(10) << p->data.commodityPurchasePrice << '\t'
						<< setw(3) << p->data.commodityPrice << '\t'
						<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
						<< setw(8) << p->data.commoditySoldQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "没有该产地的商品" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          请输入生产厂家:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> commoditymanufacturer;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			struct CommodityNode* p = NULL;//p是查找位置
			int length = 0;//链表长度
			int i = 0;//位置序号
			if (head == NULL)//如果是空链表
			{
				cout << "无商品信息！" << endl;
				_getch();
				return -1;//表示此时链表为空
			}

			p = head;
			cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
				<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				char* s = NULL;
				s = strstr(p->data.commodityManufacturer, commoditymanufacturer);

				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						i++;
					}
					cout << setw(3) << p->data.commodityNumber << '\t'
						<< setw(3) << p->data.commodityName << '\t'
						<< setw(3) << p->data.commodityClass << '\t'
						<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
						<< setw(3) << p->data.commodityManufacturer << '\t'
						<< setw(10) << p->data.commodityPurchasePrice << '\t'
						<< setw(3) << p->data.commodityPrice << '\t'
						<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
						<< setw(8) << p->data.commoditySoldQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryQuantity << '\t'
						<< setw(8) << p->data.commodityInventoryAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "没有该产地的商品" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0 && strcmp(cho, "4") != 0 && strcmp(cho, "5") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "\t\t                                  选择出错！\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
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
		CommoditySearch(head);
	}
	if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		return 0;
	}
}



//根据商品编号/当商品售价/商品库存数量/商品销售数量 
void CommoditySelectionSort(CommodityNode* head)
{
	system("cls");//清屏
	CommodityNode* p = NULL;
	CommodityNode* q = NULL;
	CommodityNode* r = NULL;
	CommodityNode* k = NULL;
	Commodity temp1;
	Commodity temp2;
	int i = 0;
	char cho[10] = "0";//排序依据选择
	char choi[10] = "0";//判断是否继续查看商品排序
	cout << "\t\t            ************************************************************************" << endl;
	cout << "\t\t           ********************          请选择排序依据:         ********************" << endl;
	cout << "\t\t          ********************         1-->按商品进货数量         ********************" << endl;
	cout << "\t\t         ********************          2-->按商品售价              ********************" << endl;
	cout << "\t\t         ********************          3-->按商品库存数量          ********************" << endl;
	cout << "\t\t          ********************         4-->按商品销售数量         ********************" << endl;
	cout << "\t\t           ********************        5-->返回主菜单            ********************" << endl;
	cout << "\t\t            ***********************************************************************" << endl;
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
	if (strcmp(cho, "1") == 0) //按商品进货数量排序，采用直接插入排序
	{

		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
			<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
			<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		//q = (StaffNode*)malloc(sizeof(StaffNode));//为结点分配内存单元
		q = new CommodityNode;//为结点分配内存单元
		q->next = head;//q的下一节点指向头结点
		head = q;//将头结点设为空
		p = head->next->next;//用指针p保存下未排序元素的信息
		head->next->next = NULL;//使用原链表构造有序区，当前仅有一个元素
		while (p != NULL)//遍历无序区
		{
			k = p->next;//保存位置
			r = head;//用指针指向有序区
			while (r->next != NULL && r->next->data.commodityPurchaseQuantity > p->data.commodityPurchaseQuantity)//判断指针指向的下一个元素与无序区取出元素的大小
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
			cout << setw(3) << p->data.commodityNumber << '\t'
				<< setw(3) << p->data.commodityName << '\t'
				<< setw(3) << p->data.commodityClass << '\t'
				<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
				<< setw(3) << p->data.commodityManufacturer << '\t'
				<< setw(10) << p->data.commodityPurchasePrice << '\t'
				<< setw(3) << p->data.commodityPrice << '\t'
				<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
				<< setw(8) << p->data.commoditySoldQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryAmount << '\t'
				<< endl;

			p = p->next;//指向下一个结点
		}
	}
	else if (strcmp(cho, "2") == 0)//按商品售价排序，采用冒泡排序（下沉法）
	{

		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
			<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
			<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		p = head;
		while (p != q)
		{
			while (p->next != q)
			{
				if (p->data.commodityPrice < p->next->data.commodityPrice) //比较相邻两个值，符合条件则交换
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
			cout << setw(3) << p->data.commodityNumber << '\t'
				<< setw(3) << p->data.commodityName << '\t'
				<< setw(3) << p->data.commodityClass << '\t'
				<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
				<< setw(3) << p->data.commodityManufacturer << '\t'
				<< setw(10) << p->data.commodityPurchasePrice << '\t'
				<< setw(3) << p->data.commodityPrice << '\t'
				<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
				<< setw(8) << p->data.commoditySoldQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryAmount << '\t'
				<< endl;
			p = p->next;//指向下一个结点
		}
	}
	else if (strcmp(cho, "3") == 0)//按商品库存数量排序，采用直接选择排序
	{

		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
			<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
			<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
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
				if (p->data.commodityInventoryQuantity > temp1.commodityInventoryQuantity)
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
			cout << setw(3) << p->data.commodityNumber << '\t'
				<< setw(3) << p->data.commodityName << '\t'
				<< setw(3) << p->data.commodityClass << '\t'
				<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
				<< setw(3) << p->data.commodityManufacturer << '\t'
				<< setw(10) << p->data.commodityPurchasePrice << '\t'
				<< setw(3) << p->data.commodityPrice << '\t'
				<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
				<< setw(8) << p->data.commoditySoldQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryAmount << '\t'
				<< endl;
			p = p->next;//指向下一个结点
		}
	}
	else if (strcmp(cho, "4") == 0) //按商品销售数量排序，采用直接选择排序
	{
	cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
		<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
		<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
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
				if (p->data.commoditySoldQuantity > temp1.commoditySoldQuantity)
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
			cout << setw(3) << p->data.commodityNumber << '\t'
				<< setw(3) << p->data.commodityName << '\t'
				<< setw(3) << p->data.commodityClass << '\t'
				<< setw(3) << p->data.commodityPlaceOfOrigin << '\t'
				<< setw(3) << p->data.commodityManufacturer << '\t'
				<< setw(10) << p->data.commodityPurchasePrice << '\t'
				<< setw(3) << p->data.commodityPrice << '\t'
				<< setw(8) << p->data.commodityPurchaseQuantity << '\t'
				<< setw(8) << p->data.commoditySoldQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryQuantity << '\t'
				<< setw(8) << p->data.commodityInventoryAmount << '\t'
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
		cout << "\t\t                           *******  是否继续查看商品排序？*******" << endl;
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
			CommoditySelectionSort(head);
		}
		i++;
	}
}
