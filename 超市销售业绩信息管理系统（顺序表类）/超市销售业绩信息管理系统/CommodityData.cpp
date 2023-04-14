//#define _CRT_SECURE_NO_WARNNINGS //避免警告
#ifndef _COMMODITYDATA_//避免头文件被重复包含
#define _COMMODITYDATA_//避免头文件被重复包含
#include"Class.h"
#include<iostream>
#include<windows.h>//控制台编程主要头文件
#include<iomanip>//用到setw()函数
#include<conio.h>//_getch()
#endif//避免头文件被重复包含
using namespace std;

CommodityData::CommodityData()
{
	size = 0;
	//data = new Commodity[size];
	//Commodity *data = new Commodity[size];//数据
}
//商品构造函数的实现   数据成员初始化
CommodityData::CommodityData(Commodity Cd[],int m)
{
	int i = 0;//循环控制变量
	for (i = 0; i < m; i ++)
	{
		strcpy(data[i].commodityNumber, Cd[i].commodityNumber);
		strcpy(data[i].commodityName, Cd[i].commodityName);
		strcpy(data[i].commodityClass, Cd[i].commodityClass);
		strcpy(data[i].commodityPlaceOfOrigin, Cd[i].commodityPlaceOfOrigin);
		strcpy(data[i].commodityManufacturer , Cd[i].commodityManufacturer);
		data[i].commodityPurchasePrice = Cd[i].commodityPurchasePrice;
		data[i].commodityInventoryAmount = Cd[i].commodityInventoryAmount;
		data[i].commodityInventoryQuantity = Cd[i].commodityInventoryQuantity;
		data[i].commodityPurchaseQuantity = Cd[i].commodityPurchaseQuantity;
		data[i].commoditySoldQuantity = Cd[i].commoditySoldQuantity;
		data[i].commodityPrice = Cd[i].commodityPrice;
	}
	size = m;
}

//商品析构函数的实现 
CommodityData::~CommodityData()
{

}


