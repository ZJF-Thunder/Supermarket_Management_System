//#define _CRT_SECURE_NO_WARNNINGS //避免警告
#ifndef _STAFFDATA_//避免头文件被重复包含
#define _STAFFDATA_
#include"Class.h"
#include<iostream>
#include<windows.h>//控制台编程主要头文件
#include<iomanip>//用到setw()函数
#include<conio.h>//_getch()
#endif
using namespace std;

StaffData::StaffData()
{
	size = 0;
}

//员工构造函数的实现   数据成员初始化
StaffData::StaffData(Staff *Sf,int m)
{
	int i=0;//循环控制变量
	for (i=0;i<m;i++)
	{
		strcpy(data[i].staffNumber, Sf[i].staffNumber);
		strcpy(data[i].staffName, Sf[i].staffName);
		strcpy(data[i].staffgender, Sf[i].staffgender);
		data[i].staffMonthSaleQuantity = Sf[i].staffMonthSaleQuantity;
		data[i].staffMonthSaleAmount = Sf[i].staffMonthSaleAmount;
		data[i].staffTotalSaleQuantity = Sf[i].staffTotalSaleQuantity;
		data[i].staffTotalSaleAmount = Sf[i].staffTotalSaleAmount;

	}
	size = m;
}

//员工析构函数的实现 
StaffData::~StaffData()
{

}


