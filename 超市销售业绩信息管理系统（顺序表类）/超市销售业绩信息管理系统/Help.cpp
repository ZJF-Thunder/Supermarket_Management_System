#ifndef _HELP_//避免头文件被重复包含
#define _HELP_
#include"Help.h"
#include<conio.h>
#include<iostream>
#include<windows.h>
#endif
using namespace std;

void help()
{
	cout << "************* 是否确认进入帮助模块？  *************\n";
	cout << "1 确认进入\n2 取消进入\n";
	int s = 0;//定义一个选择的变量
	cout << "输入您的选择:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	cin >> s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	if(s == 1)
	{
		cout <<"************* 欢迎进入帮助模块 ********\n"; 
	    int choose;//定义一个选择变量
	    cout<<"*************   请按照下列选项选择   *************"<<endl;
		cout<<"*************     1  系统简介     *************"<<endl;
	    //cout<<"*2  如果提示显示输入Y，我却输入了y，该怎么办？*****"<<endl;
	    //cout<<"*********     3  使用本系统的注意事项   *********"<<endl;
	    //cout<<"************* 请输入您的选择 1 or 2***********\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//浅蓝色
	    cin>>choose;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
	    switch(choose)
		{
		case 1:
			{
				cout << "亲爱的用户，您好！本系统的名称为“超市销售业绩信息管理系统\n";
				cout << "本系统的设计人员为：曾浚峰、苟银颖、匡婉莹、马辰。\n";
				cout << "本系统能实现的功能为如下：\n";
				cout << "输入商品信息模块：使得输入的信息格式化，使信息看上去一目了然\n";
				cout << "输入员工信息模块：按照要求输入相应的员工信息，使得管理人员更加便捷\n";
				cout << "删除商品信息模块：在此模块，你可以删除你想删除的商品信息，及时更新系统信息\n";
				cout << "删除员工信息模块：在此模块，你可以删除离职员工的信息，及时更新系统信息\n";
				cout << "修改商品信息模块：在此模块，你可以根据市场的不同，及时调整商品的各种信息，例如商品的进价、售价等\n";
				cout << "修改员工信息模块：在此模块，你可以及时更新员工的各项信息，比如每月销售的情况，累计销售情况等\n";
				cout << "查询商品信息模块：在此模块，你可以根据商品的编号或者名称等进行精准查询或者根据产地、厂家等进行模糊查询\n";
				cout << "查询员工信息模块：在此模块，你可以根据员工的姓名或者编号等进行精准查询或者根据性别等进行模糊查询\n";
				cout << "浏览商品信息模块：在此模块，你可以浏览所有商品的全部信息\n";
				cout << "浏览员工信息模块：在此模块，你可以浏览所有员工的全部信息\n";
				cout << "统计并显示各员工的销售量模块：在此模块，你可以看到每个员工从高到低的销售量\n";
				cout << "------------------------------------------------------------------------------------------------------------------\n";
				cout << "------------------------------------------------------------------------------------------------------------------\n";
				cout << "本系统旨在帮助您更好的管理超市，节约管理成本，实现管理的高效性和准确性\n";		
				cout << "感谢您的使用，希望您能有一个好的体验！\n";
				break;
			}
		default:cout<<"************* 选择出错，请重新选择！*************\n"<<endl;
		}
	}
	else
	{
		cout<<"************* 选择出错，请重新选择！*************\n"<<endl;
	}
	cout << "请按任意键继续！" << endl;
	_getch();
}