//保存文件函数   保存输入的数据到文件中
bool CommodityData::SaveFile()
{
	FILE *fp;//（大写）,创建文件指针
	int i = 0;
	char isSave[10] = "0" ;//是否保存变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "是否保存？(Y/N):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> isSave;
	while (strcmp(isSave, "Y") != 0 && strcmp(isSave, "y") != 0 && strcmp(isSave, "N") != 0 && strcmp(isSave, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout<< "输入错误，请重新输入:" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> isSave;
	} 

	if (strcmp(isSave, "N") == 0 || strcmp(isSave, "n") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	else if (strcmp(isSave, "Y") == 0 || strcmp(isSave, "y") == 0)
	{
		//fp = fopen("CommodityData.txt","w+");
		fopen_s(&fp, "CommodityData.txt","w+");
		if(!fp)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout<<"创建文件失败!"<<endl;
			return 0;
		}
		i = 0;
		while(i < size)
		{
			fprintf(fp,"%s\t",data[i].commodityNumber);	
			fprintf(fp,"%s\t",data[i].commodityName);
			fprintf(fp,"%s\t",data[i].commodityClass);
			fprintf(fp,"%s\t",data[i].commodityPlaceOfOrigin);	
			fprintf(fp,"%s\t",data[i].commodityManufacturer);
			fprintf(fp,"%f\t",data[i].commodityPurchasePrice);
			fprintf(fp,"%f\t",data[i].commodityPrice);
			fprintf(fp,"%d\t",data[i].commodityPurchaseQuantity);
			fprintf(fp,"%d\t",data[i].commoditySoldQuantity);
			fprintf(fp,"%d\t",data[i].commodityInventoryQuantity);
			fprintf(fp,"%d\t\n",data[i].commodityInventoryAmount);
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "共输入" << i << "个商品的信息到文件中！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		fclose(fp);
		return true;
	}
}

//读取数据函数   读取文件中的数据到内存中
bool CommodityData::ReadFile()
{
	FILE *fp;//文件指针
	int i=0;//循环控制
	fp=fopen("CommodityData.txt","r");
	while(!feof(fp))
	{
		//fscanf_s(fp,"%s\t",data[i].commodityNumber, 8);
		fscanf(fp,"%s\t",data[i].commodityNumber);	
		fscanf(fp,"%s\t",data[i].commodityName);
		fscanf(fp,"%s\t",data[i].commodityClass);
		fscanf(fp,"%s\t",data[i].commodityPlaceOfOrigin);	
		fscanf(fp,"%s\t",data[i].commodityManufacturer);
		fscanf(fp,"%f\t",&data[i].commodityPurchasePrice);
		fscanf(fp,"%f\t",&data[i].commodityPrice);
		fscanf(fp,"%d\t",&data[i].commodityPurchaseQuantity);
		fscanf(fp,"%d\t",&data[i].commoditySoldQuantity);
		fscanf(fp,"%d\t",&data[i].commodityInventoryQuantity);
		fscanf(fp,"%d\t\n",&data[i].commodityInventoryAmount);
		i++;
	}
	size = i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "共读取" << size << "个商品的信息到内存中！" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	fclose(fp);
	return true;
}



//增加（输入）商品的信息
void CommodityData::input(CommodityData *Co, Commodity *Cd, int m)
{
	//Co = new CommodityData;
	Co->ReadFile();//读取文件中的数据到内存中,得到size的值
	//ReadFile();
	if (size != 0)
	{
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                        *******请确定是否为误操作！(Y or N)*******" << endl;
		cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
		cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                       请输入您的选择:";
		char a[10] = "0" ;//确认误操作变量
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> a ;
		while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout<< "输入错误，请重新输入:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> a;
		} 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
		{
			cout << "请输入增加的商品数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> m;
			if (m < 0)
			{
				cout << "非法输入！请重新输入！" << endl;
				cin >> m;
			}
			Cd = new Commodity[m];//动态内存分配一个临时数组存放数据

			/*这里可以再加一个询问用户是否需要更改商品的数量的功能（就是存在商品数量输入错误需要更改的可能性）*/
			system("cls");//清屏 

			//size = m;

			//data = new CommodityData[size];//商品类动态数组 

			for (int i = 0; i < m; i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个商品的编号:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> (&Cd)[i]->commodityNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个商品的名称:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个商品的类别:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityClass;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的产地:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPlaceOfOrigin;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的生产厂家:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityManufacturer;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的进价:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPurchasePrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的售价:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的进货数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPurchaseQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commoditySoldQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的库存数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityInventoryQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout<<"请输入第"<< i + 1 <<"个商品的库存金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityInventoryAmount;

				strcpy(data[size+i].commodityNumber, Cd[i].commodityNumber);
				strcpy(data[size+i].commodityName, Cd[i].commodityName);
				strcpy(data[size+i].commodityClass, Cd[i].commodityClass);
				strcpy(data[size+i].commodityPlaceOfOrigin, Cd[i].commodityPlaceOfOrigin);
				strcpy(data[size+i].commodityManufacturer , Cd[i].commodityManufacturer);
				data[size+i].commodityPurchasePrice = Cd[i].commodityPurchasePrice;	
				data[size+i].commodityPrice = Cd[i].commodityPrice;
				data[size+i].commodityPurchaseQuantity = Cd[i].commodityPurchaseQuantity;
				data[size+i].commoditySoldQuantity = Cd[i].commoditySoldQuantity;
				data[size+i].commodityInventoryQuantity = Cd[i].commodityInventoryQuantity;
				data[size+i].commodityInventoryAmount = Cd[i].commodityInventoryAmount;
	
				//system("cls");
			}	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "共增加" << m << "个商品的信息！" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			size = size + m;
			Co->SaveFile(); //保存数据到文件中
			delete []Cd;
		}
		else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			return ;
		}
		
		
	}
	else if (size = 0)
	{
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                        *******请确定是否为误操作！(Y or N)*******" << endl;
		cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
		cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                       请输入您的选择:";
		char b[10] = "0" ;//确认误操作变量
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> b ;
		while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout<< "输入错误，请重新输入:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> b;
		} 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0 )
		{
			cout << "size = " << size<<endl;
			cout << "请输入增加的商品数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> m;

			Cd = new Commodity[m];//动态内存分配一个临时数组存放数据

			/*这里可以再加一个询问用户是否需要更改商品的数量的功能（就是存在商品数量输入错误需要更改的可能性）*/
			system("cls");//清屏 

			for (int i = 0; i < m; i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个商品的编号:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个商品的名称:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个商品的类别:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityClass;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的产地:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPlaceOfOrigin;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的生产厂家:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityManufacturer;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的进价:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPurchasePrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的售价:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的进货数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityPurchaseQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commoditySoldQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个商品的库存数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityInventoryQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout<<"请输入第"<< i + 1 <<"个商品的库存金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Cd[i].commodityInventoryAmount;

				strcpy(data[i].commodityNumber, Cd[i].commodityNumber);
				strcpy(data[i].commodityName, Cd[i].commodityName);
				strcpy(data[i].commodityClass, Cd[i].commodityClass);
				strcpy(data[i].commodityPlaceOfOrigin, Cd[i].commodityPlaceOfOrigin);
				strcpy(data[i].commodityManufacturer , Cd[i].commodityManufacturer);
				data[i].commodityPurchasePrice = Cd[i].commodityPurchasePrice;	
				data[i].commodityPrice = Cd[i].commodityPrice;
				data[i].commodityPurchaseQuantity = Cd[i].commodityPurchaseQuantity;
				data[i].commoditySoldQuantity = Cd[i].commoditySoldQuantity;
				data[i].commodityInventoryQuantity = Cd[i].commodityInventoryQuantity;  
				data[i].commodityInventoryAmount = Cd[i].commodityInventoryAmount;
	
				//system("cls");
			}	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "共增加" << m << "个商品的信息！" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			size = m;
			Co->SaveFile(); //保存数据到文件中
			//SaveFile();
			delete []Cd;
		}
		else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			return ;
		}
		
	}
	//delete Co;
	//system("pause");
}