//保存文件函数   保存输入的数据到文件中
bool StaffData::SaveFile()
{
	FILE *fp;//（大写）,创建文件指针
	int i = 0;
	char isSave[10] = "0" ;//是否保存变量
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	cout<<"是否保存？(Y/N):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	cin>> isSave;
	while (strcmp(isSave, "Y") != 0 && strcmp(isSave, "y") != 0 && strcmp(isSave, "N") != 0 && strcmp(isSave, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<< "输入错误，请重新输入:" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cin >> isSave;
	} 

	if (strcmp(isSave, "N") == 0 || strcmp(isSave, "n") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return 0;
	}
	else if (strcmp(isSave, "Y") == 0 || strcmp(isSave, "y") == 0)
	{

		//fp = fopen("StaffData.txt","w+");
		fopen_s(&fp, "StaffData.txt","w+");
		//fopen_s(&fp, "StaffData.txt","a+");
		if(!fp)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout<<"创建文件失败!"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			return 0;
		}
		i = 0;
		while(i<size)
		{
			fprintf(fp,"%s\t",data[i].staffNumber);	
			fprintf(fp,"%s\t",data[i].staffName);
			fprintf(fp,"%s\t",data[i].staffgender);
			fprintf(fp,"%d\t",data[i].staffMonthSaleQuantity);	
			fprintf(fp,"%f\t",data[i].staffMonthSaleAmount);
			fprintf(fp,"%d\t",data[i].staffTotalSaleQuantity);
			fprintf(fp,"%f\t\n",data[i].staffTotalSaleAmount);
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "共输入" << i << "个员工的信息到文件中！" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		fclose(fp);
		return true;
	}
}

//读取数据函数   读取文件中的数据到内存中
bool StaffData::ReadFile()
{
	FILE *fp;//文件指针
	int i=0;//循环控制
	fp=fopen("StaffData.txt","r");
	i=0;
	while(!feof(fp))
	{
		fscanf(fp,"%s\t",data[i].staffNumber);	
		fscanf(fp,"%s\t",data[i].staffName);
		fscanf(fp,"%s\t",data[i].staffgender);
		fscanf(fp,"%d\t",&data[i].staffMonthSaleQuantity);	
		fscanf(fp,"%f\t",&data[i].staffMonthSaleAmount);
		fscanf(fp,"%d\t",&data[i].staffTotalSaleQuantity);
		fscanf(fp,"%f\t\n",&data[i].staffTotalSaleAmount);
		i++;
	}
	size = i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	cout << "共读取" << size << "个员工的信息到内存中！" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	fclose(fp);
	return true;
	//return 1;
}


//增加（输入）员工的信息
void StaffData::input(StaffData *St, Staff *Sf,int m)
{
	St->ReadFile();//读取文件中的数据到内存中
	if (size != 0)
	{
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                        *******请确定是否为误操作！(Y or N)*******" << endl;
		cout << "\t\t                       *******       按 Y 返回主菜单        *******" << endl;
		cout << "\t\t                        *******       按 N 继续操作        *******" << endl;
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                       请输入您的选择:";
		char a[10] = "0" ;//确认误操作变量
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cin >> a ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout<< "输入错误，请重新输入:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cin >> a;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		} 
		if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "请输入增加的员工数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cin >> m;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			Sf = new Staff[m];
			/*这里可以再加一个询问用户是否需要更改员工的数量的功能（就是存在员工数量输入错误需要更改的可能性）*/
			system("cls");//清屏 

			//size = m;

			//data = new StaffData[size];//员工类动态数组 
			for (int i = 0; i < m; i++)
			{

				cout << "请输入第" << i + 1 << "个员工的编号:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "请输入第" << i + 1 << "个员工的名称:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "请输入第" << i + 1 << "个员工的性别:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffgender;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "请输入第"<< i + 1 <<"个员工的当月销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffMonthSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "请输入第"<< i + 1 <<"个员工的当月销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffMonthSaleAmount;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "请输入第"<< i + 1 <<"个员工的累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffTotalSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "请输入第"<< i + 1 <<"个员工的累计销售金额 :";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffTotalSaleAmount;
		    
				strcpy(data[size+i].staffNumber, Sf[i].staffNumber);
				strcpy(data[size+i].staffName, Sf[i].staffName);
				strcpy(data[size+i].staffgender, Sf[i].staffgender);
				data[size+i].staffMonthSaleQuantity = Sf[i].staffMonthSaleQuantity;
				data[size+i].staffMonthSaleAmount = Sf[i].staffMonthSaleAmount;
				data[size+i].staffTotalSaleQuantity = Sf[i].staffTotalSaleQuantity;
				data[size+i].staffTotalSaleAmount = Sf[i].staffTotalSaleAmount;
			
			//system("cls");
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "共增加" << m << "个员工的信息！" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			size = size + m;
			St->SaveFile(); //保存数据到文件中
			delete []Sf;
			//system("pause");	
		}
		else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
		{
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cin >> b ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout<< "输入错误，请重新输入:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> b;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		} 
		if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0 )
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "请输入增加的员工数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> m;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			Sf = new Staff[m];//动态内存分配数组
			/*这里可以再加一个询问用户是否需要更改员工的数量的功能（就是存在员工数量输入错误需要更改的可能性）*/
			system("cls");//清屏 

			//size = m;

			//data = new StaffData[size];//员工类动态数组 


			for (int i = 0; i < m; i++)
			{

				cout << "请输入第" << i + 1 << "个员工的编号:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个员工的名称:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第" << i + 1 << "个员工的性别:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffgender;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个员工的当月销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffMonthSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个员工的当月销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffMonthSaleAmount;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个员工的累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffTotalSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请输入第"<< i + 1 <<"个员工的累计销售金额 :";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> Sf[i].staffTotalSaleAmount;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色

				strcpy(data[i].staffNumber, Sf[i].staffNumber);
				strcpy(data[i].staffName, Sf[i].staffName);
				strcpy(data[i].staffgender, Sf[i].staffgender);
				data[i].staffMonthSaleQuantity = Sf[i].staffMonthSaleQuantity;
				data[i].staffMonthSaleAmount = Sf[i].staffMonthSaleAmount;
				data[i].staffTotalSaleQuantity = Sf[i].staffTotalSaleQuantity;
				data[i].staffTotalSaleAmount = Sf[i].staffTotalSaleAmount;
			
			//system("cls");
			}
			cout << "共增加" << m << "个员工的信息！" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			size = size + m;
			St->SaveFile(); //保存数据到文件中
			delete []Sf;
			//system("pause");	
		}
		else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
		{
			return ;
		}
	}

}

//输出员工的信息
void StaffData::output(StaffData *St)
{
	St->ReadFile();
	if (size != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
		for (int i = 0; i < size; i++)
		{
			cout<<setw(3)<< data[i].staffNumber << '\t'
				<<setw(3)<< data[i].staffName << '\t'
				<<setw(3)<< data[i].staffgender << '\t'
				<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
				<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
				<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
				<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
				<< endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "请按任意键继续"  <<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		_getch();
	}

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
	//system("pause");
}


//删除员工信息模块
void StaffData::del(StaffData *St)
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
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
	{
		St->output(St);

		char choose[10] = "0";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		cout << "************欢迎进入删除员工信息模块************\n";
		cout<<"*************   请选择删除方式   *************"<<endl;
    	cout<<"*************  1  按员工编号     *************"<<endl;
    	cout<<"*************  2  按员工姓名     *************"<<endl;
    	cout<<"************* 请输入您的选择 1 or 2 ***********\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	    cin >> choose;
		while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout << "输入错误，请重新输入:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> choose;
		} 
		if (strcmp(choose, "1") == 0)
		{
			char StaffData[8];//需要删除的员工编号 
            int k = 0;//用于判断是否找到了该员工
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	        cout << "请输入你需要删除的员工编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
            cin >> StaffData;//输入需要删除的员工编号
            //search();
            int num = 0;//寻找员工编号相同时的下标
            int i = 0;//对象数组员工编号的下标
            for (i = 0; i < size; i++)
			{
				if (strcmp(StaffData, data[i].staffNumber) == 0)//判断输入的员工编号是否和库存里的一样
				{
					num = i;
					for (int j = num; j < size; j++)
					{
						data[j] = data[j + 1];//将后面的员工数据向前移
					}
					size = size - 1;
					k = k + 1;
					break;
				}
			}
			if(k > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "*************       删除成功！      *************" << endl;
				St->SaveFile();
				cout << "***********   是否继续删除？Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				if(strcmp(exit, "N") == 0 || strcmp(exit, "n") == 0 )
				{
					return ;
				}
				if(strcmp(exit, "Y") == 0 || strcmp(exit, "y") == 0 )
				{
					del(St);
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "************* 对不起，没有找到该员工 *************" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "***********   是否继续删除？Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				if(strcmp(exit, "N") == 0 || strcmp(exit, "n") == 0 )
				{
					return ;
				}
				if(strcmp(exit, "Y") == 0 || strcmp(exit, "y") == 0 )
				{
					del(St);
				}
			}
		}
		else if (strcmp(choose, "2") == 0)
		{
			char StaffName[8];//需要删除的员工名称 
            int m = 0;//用于判断是否找到了该员工
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	        cout << "请输入你需要删除的员工的名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
            cin >> StaffName;//输入需要删除的员工名称
            //search();
            int num2 = 0;//寻找员工名称相同时的下标
            int i2 = 0;//对象数组员工名称的下标
            for (i2 = 0; i2 < size; i2++)
			{
				if (strcmp(StaffName, data[i2].staffName) == 0)//判断输入的员工名称是否和库存里的一样
				{
					num2 = i2;
					for (int j2 = num2; j2 < size; j2++)
					{
		        	    data[j2] = data[j2 + 1];//将后面的员工数据向前移
					}
					size = size - 1;
					m = m + 1;
					break;
				}
			}
	        if(m > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	         	cout << "*************       删除成功！      *************" << endl;
				St->SaveFile();
				cout << "***********   是否继续删除？Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				if(strcmp(exit, "N") == 0 || strcmp(exit, "n") == 0 )
				{
					return ;
				}
				if(strcmp(exit, "Y") == 0 || strcmp(exit, "y") == 0 )
				{
					del(St);
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout << "************* 对不起，没有找到该员工 *************" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "***********   是否继续删除？Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "输入错误，请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				if(strcmp(exit, "N") == 0 || strcmp(exit, "n") == 0 )
				{
					return ;
				}
				if(strcmp(exit, "Y") == 0 || strcmp(exit, "y") == 0 )
				{
					del(St);
				}
			}
		}
		St->SaveFile();
	}

	else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return ;
	}
}
 