//输出商品的信息
void CommodityData::output(CommodityData *Co)
{
	//Co = new CommodityData;
	Co->ReadFile();
	//ReadFile();
	if (size != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' 
			<< "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
			<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' 
			<< "库存数量" << '\t' << "库存金额" << endl;
		cout << endl;
		for (int i = 0; i < size; i++)
		{		//setw()设置字符之间的宽度
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
			cout<< setw(3)<< data[i].commodityNumber << '\t'
				<< setw(3)<< data[i].commodityName << '\t'
				<< setw(3)<< data[i].commodityClass << '\t'
				<< setw(3)<< data[i].commodityPlaceOfOrigin<<'\t'
				<< setw(3)<< data[i].commodityManufacturer<<'\t' 
				<< setw(10)<< data[i].commodityPurchasePrice<<'\t'
				<< setw(3)<< data[i].commodityPrice<<'\t'
				<< setw(8)<< data[i].commodityPurchaseQuantity<<'\t'
				<< setw(8)<< data[i].commoditySoldQuantity<<'\t'
				<< setw(8)<< data[i].commodityInventoryQuantity<<'\t'
				<< setw(8)<< data[i].commodityInventoryAmount<<'\t'
				<< endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请按任意键继续"  <<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		_getch();
	}
	//system("pause");	
	else if (size = 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout<< "很抱歉，文件中没有商品信息，请先添加商品信息！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请按任意键继续"  <<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		_getch();
		return ;
	}
	cout << endl;
	//delete Co;
	
}

//商品删除模块
 void CommodityData::del(CommodityData *Co)
{
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******请确定是否为误操作！(Y or N)*******" << endl;
	cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
	cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       请输入您的选择:";
	char a[10] = "0" ;//确认误操作变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> a ;
	while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> a;
	} 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )//如果继续操作
	{

		//CommodityData *Co;//声明一个商品对象
		Co->output(Co);//指向输出函数

		char choose[10] = "0";//定义一个选择字符
		cout << "************* 欢迎进入删除商品信息模块 ********\n"; 
	    cout << "*************   请选择删除方式   *************\n";
	    cout << "*************  1  按商品编号     *************\n";
	    cout << "*************  2  按商品名称     *************\n";
	    cout << "************* 请输入您的选择 1 or 2 ***********\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	    cin >> choose;
		while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0)//当既
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "输入错误，请重新输入:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> choose;
		} 
		if (strcmp(choose, "1") == 0)
		{
			char CommodityNumber[8];//需要删除的商品编号 
			int v = 0;//用于判断是否找到了商品
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	        cout << "请输入你需要删除的商品编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	        cin >> CommodityNumber;//输入需要删除的商品代码
	        //search();
	        int num = 0;//寻找商品编号相同时的下标
	        int i = 0;//对象数组商品编号的下标
         	for (i = 0; i < size; i++)
         	{
	        	if (strcmp(CommodityNumber, data[i].commodityNumber) == 0)//判断输入的商品编号是否和库存里的一样
	         	{
		        	num = i;
		        	for (int j = num; j < size; j++)
					{
			        	data[j] = data[j + 1];//将后面的商品数据向前移
					}
					size = size - 1;
					v = v + 1;
					
		            break;
				}
				
			}
			
			if(v > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				cout << "*************       删除成功！      *************" << endl;
				Co->SaveFile();
				cout << "***********   是否继续删除？(G or I):  ***********" << endl;
				char exit1[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit1;
				while(strcmp(exit1, "G") != 0 && strcmp(exit1, "g") != 0 && strcmp(exit1, "I") != 0 && strcmp(exit1, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit1;
				}
				while(strcmp(exit1, "I") == 0 || strcmp(exit1, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return ;
				}
				while(strcmp(exit1, "G") == 0 || strcmp(exit1, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					del(Co);
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "************* 对不起，没有找到该商品 *************" << endl;
				cout << "***********   是否继续删除？(G or I):  ***********" << endl;
				char exit2[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit2;
				while(strcmp(exit2, "G") != 0 && strcmp(exit2, "g") != 0 && strcmp(exit2, "I") != 0 && strcmp(exit2, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit2;
				}
				while(strcmp(exit2, "I") == 0 || strcmp(exit2, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return ;
				}
				while(strcmp(exit2, "G") == 0 || strcmp(exit2, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					del(Co);
				}
			}
			
		}
		else if (strcmp(choose, "2") == 0)
		{
	    	char CommodityName[8];//需要删除的商品名称 
			int v = 0;//用于判断是否找到了该商品
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "请输入你需要删除的商品的名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
         	cin >> CommodityName;//输入需要删除的商品名称
         	//search();
        	int u = 0;//寻找商品名称相同时的下标
        	int t = 0;//对象数组商品名称的下标
        	for (t = 0; t < size; t++)
        	{
	        	if (strcmp(CommodityName, data[t].commodityName) == 0)//判断输入的商品名称是否和库存里的一样
	        	{
		        	u = t;
					for (int s = u; s < size; s++)
					{
		    	    	data[s] = data[s + 1];//将后面的商品数据向前移
					}
	 		    	size = size - 1;//商品数量减1
					v = v + 1;
		        	//cout << "删除成功！" << endl;
					break;
	        	}
			}
			if(v > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				cout << "*************        删除成功！     *************" << endl;
				Co->SaveFile();
				cout << "***********   是否继续删除？(G or I):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit;
				while(strcmp(exit, "G") != 0 && strcmp(exit, "g") != 0 && strcmp(exit, "I") != 0 && strcmp(exit, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit;
				}
				while(strcmp(exit, "I") == 0 || strcmp(exit, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return ;
				}
				while(strcmp(exit, "G") == 0 || strcmp(exit, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					del(Co);
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "************* 对不起，没有找到该商品 *************" << endl;
				cout << "***********   是否继续删除？(G or I):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit;
				while(strcmp(exit, "G") != 0 && strcmp(exit, "g") != 0 && strcmp(exit, "I") != 0 && strcmp(exit, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit;
				}
				while(strcmp(exit, "I") == 0 || strcmp(exit, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return ;
				}
				while(strcmp(exit, "G") == 0 || strcmp(exit, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					del(Co);
				}
			}
    	}
	
		Co->SaveFile();
		//delete Co;
	}

	else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
	{
		return ;
	}
}


//修改商品信息
void CommodityData::modify(CommodityData* Co)
{
	Co->ReadFile();
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******请确定是否为误操作！(Y or N)*******" << endl;
	cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
	cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       请输入您的选择:";
	char a[10] = "0";//确认误操作变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> a;
	while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout << "输入错误，请重新输入:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> a;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
	{
		int f1 = 0;
		int n = 0;
		int i = 0;
		cout << "查找方式 ：1.编号 2.名字" << endl;
		int m = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> m;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		switch (m)
		{
		case 1:
			char Number[8];
			cout << "请输入你需要修改商品编号" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> Number;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i++)//查找输入的商品
			{

				if ((strcmp(Number, data[i].commodityNumber) == 0))
				{
					n = 1;
					cout << "修改信息为:" << endl;

					cout << "商品编号:" << data[i].commodityName << endl;

					cout << "商品类别:" << data[i].commodityClass << endl;

					cout << "产地:" << data[i].commodityPlaceOfOrigin << endl;

					cout << "生产厂家:" << data[i].commodityManufacturer << endl;

					cout << "商品进价:" << data[i].commodityPurchasePrice << endl;

					cout << "商品售价:" << data[i].commodityPrice << endl;

					cout << "商品进货数量:" << data[i].commodityPurchaseQuantity << endl;

					cout << "商品销售数量:" << data[i].commoditySoldQuantity << endl;

					cout << "商品库存数量:" << data[i].commodityInventoryQuantity << endl;

					cout << "商品库存金额:" << data[i].commodityInventoryAmount << endl;
					cout << "请确认是否修改该商品的信息（Y or N）：";
					char check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					if (check == 'Y' || check == 'y')
					{
						cout << "全部修改输入1，局部修改输入2:" << endl;
						int z = 0;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
						cin >> z;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
						if (z == 1)
						{
							cout << "修改前商品编号：" << data[i].commodityNumber << endl;
							cout << "请输入商品编号:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品名称：" << data[i].commodityName << endl;
							cout << "请输入商品名称:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品类别：" << data[i].commodityClass << endl;
							cout << "请输入商品类别:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityClass;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前产地：" << data[i].commodityPlaceOfOrigin << endl;
							cout << "请输入产地:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPlaceOfOrigin;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前生产厂家：" << data[i].commodityManufacturer << endl;
							cout << "请输入生产厂家:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityManufacturer;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品进价：" << data[i].commodityPurchasePrice << endl;
							cout << "请输入商品进价:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPurchasePrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品售价：" << data[i].commodityPrice << endl;
							cout << "请输入商品售价:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品进货数量：" << data[i].commodityPurchaseQuantity << endl;
							cout << "请输入商品进货数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPurchaseQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品销售数量：" << data[i].commoditySoldQuantity << endl;
							cout << "请输入商品销售数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commoditySoldQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品库存数量：" << data[i].commodityInventoryQuantity << endl;
							cout << "请输入商品库存数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityInventoryQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品库存金额：" << data[i].commodityInventoryAmount << endl;
							cout << "请输入商品库存金额:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityInventoryAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> f1;
							if (f1)
							{
								modify(Co);
							}
						}
						else if (z == 2)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "请输入要修改的编号：" << endl;
							cout << "1.商品编号" << endl << "2.商品名称" << endl << "3.商品类别" << endl << "4.产地" << endl << "5.生产厂家" << endl << "6.商品进价" << endl << "7.商品售价" << endl << "8.商品进货数量" << endl << "9.商品销售数量" << endl << "10.商品库存数量" << endl << "11.商品库存金额" << endl;
							int k = 0;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							switch (k)
							{
							case 1:
								cout << "修改前商品编号：" << data[i].commodityNumber << endl;
								cout << "请输入商品编号:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 2:
								cout << "修改前商品名称：" << data[i].commodityName << endl;
								cout << "请输入商品名称:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 3:
								cout << "修改前商品类别：" << data[i].commodityClass << endl;
								cout << "请输入商品类别:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityClass;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 4:
								cout << "修改前产地：" << data[i].commodityPlaceOfOrigin << endl;
								cout << "请输入产地:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPlaceOfOrigin;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 5:
								cout << "修改前生产厂家：" << data[i].commodityManufacturer << endl;
								cout << "请输入生产厂家:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityManufacturer;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 6:
								cout << "修改前商品进价：" << data[i].commodityPurchasePrice << endl;
								cout << "请输入商品进价:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPurchasePrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 7:
								cout << "修改前商品售价：" << data[i].commodityPrice << endl;
								cout << "请输入商品售价:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 8:
								cout << "修改前商品进货数量：" << data[i].commodityPurchaseQuantity << endl;
								cout << "请输入商品进货数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPurchaseQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 9:
								cout << "修改前商品销售数量：" << data[i].commoditySoldQuantity << endl;
								cout << "请输入商品销售数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commoditySoldQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 10:
								cout << "修改前商品库存数量：" << data[i].commodityInventoryQuantity << endl;
								cout << "请输入商品库存数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityInventoryQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 11:
								cout << "修改前商品库存金额：" << data[i].commodityInventoryAmount << endl;
								cout << "请输入商品库存金额:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityInventoryAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							}
						}

					}
					else
					{
						break;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					cout << "修改成功" << endl;
				}

				if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "找不到修改的目标" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			Co->SaveFile();
			break;

		case 2:
			cout << "请输入你需要修改商品名字：" << endl;
			char Name[20];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> Name;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i++)//查找输入的商品
			{

				if ((strcmp(Name, data[i].commodityName) == 0))
				{
					n = 1;
					cout << "修改信息为:" << endl;

					cout << "商品编号:" << data[i].commodityNumber << endl;

					cout << "商品名称:" << data[i].commodityName << endl;

					cout << "商品类别:" << data[i].commodityClass << endl;

					cout << "产地:" << data[i].commodityPlaceOfOrigin << endl;

					cout << "生产厂家:" << data[i].commodityManufacturer << endl;

					cout << "商品进价:" << data[i].commodityPurchasePrice << endl;

					cout << "商品售价:" << data[i].commodityPrice << endl;

					cout << "商品进货数量:" << data[i].commodityPurchaseQuantity << endl;

					cout << "商品销售数量:" << data[i].commoditySoldQuantity << endl;

					cout << "商品库存数量:" << data[i].commodityInventoryQuantity << endl;

					cout << "商品库存金额:" << data[i].commodityInventoryAmount << endl;

					cout << "请确认是否修改该商品的信息（Y or N）：";
					char check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					if (check == 'Y' || check == 'y')
					{
						cout << "全部修改输入1，局部修改输入2:" << endl;
						int z;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
						cin >> z;
						if (z == 1)
						{
							cout << "修改前商品编号：" << data[i].commodityNumber << endl;
							cout << "请输入商品编号:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品名称：" << data[i].commodityName << endl;
							cout << "请输入商品名称:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品类别：" << data[i].commodityClass << endl;
							cout << "请输入商品类别:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityClass;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前产地：" << data[i].commodityPlaceOfOrigin << endl;
							cout << "请输入产地:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPlaceOfOrigin;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前生产厂家：" << data[i].commodityManufacturer << endl;
							cout << "请输入生产厂家:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityManufacturer;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品进价：" << data[i].commodityPurchasePrice << endl;
							cout << "请输入商品进价:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPurchasePrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品售价：" << data[i].commodityPrice << endl;
							cout << "请输入商品售价:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品进货数量：" << data[i].commodityPurchaseQuantity << endl;
							cout << "请输入商品进货数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityPurchaseQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品销售数量：" << data[i].commoditySoldQuantity << endl;
							cout << "请输入商品销售数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commoditySoldQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品库存数量：" << data[i].commodityInventoryQuantity << endl;
							cout << "请输入商品库存数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityInventoryQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前商品库存金额：" << data[i].commodityInventoryAmount << endl;
							cout << "请输入商品库存金额:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].commodityInventoryAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> f1;
							if (f1)
							{
								modify(Co);
							}
						}
						else if (z == 2)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "请输入要修改的编号：" << endl;
							cout << "1.商品编号" << endl << "2.商品名称" << endl << "3.商品类别" << endl << "4.产地" << endl << "5.生产厂家" << endl << "6.商品进价" << endl << "7.商品售价" << endl << "8.商品进货数量" << endl << "9.商品销售数量" << endl << "10.商品库存数量" << endl << "11.商品库存金额" << endl;
							int k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							switch (k)
							{
							case 1:
								cout << "修改前商品编号：" << data[i].commodityNumber << endl;
								cout << "请输入商品编号:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 2:
								cout << "修改前商品名称：" << data[i].commodityName << endl;
								cout << "请输入商品名称:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 3:
								cout << "修改前商品类别：" << data[i].commodityClass << endl;
								cout << "请输入商品类别:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityClass;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 4:
								cout << "修改前产地：" << data[i].commodityPlaceOfOrigin << endl;
								cout << "请输入产地:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPlaceOfOrigin;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 5:
								cout << "修改前生产厂家：" << data[i].commodityManufacturer << endl;
								cout << "请输入生产厂家:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityManufacturer;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 6:
								cout << "修改前商品进价：" << data[i].commodityPurchasePrice << endl;
								cout << "请输入商品进价:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPurchasePrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 7:
								cout << "修改前商品售价：" << data[i].commodityPrice << endl;
								cout << "请输入商品售价:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 8:
								cout << "修改前商品进货数量：" << data[i].commodityPurchaseQuantity << endl;
								cout << "请输入商品进货数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityPurchaseQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 9:
								cout << "修改前商品销售数量：" << data[i].commoditySoldQuantity << endl;
								cout << "请输入商品销售数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commoditySoldQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 10:
								cout << "修改前商品库存数量：" << data[i].commodityInventoryQuantity << endl;
								cout << "请输入商品库存数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityInventoryQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 11:
								cout << "修改前商品库存金额：" << data[i].commodityInventoryAmount << endl;
								cout << "请输入商品库存金额:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].commodityInventoryAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							}
						}

					}
					else
					{
						break;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
					cout << "修改成功" << endl;
				}

				if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "找不到修改的目标" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			Co->SaveFile();
			break;
		}

	}
	else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return;
	}

}


//商品查找函数的实现
CommodityData  CommodityData::search(CommodityData *Co)
{
	char choice[10] = "0";
	char choi[10] = "0";//用于判断是否继续查找
	char cnum[8] = "0";//要查找的信息编号
	char cnam[20] = "0";//要查找的名称
	char ccla[10] = "0";//要查找的类别
	char cpoo[10] = "0";//要查找的产地
	char cmft[20] = "0";//要查找的厂家
	char cho[10] = "0";//查询的选择
	int n = 0;//判断商品是否存在
	int m = 0;//商品存在时输出一次列名
	int i = 0;//for循环中使用
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                        *******请选择您要查询的方式：*******"<<endl;
	cout<<"\t\t                       *******      1-->精确查找      *******"<<endl;
	cout<<"\t\t                      *******       2-->模糊查找       *******"<<endl;
	cout<<"\t\t                        *******     3-->返回主菜单   *******"<<endl;
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                      请输入您的选择(1-3):"; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin>>choice;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		Co->ReadFile();                //读取文件中的数据到内存中
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                          *******  请选择查询依据:  *******"<<endl;
		cout<<"\t\t                        *******     1-->按商品编号    *******"<<endl;
		cout<<"\t\t                       *******      2-->按商品名称     *******"<<endl;
		cout<<"\t\t                      *******       3-->按商品类别      *******"<<endl;
		cout<<"\t\t                       *******      4-->按产地         *******"<<endl;
		cout<<"\t\t                        *******     5-->按生产厂家    *******"<<endl;
		cout<<"\t\t                         *******    6-->返回主菜单   *******"<<endl;
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                      请输入您的选择（1-6）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");
		if (strcmp(cho, "1") == 0)
		{

			cout << "\t\t          请输入商品编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cnum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if (strcmp(cnum, data[i].commodityNumber) == 0)//判断是否有与查询编号一致的信息
				{
					if(m == 0)//商品存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
					n = 1;  //运行此步，则商品存在
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        该商品不存在" << endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          请输入商品名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cnam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strcmp(cnam, data[i].commodityName) == 0)//判断是否有与查询名称一致的信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
							<<data[i].commodityName << '\t'
							<<data[i].commodityClass << '\t'
							<<data[i].commodityPlaceOfOrigin<<'\t'
							<<data[i].commodityManufacturer<<'\t'
							<<data[i].commodityPurchasePrice<<'\t'
							<<data[i].commodityPrice<<'\t'
							<<data[i].commodityPurchaseQuantity<<'\t'
							<<data[i].commoditySoldQuantity<<'\t'
							<<data[i].commodityInventoryQuantity<<'\t'
							<<data[i].commodityInventoryAmount
							<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        该商品不存在" << endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          请输入商品类别:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> ccla;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strcmp(ccla, data[i].commodityClass) == 0)//判断是否有与查询类别一致的信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
							<<data[i].commodityName << '\t'
							<<data[i].commodityClass << '\t'
							<<data[i].commodityPlaceOfOrigin<<'\t'
							<<data[i].commodityManufacturer<<'\t'
							<<data[i].commodityPurchasePrice<<'\t'
							<<data[i].commodityPrice<<'\t'
							<<data[i].commodityPurchaseQuantity<<'\t'
							<<data[i].commoditySoldQuantity<<'\t'
							<<data[i].commodityInventoryQuantity<<'\t'
							<<data[i].commodityInventoryAmount
							<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        该商品不存在" << endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          请输入产地:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cpoo;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strcmp(cpoo, data[i].commodityPlaceOfOrigin) == 0)//判断是否有与查询产地一致的信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
							<<data[i].commodityName << '\t'
							<<data[i].commodityClass << '\t'
							<<data[i].commodityPlaceOfOrigin<<'\t'
							<<data[i].commodityManufacturer<<'\t'
							<<data[i].commodityPurchasePrice<<'\t'
							<<data[i].commodityPrice<<'\t'
							<<data[i].commodityPurchaseQuantity<<'\t'
							<<data[i].commoditySoldQuantity<<'\t'
							<<data[i].commodityInventoryQuantity<<'\t'
							<<data[i].commodityInventoryAmount
							<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        该商品不存在" << endl;
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "          请输入生产厂家:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cmft;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strcmp(cmft, data[i].commodityManufacturer) == 0)//判断是否有与查询厂家一致的信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
							<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        该商品不存在" << endl;
			}
		}
		else if (strcmp(cho, "6") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			return *Co;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "\t\t                            选择出错！\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		}
	}
	else if (strcmp(choice, "2") == 0)
	{
		Co->ReadFile();
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                          *******  请选择查询依据:  *******"<<endl;
		cout<<"\t\t                        *******     1-->按商品编号    *******"<<endl;
		cout<<"\t\t                       *******      2-->按商品名称     *******"<<endl;
		cout<<"\t\t                      *******       3-->按商品类别      *******"<<endl;
		cout<<"\t\t                       *******      4-->按产地         *******"<<endl;
		cout<<"\t\t                        *******     5-->按生产厂家    *******"<<endl;
		cout<<"\t\t                         *******    6-->返回主菜单   *******"<<endl;
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                      请输入您的选择（1-6）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout << "          请输入商品编号关键字:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cnum;
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityNumber, cnum) != NULL)//判断所有商品编号中是否含有查询信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
							n = 1;
					}
				}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        关键词不存在！" << endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          请输入商品名称关键字:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cnam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityName, cnam) != NULL)//判断所有商品名称中是否含有查询信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        关键词不存在！" << endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          请输入商品类别关键字:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> ccla;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityClass, ccla) != NULL)//判断所有商品类别中是否含有查询信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
							<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        关键词不存在！" << endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          请输入产地关键字:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cpoo;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityPlaceOfOrigin, cpoo) != NULL)//判断所有商品产地中是否含有查询信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        关键词不存在！" << endl;
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "          请输入生产厂家关键字:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> cmft;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityManufacturer, cmft) != NULL)//判断所有商品生产厂家中是否含有查询信息
				{
					if(m == 0)
					{
						cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t' << "生产厂家" << '\t' << "进价" << '\t'
							<< "售价" << '\t' << "进货数量" << '\t' << "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "\t\t        关键词不存在！" << endl;
			}
		}
		else if (strcmp(cho, "6") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			return *Co;
		}
		else
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
		return *Co;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
		cout<<"\t\t                             选择出错!\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	}
	i = 0; //用于判断在选择是否继续查找时，选择是否出错
	while(strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
	{
		if(i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout<<"\t\t                                     非法输入！请重新输入！"<<endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<<"\t\t                              ********************************" << endl;
		cout<<"\t\t                           *******    是否继续查找商品？  *******"<<endl;
		cout<<"\t\t                          *******       Y-->继续查找       *******"<<endl;
		cout<<"\t\t                           *******      N-->返回主菜单    *******"<<endl;
		cout<<"\t\t                              ********************************" << endl;
		cout<<"\t\t                          请输入您的选择(Y or N):"; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin>>choi;
		system("cls");
		if(strcmp(choi, "N") == 0||strcmp(choi, "n") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			return *Co;
		}
		else if(strcmp(choi, "y") == 0||strcmp(choi, "Y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			search(Co);
		}
		i++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout << "请按任意键继续"  <<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	_getch();
	//system("pause");
	return *Co;
}



//根据商品编号/当商品售价/商品库存数量/商品销售数量 
void CommodityData::selectionSort(CommodityData* Co, Commodity* t)
{
	system("cls");//清屏
	Co->ReadFile();
	t = new Commodity;
	char cho[10] = "0";//排序依据选择
	char choi[10] = "0";//判断是否继续查看商品排序
	cout << "\t\t            ************************************************************************" << endl;
	cout << "\t\t           ********************          请选择排序依据:         ********************" << endl;
	cout << "\t\t          ********************         1-->按商品编号             ********************" << endl;
	cout << "\t\t         ********************          2-->按商品售价              ********************" << endl;
	cout << "\t\t         ********************          3-->按商品库存数量          ********************" << endl;
	cout << "\t\t          ********************         4-->按商品销售数量         ********************" << endl;
	cout << "\t\t           ********************        5-->返回主菜单            ********************" << endl;
	cout << "\t\t            ***********************************************************************" << endl;
	cout << "\t\t         请输入您的选择（1-5）:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> cho;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色

	if (strcmp(cho, "1") == 0)
	{
		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
			<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
			<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 1; i < size; i++)    //按商品编号排序，采用直接插入排序
		{
			*t = data[i];
			int j = i - 1;
			while (j >= 0 && t->commodityNumber > data[j].commodityNumber)
			{
				data[j + 1] = data[j];
				j--;
			}
			j++;
			data[j] = *t;
		}

		for (int i = 0; i < size; i++)
		{
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
				<< endl;
		}

	}

	else if (strcmp(cho, "2") == 0)
	{

		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
			<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
			<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);

		for (int i = 0; i < size; i++)   //按商品售价排序，采用冒泡排序（下沉法） 
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (data[j + 1].commodityPrice > data[j].commodityPrice)
				{
					*t = data[j + 1];
					data[j + 1] = data[j];
					data[j] = *t;
				}
			}
		}

		for (int i = 0; i < size; i++)
		{
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
				<< endl;
		}
	}

	else if (strcmp(cho, "3") == 0)
	{

		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
			<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
			<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);

		for (int i = 0; i < size; i++)    //按商品库存数量排序，采用直接选择排序
		{
			int k = i;
			*t = data[i];
			for (int j = i + 1; j < size; j++)
			{
				if (data[j].commodityInventoryQuantity > t->commodityInventoryQuantity)
				{
					*t = data[j];
					k = j;
				}
			}
			data[k] = data[i];
			data[i] = *t;
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
				<< endl;
		}

	}

	else if (strcmp(cho, "4") == 0)
	{
		cout << "编号" << '\t' << "名称" << '\t' << "类别" << '\t' << "产地" << '\t'
			<< "生产厂家" << '\t' << "进价" << '\t' << "售价" << '\t' << "进货数量" << '\t'
			<< "销售数量" << '\t' << "库存数量" << '\t' << "库存金额" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)    //按商品销售数量排序，采用直接选择排序
		{
			int k = i;
			*t = data[i];
			for (int j = i + 1; j < size; j++)
			{
				if (data[j].commoditySoldQuantity > t->commoditySoldQuantity)
				{
					*t = data[j];
					k = j;
				}
			}
			data[k] = data[i];
			data[i] = *t;
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
				<< endl;
		}
	}

	else if (strcmp(cho, "5") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		return;
	}

	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "\t\t             选择出错，请重新选择！\n" << endl;
	}

	int i = 0; //用于判断在选择是否继续查找时，选择是否出错
	while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
	{
		if (i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "\t\t                                     输入错误，请重新输入！" << endl;
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
			selectionSort(Co, t);
		}
		i++;
	}

	delete t;
	cout << "请按任意键继续" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	_getch();
	//system("pause");
}