//修改员工信息
void StaffData::modify(StaffData* St)
{
	St->ReadFile();
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
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
	{

		int f1 = 0;
		int i = 0;;
		int n = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		cout << "查找方式 ：1.编号 2.名字" << endl;
		int m = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin >> m;
		switch (m)
		{
		case 1:
			char Number[4];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "请输入你需要修改员工编号" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> Number;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i++)//查找输入的商品
			{

				if ((strcmp(Number, data[i].staffNumber) == 0))
				{
					n = 1;
					cout << "修改信息为:" << endl;

					cout << "员工编号:" << data[i].staffNumber << endl;

					cout << "员工名称:" << data[i].staffName << endl;

					cout << "员工性别:" << data[i].staffgender << endl;

					cout << "员工的当月销售数量:" << data[i].staffMonthSaleQuantity << endl;

					cout << "员工的当月销售金额:" << data[i].staffMonthSaleAmount << endl;

					cout << "员工的累计销售数量:" << data[i].staffTotalSaleQuantity << endl;

					cout << "员工的累计销售金额:" << data[i].staffTotalSaleAmount << endl;

					cout << "请确认是否修改该员工的信息（Y or N）：";
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
							cout << "修改前员工编号：" << data[i].staffNumber << endl;
							cout << "请输入员工编号:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工名称：" << data[i].staffName << endl;
							cout << "请输入员工名称:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工性别：" << data[i].staffgender << endl;
							cout << "请输入员工性别:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffgender;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工当月销售数量：" << data[i].staffMonthSaleQuantity << endl;
							cout << "请输入员工的当月销售数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffMonthSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工当月销售金额：" << data[i].staffMonthSaleAmount << endl;
							cout << "请输入员工的当月销售金额:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffMonthSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工累计销售数量：" << data[i].staffTotalSaleQuantity << endl;
							cout << "请输入员工的累计销售数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffTotalSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工累计销售金额：" << data[i].staffTotalSaleAmount << endl;
							cout << "请输入员工的累计销售金额:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffTotalSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> f1;
							if (f1)
							{
								modify(St);
							}
						}
						else if (z == 2)
						{
							cout << "请输入要修改的编号：" << endl;
							cout << "1.员工编号" << endl << "2.员工名称" << endl << "3.员工性别" << endl << "4.员工的当月销售数量" << endl << "5.员工的当月销售金额" << endl << "6.员工的累计销售数量" << endl << "7.员工的累计销售金额" << endl;
							int k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							switch (k)
							{
							case 1:
								cout << "修改前员工编号：" << data[i].staffNumber << endl;
								cout << "请输入员工编号:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;

							case 2:
								cout << "修改前员工名称：" << data[i].staffName << endl;
								cout << "请输入员工名称:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 3:
								cout << "修改前员工性别：" << data[i].staffgender << endl;
								cout << "请输入员工性别:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffgender;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 4:
								cout << "修改前员工当月销售数量：" << data[i].staffMonthSaleQuantity << endl;
								cout << "请输入员工的当月销售数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffMonthSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 5:
								cout << "修改前员工当月销售金额：" << data[i].staffMonthSaleAmount << endl;
								cout << "请输入员工的当月销售金额:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffMonthSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 6:
								cout << "修改前员工累计销售数量：" << data[i].staffTotalSaleQuantity << endl;
								cout << "请输入员工的累计销售数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffTotalSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 7:
								cout << "修改前员工累计销售金额：" << data[i].staffTotalSaleAmount << endl;
								cout << "请输入员工的累计销售金额:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffTotalSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
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

				else if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "找不到修改的目标" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			St->SaveFile();
			break;

		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout << "请输入你需要修改员工名字：" << endl;
			char Name[20];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin >> Name;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i++)//查找输入的商品
			{

				if ((strcmp(Name, data[i].staffName) == 0))
				{
					n = 1;
					cout << "修改信息为:" << endl;

					cout << "员工编号:" << data[i].staffNumber << endl;

					cout << "员工名称:" << data[i].staffName << endl;

					cout << "员工性别:" << data[i].staffgender << endl;

					cout << "员工的当月销售数量:" << data[i].staffMonthSaleQuantity << endl;

					cout << "员工的当月销售金额:" << data[i].staffMonthSaleAmount << endl;

					cout << "员工的累计销售数量:" << data[i].staffTotalSaleQuantity << endl;

					cout << "员工的累计销售金额:" << data[i].staffTotalSaleAmount << endl;

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
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
						if (z == 1)
						{
							cout << "修改前员工编号：" << data[i].staffNumber << endl;
							cout << "请输入员工编号:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工名称：" << data[i].staffName << endl;
							cout << "请输入员工名称:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工性别：" << data[i].staffgender << endl;
							cout << "请输入员工性别:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffgender;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工当月销售数量：" << data[i].staffMonthSaleQuantity << endl;
							cout << "请输入员工的当月销售数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffMonthSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工当月销售金额：" << data[i].staffMonthSaleAmount << endl;
							cout << "请输入员工的当月销售金额:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffMonthSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工累计销售数量：" << data[i].staffTotalSaleQuantity << endl;
							cout << "请输入员工的累计销售数量:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffTotalSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "修改前员工累计销售金额：" << data[i].staffTotalSaleAmount << endl;
							cout << "请输入员工的累计销售金额:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> data[i].staffTotalSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> f1;
							if (f1)
							{
								modify(St);
							}
						}
						else if (z == 2)
						{
							cout << "请输入要修改的编号：" << endl;
							cout << "1.员工编号" << endl << "2.员工名称" << endl << "3.员工性别" << endl << "4.员工的当月销售数量" << endl << "5.员工的当月销售金额" << endl << "6.员工的累计销售数量" << endl << "7.员工的累计销售金额" << endl;
							int k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
							switch (k)
							{
							case 1:
								cout << "修改前员工编号：" << data[i].staffNumber << endl;
								cout << "请输入员工编号:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;

							case 2:
								cout << "修改前员工名称：" << data[i].staffName << endl;
								cout << "请输入员工名称:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 3:
								cout << "修改前员工性别：" << data[i].staffgender << endl;
								cout << "请输入员工性别:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffgender;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 4:
								cout << "修改前员工当月销售数量：" << data[i].staffMonthSaleQuantity << endl;
								cout << "请输入员工的当月销售数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffMonthSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 5:
								cout << "修改前员工当月销售金额：" << data[i].staffMonthSaleAmount << endl;
								cout << "请输入员工的当月销售金额:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffMonthSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 6:
								cout << "修改前员工累计销售数量：" << data[i].staffTotalSaleQuantity << endl;
								cout << "请输入员工的累计销售数量:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffTotalSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 7:
								cout << "修改前员工累计销售金额：" << data[i].staffTotalSaleAmount << endl;
								cout << "请输入员工的累计销售金额:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> data[i].staffTotalSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
								cout << "!!!!!!!!!!!!是否继续修改？如果是输入1，不是输入0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
								cin >> f1;
								if (f1)
								{
									modify(St);
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

				else if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout << "找不到修改的目标" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			St->SaveFile();
			break;
		}

	}
	else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		return;
	}

}


//员工查找函数的实现
StaffData  StaffData::search(StaffData *St)
{
	char ch[10] = "0";     //用于判断是否继续查找
	char choice[10] = "0";//选择查询方式
	char cho[10] = "0";//选择查询依据
	int n = 0;//判断商品是否存在使用
	int m = 0;//存在符合条件员工时，输出一次列名使用
	int i = 0;//for循环遍历
	char snum[4] = "0";
	char snam[20] = "0";
	char sgen[5] = "0";
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                        *******请选择您要查询的方式：*******"<<endl;
	cout<<"\t\t                       *******      1-->精确查找      *******"<<endl;
	cout<<"\t\t                      *******       2-->模糊查找       *******"<<endl;
	cout<<"\t\t                       *******      3-->范围查找      *******"<<endl;
	cout<<"\t\t                        *******     4-->返回主菜单   *******"<<endl;
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                      请输入您的选择(1-4):"; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin>>choice;
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		//员工精确查找
		ReadFile();
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                          *******  请选择查询依据:  *******"<<endl;
		cout<<"\t\t                        *******     1-->按员工编号    *******"<<endl;
		cout<<"\t\t                       *******      2-->按员工名称     *******"<<endl;
		cout<<"\t\t                        *******     3-->按员工性别    *******"<<endl;
		cout<<"\t\t                         *******    4-->返回主菜单   *******"<<endl;
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                       请输入您的选择（1-4）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin>>cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout<<"          请输入员工编号:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>snum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(strcmp(snum,data[i].staffNumber)==0)
				{
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
						<<setw(3)<< data[i].staffName << '\t'
						<<setw(3)<< data[i].staffgender << '\t'
						<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
						<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
						<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
						<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
						<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        该员工不存在"<<endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout<<"          请输入员工名称:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>snam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(strcmp(snam,data[i].staffName)==0)
				{
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
						<<setw(3)<< data[i].staffName << '\t'
						<<setw(3)<< data[i].staffgender << '\t'
						<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
						<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
						<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
						<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
						<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        该员工不存在"<<endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout<<"          请输入员工性别:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>sgen;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(strcmp(sgen,data[i].staffgender)==0)
				{
				
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
						<<setw(3)<< data[i].staffName << '\t'
						<<setw(3)<< data[i].staffgender << '\t'
						<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
						<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
						<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
						<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
						<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        该员工不存在"<<endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "\t\t                           返回主菜单!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			system("cls");
			return *St;
		}
		else
		{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t                         选择出错！\n"<<endl;
		}
	}

	else if (strcmp(choice, "2") == 0)
	{
		//员工模糊查找
		ReadFile();
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                         *******  请选择查询方式:  *******"<<endl;
		cout<<"\t\t                        *******    1-->按员工编号   *******"<<endl;
		cout<<"\t\t                        *******    2-->按员工名称   *******"<<endl;
		cout<<"\t\t                         *******   3-->返回主菜单  *******"<<endl;
		cout<<"\t\t                           ******************************" << endl;
		cout<<"\t\t                        请输入您的选择（1-3）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin>>cho;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		if (strcmp(cho, "1") == 0)
		{
			cout<<"          请输入员工编号关键字:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>snum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(strstr(data[i].staffNumber,snum)!=NULL)
				{
				
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
					<<setw(3)<< data[i].staffName << '\t'
					<<setw(3)<< data[i].staffgender << '\t'
					<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
					<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
					<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        关键词不存在！"<<endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout<<"          请输入员工名称关键字:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>snam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(strstr(data[i].staffName,snam)!=NULL)
				{
				
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
					<<setw(3)<< data[i].staffName << '\t'
					<<setw(3)<< data[i].staffgender << '\t'
					<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
					<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
					<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        关键词不存在！"<<endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "返回主菜单!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			system("cls");
			return *St;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout<<"\t\t                                    选择出错！\n"<<endl;
		}
	}
	else if (strcmp(choice, "3") == 0)//员工范围查找
	{
		ReadFile();
		int smsq1 = 0;
		int smsq2 = 0;
		int stsq1 = 0;
		int stsq2 = 0;//当月销售数量下限/当月销售数量上限/当月销售金额下限/当月销售金额上限
		float smsa1 = 0;
		float smsa2 = 0;
		float stsa1 = 0;
		float stsa2 = 0;//累计销售数量下限/累计销售数量上限/累计销售金额下限/累计销售金额上限
		char a[10] = "0";
		cout<<"\t\t                          ***********************************" << endl;
		cout<<"\t\t                        *******      请选择查询方式:    *******"<<endl;
		cout<<"\t\t                       *******   1-->按员工当月销售数量  *******"<<endl;
		cout<<"\t\t                      *******    2-->按员工当月销售金额   *******"<<endl;
		cout<<"\t\t                      *******    3-->按员工累计销售数量   *******"<<endl;
		cout<<"\t\t                       *******   4-->按员工累计销售金额  *******"<<endl;
		cout<<"\t\t                        *******  5-->返回主菜单         *******"<<endl;
		cout<<"\t\t                          ***********************************" << endl;
		cout<<"\t\t                      请输入您的选择（1-5）:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin>>cho;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout<<"          请输入最低当月销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>smsq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout<<"          请输入最高当月销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>smsq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			while(smsq1 > smsq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                           非法输入（最低>最高)！请重新输入!"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* 是否继续范围查找？******" << endl;
				cout<<"\t\t                      *******    Y-->继续查找    *******" << endl;
				cout<<"\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout<< "                 输入错误!请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return *St;
				}
				cout<<"          请输入最低当月销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>smsq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout<<"          请输入最高当月销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>smsq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(smsq1 <=data[i].staffMonthSaleQuantity && smsq2 >= data[i].staffMonthSaleQuantity)
				{
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
					<<setw(3)<< data[i].staffName << '\t'
					<<setw(3)<< data[i].staffgender << '\t'
					<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
					<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
					<< endl;
					n = 1;
					}
			}	
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        不存在符合条件的员工信息！"<<endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout<<"          请输入最低当月销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>smsa1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout<<"          请输入最高当月销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>smsa2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			while(smsa1 > smsa2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"                       非法输入（最低>最高)！请重新输入!"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* 是否继续范围查找？******" << endl;
				cout<<"\t\t                      *******    Y-->继续查找    *******" << endl;
				cout<<"\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout<< "                 输入错误!请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return *St;
				}
				cout<<"          请输入最低当月销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>smsa1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout<<"          请输入最高当月销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>smsa2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(smsa1 <=data[i].staffMonthSaleAmount && smsa2 >= data[i].staffMonthSaleAmount)
				{
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
					<<setw(3)<< data[i].staffName << '\t'
					<<setw(3)<< data[i].staffgender << '\t'
					<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
					<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
					<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        不存在符合条件的员工信息！"<<endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout<<"          请输入最低累计销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>stsq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout<<"          请输入最高累计销售数量:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>stsq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			while(stsq1 > stsq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"               非法输入（最低>最高)！请重新输入！"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* 是否继续范围查找？******" << endl;
				cout<<"\t\t                      *******    Y-->继续查找    *******" << endl;
				cout<<"\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout<< "                 输入错误!请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return *St;
				}
				cout<<"          请输入最低累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>stsq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout<<"          请输入最高累计销售数量:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>stsq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(stsq1 <=data[i].staffTotalSaleQuantity && stsq2 >= data[i].staffTotalSaleQuantity)
				{
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
					<<setw(3)<< data[i].staffName << '\t'
					<<setw(3)<< data[i].staffgender << '\t'
					<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
					<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
					<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        不存在符合条件的员工信息！"<<endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout<<"          请输入最低累计销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>stsa1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			cout<<"          请输入最高累计销售金额:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
			cin>>stsa2;
			while(stsa1 > stsa2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"                     非法输入（最低>最高)！请重新输入！"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* 是否继续范围查找？******" << endl;
				cout<<"\t\t                      *******    Y-->继续查找    *******" << endl;
				cout<<"\t\t                       *******   N-->返回主菜单 *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      请输入您的选择:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
					cout<< "                 输入错误!请重新输入:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
					return *St;
				}
				cout<<"          请输入最低累计销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>stsa1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout<<"          请输入最高累计销售金额:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
				cin>>stsa2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
			}
			for (i = 0; i < size; i ++)//遍历文件中数据
			{
				if(stsa1 <=data[i].staffTotalSaleAmount && stsa2 >= data[i].staffTotalSaleAmount)
				{
					if(m == 0)//员工存在的情况下，输出一次列名
					{
						cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
							<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
						cout << endl;
						m++; //改变m值，之后就不会再输出
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//蓝色
					cout<<setw(3)<< data[i].staffNumber << '\t'
					<<setw(3)<< data[i].staffName << '\t'
					<<setw(3)<< data[i].staffgender << '\t'
					<<setw(8)<< data[i].staffMonthSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffMonthSaleAmount<<'\t' 
					<<setw(8)<< data[i].staffTotalSaleQuantity<<'\t'
					<<setw(8)<< data[i].staffTotalSaleAmount<<'\t'
					<< endl;
					n = 1;
					}
			}
			if(n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
				cout<<"\t\t        不存在符合条件的员工信息！"<<endl;
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "返回主菜单!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
			system("cls");
			return *St;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色
			cout<<"\t\t                               选择出错！\n"<<endl;
		}
	}

	else if (strcmp(choice, "4") == 0)
	{
		cout << "返回主菜单!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
		system("cls");
		return *St;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<<"\t\t                                          选择出错!\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	}
	i = 0; //用于判断在选择是否继续查找时，选择是否出错
	while(strcmp(ch, "Y") != 0 && strcmp(ch, "y") != 0 && strcmp(ch, "N") != 0 && strcmp(ch, "n") != 0)
	{
		if(i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout<<"\t\t                                     非法输入！请重新输入！"<<endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<<"\t\t                             *******************************" << endl;
		cout<<"\t\t                           *******   是否继续查找？    *******"<<endl;
		cout<<"\t\t                         *******      Y-->继续查找      *******"<<endl;
		cout<<"\t\t                          *******     N-->返回主菜单  *******"<<endl;
		cout<<"\t\t                             ******************************" << endl;
		cout<<"\t\t                         请输入您的选择(Y or N):"; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
		cin>>ch;
		system("cls");
		if(strcmp(ch, "N") == 0||strcmp(ch, "n") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			return *St;
		}
		else if(strcmp(ch, "y") == 0||strcmp(ch, "Y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			search(St);
		}
		i++;
	}
	cout << "请按任意键继续"  <<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	_getch();
	return *St;
}


//根据当月销售数量/当月销售金额/累计销售数量/累计销售金额降序排序
void StaffData::selectionSort(StaffData* St, Staff* temp)
{
	system("cls");//清屏
	St->ReadFile();
	temp = new Staff;
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
	if (strcmp(cho, "1") == 0)
	{

		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 1; i < size; i++)    //按当月销售数量排序，采用直接插入排序
		{
			*temp = data[i];
			int j = i - 1;
			while (j >= 0 && temp->staffMonthSaleQuantity > data[j].staffMonthSaleQuantity)
			{
				data[j + 1] = data[j];
				j--;
			}
			j++;
			data[j] = *temp;
		}
		for (int i = 0; i < size; i++)
		{
			cout << setw(3) << data[i].staffNumber << '\t'
				<< setw(3) << data[i].staffName << '\t'
				<< setw(3) << data[i].staffgender << '\t'
				<< setw(8) << data[i].staffMonthSaleQuantity << '\t'
				<< setw(8) << data[i].staffMonthSaleAmount << '\t'
				<< setw(8) << data[i].staffTotalSaleQuantity << '\t'
				<< setw(8) << data[i].staffTotalSaleAmount << '\t'
				<< endl;
		}

	}
	else if (strcmp(cho, "2") == 0)
	{

		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)   //按当月销售金额排序，采用冒泡排序（下沉法） 
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (data[j + 1].staffMonthSaleAmount > data[j].staffMonthSaleAmount)
				{
					*temp = data[j + 1];
					data[j + 1] = data[j];
					data[j] = *temp;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			cout << setw(3) << data[i].staffNumber << '\t'
				<< setw(3) << data[i].staffName << '\t'
				<< setw(3) << data[i].staffgender << '\t'
				<< setw(8) << data[i].staffMonthSaleQuantity << '\t'
				<< setw(8) << data[i].staffMonthSaleAmount << '\t'
				<< setw(8) << data[i].staffTotalSaleQuantity << '\t'
				<< setw(8) << data[i].staffTotalSaleAmount << '\t'
				<< endl;
		}
	}
	else if (strcmp(cho, "3") == 0)
	{

		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)    //按累计销售数量排序，采用直接选择排序
		{
			int k = i;
			*temp = data[i];
			for (int j = i + 1; j < size; j++)
			{
				if (data[j].staffTotalSaleQuantity > temp->staffTotalSaleQuantity)
				{
					*temp = data[j];
					k = j;
				}
			}
			data[k] = data[i];
			data[i] = *temp;
			cout << setw(3) << data[i].staffNumber << '\t'
				<< setw(3) << data[i].staffName << '\t'
				<< setw(3) << data[i].staffgender << '\t'
				<< setw(8) << data[i].staffMonthSaleQuantity << '\t'
				<< setw(8) << data[i].staffMonthSaleAmount << '\t'
				<< setw(8) << data[i].staffTotalSaleQuantity << '\t'
				<< setw(8) << data[i].staffTotalSaleAmount << '\t'
				<< endl;
		}
	}
	else if (strcmp(cho, "4") == 0)
	{
		cout << "编号" << '\t' << "姓名" << '\t' << "性别" << '\t' << "当月销售数量" << '\t'
			<< "当月销售金额" << '\t' << "累计销售数量" << '\t' << "累计销售金额" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)    //按累计销售金额排序，采用直接选择排序
		{
			int k = i;
			*temp = data[i];
			for (int j = i + 1; j < size; j++)
			{
				if (data[j].staffTotalSaleAmount > temp->staffTotalSaleAmount)
				{
					*temp = data[j];
					k = j;
				}
			}
			data[k] = data[i];
			data[i] = *temp;
			cout << setw(3) << data[i].staffNumber << '\t'
				<< setw(3) << data[i].staffName << '\t'
				<< setw(3) << data[i].staffgender << '\t'
				<< setw(8) << data[i].staffMonthSaleQuantity << '\t'
				<< setw(8) << data[i].staffMonthSaleAmount << '\t'
				<< setw(8) << data[i].staffTotalSaleQuantity << '\t'
				<< setw(8) << data[i].staffTotalSaleAmount << '\t'
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
			selectionSort(St, temp);
		}
		i++;
	}
	delete temp;
	cout << "请按任意键继续" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	_getch();
	//system("pause");
}
