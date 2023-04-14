#include "Commodity.h"
#include "Staff.h"
#include "Menu.h"
#include "Help.h"
#include<Graphics.h>
#include<easyx.h>
#include<conio.h>
#include<iostream>
using namespace std;

//菜单
void menu()
{
	MOUSEMSG m;//定义鼠标变量 m
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(0, 0, 70, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("楷体"));
	outtextxy(215, 70, _T("超市销售业绩信息管理系统"));//超市坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(460, 208, _T("商品系统"));
	outtextxy(460, 258, _T("员工系统"));
	outtextxy(460, 308, _T("退出系统"));
	outtextxy(20, 8, _T("帮助"));

	while (1)
	{
		//获取鼠标消息
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//画出红色的矩形框线
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//进入商品子菜单
			if (m.uMsg == WM_LBUTTONDOWN) //鼠标左键点击消息
			{
				closegraph();
				CommodityDataMenu();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//进入员工子菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				StaffDataMenu();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);//退出系统
			}
		}
		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//获取帮助
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				help();
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(0, 0, 70, 30);
		}
	}
	getchar();
	closegraph();

}

//商品子菜单
void CommodityDataMenu()
{
	CommodityNode* head = NULL;
	system("cls");

	MOUSEMSG m;//定义鼠标变量 m
	//菜单
	//initgraph(1000, 500);
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(390, 450, 590, 480);
	fillrectangle(0, 0, 100, 30);
	fillrectangle(880, 0, 980, 30);


	settextcolor(BLACK);//设置字体颜色为黑色
	settextstyle(45, 0, _T("楷体"));
	outtextxy(215, 70, _T("超市销售业绩信息管理系统"));//超市坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(445, 158, _T("输入商品信息"));
	outtextxy(445, 208, _T("删除商品信息"));
	outtextxy(445, 258, _T("修改商品信息"));
	outtextxy(445, 308, _T("查询商品信息"));
	outtextxy(445, 358, _T("浏览商品信息"));
	outtextxy(460, 408, _T("商品排序"));
	outtextxy(465, 458, _T("主菜单"));
	outtextxy(20, 8, _T("退出系统"));
	outtextxy(890, 8, _T("系统初始化"));

	while (1)
	{

		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//如果点击了输入
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				CommodityInput();

				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//如果点击了删除
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				head = CommodityRead();
				head = CommodityDel(head);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//点击了修改
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				
				head = CommodityRead();
				head = CommodityModify(head);
				CommoditySave(head);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//点击了查询
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				int location = 0;
				head = CommodityRead();
				CommoditySearch(head);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//点击了输出
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				head = CommodityRead();
				CommodityOutput(head);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请按任意键继续" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				_getch();

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//点击了排序
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = CommodityRead();
				CommoditySelectionSort(head);
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 450 && m.y <= 480)
		{
			setlinecolor(RED);
			rectangle(385, 445, 595, 485);
			//返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();//返回主菜单
			}
		}
		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);
				return;
			}
		}

		else if (m.x >= 880 && m.x <= 980 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(880, 0, 980, 30);
			//系统初始化
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = CommodityInit(head);
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		else {
			setlinecolor(WHITE);
			rectangle(385, 145, 595, 185);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(385, 345, 595, 385);
			rectangle(385, 395, 595, 435);
			rectangle(385, 445, 595, 485);
			rectangle(0, 0, 100, 30);
			rectangle(880, 0, 980, 30);
		}
	}
	getchar();
	closegraph();
}

//员工子菜单
void StaffDataMenu()
{
	StaffNode* head = NULL;
	system("cls");

	MOUSEMSG m;//定义鼠标变量 m
	//菜单
	//initgraph(1000, 500);
	initgraph(980, 500); //定义画布大小也就是黑框大小

	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls)
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(390, 450, 590, 480);
	fillrectangle(0, 0, 100, 30);
	fillrectangle(880, 0, 980, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("楷体"));
	outtextxy(215, 70, _T("超市销售业绩信息管理系统"));//超市坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景

	outtextxy(445, 158, _T("输入员工信息"));
	outtextxy(445, 208, _T("删除员工信息"));
	outtextxy(445, 258, _T("修改员工信息"));
	outtextxy(445, 308, _T("查询员工信息"));
	outtextxy(445, 358, _T("浏览员工信息"));
	outtextxy(460, 408, _T("员工排序"));
	outtextxy(465, 458, _T("主菜单"));
	outtextxy(20, 8, _T("退出系统"));
	outtextxy(890, 8, _T("系统初始化"));

	while (1)
	{
		//
		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{//
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//如果点击了输入
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				StaffInput();

				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//如果点击了删除
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				head = StaffRead(head);
				head = StaffDel(head);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//点击了修改
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				head = StaffRead(head);
				head = StaffModify(head);
				StaffSave(head);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//点击了查询
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				head = StaffRead(head);
				Staffearch(head);

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//点击了输出
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				head = StaffRead(head);
				StaffOutput(head);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//紫色
				cout << "请按任意键继续" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//黑色
				_getch();

				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//点击了排序
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = StaffRead(head);
				StaffSelectionSort(head);
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 450 && m.y <= 480)
		{
			setlinecolor(RED);
			rectangle(385, 445, 595, 485);

			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();//返回主菜单
			}
		}
		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);//退出系统

			}
		}

		else if (m.x >= 880 && m.x <= 980 && m.y >= 0 && m.y <= 30)
		{
		setlinecolor(RED);
		rectangle(880, 0, 980, 30);
		//系统初始化
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			closegraph();
			head = StaffInit(head);
			system("cls");
			FlushMouseMsgBuffer();//清空鼠标消息缓存区
			StaffDataMenu();

		}
		}
		else {
			setlinecolor(WHITE);
			rectangle(385, 145, 595, 185);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(385, 345, 595, 385);
			rectangle(385, 395, 595, 435);
			rectangle(385, 445, 595, 485);
			rectangle(0, 0, 100, 30);
			rectangle(880, 0, 980, 30);
		}
	}
	getchar();
	closegraph();

}

//商品输入子菜单的实现
void CommodityInput()
{
	CommodityNode* head = NULL;
	system("cls");

	MOUSEMSG m;//定义鼠标变量 m
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(0, 0, 100, 30);


	settextcolor(BLACK);
	settextstyle(45, 0, _T("楷体"));
	outtextxy(215, 70, _T("超市销售业绩信息管理系统"));//超市坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(445, 208, _T("创建商品信息"));
	outtextxy(445, 258, _T("增加商品信息"));
	outtextxy(440, 308, _T("返回上一级菜单"));
	outtextxy(450, 358, _T("返回主菜单"));
	outtextxy(20, 8, _T("退出系统"));

	while (1)
	{
		//获取鼠标消息
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//画出红色的矩形框线
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//进入创建信息
			if (m.uMsg == WM_LBUTTONDOWN) //鼠标左键点击消息
			{
				closegraph();

				head = CommodityCreate(head);
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//进入增加信息
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = CommodityRead();
				head = CommodityAdd(head);
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//返回上一级菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				CommodityDataMenu();//返回上一级菜单
			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}

		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);//退出系统

			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(385, 345, 595, 385);
			rectangle(0, 0, 100, 30);
		}
	}
	getchar();
	closegraph();
}

//员工输入子菜单的实现
void StaffInput()
{
	StaffNode* head = NULL;
	system("cls");

	MOUSEMSG m;//定义鼠标变量 m
	initgraph(980, 500); //定义画布大小也就是黑框大小
	setbkcolor(0xAFEEEE);//设置背景颜色 用与RGB相对应的16进制代码表示
	cleardevice();//刷新一次 略等于那个system(cls) 用当前背景色清空屏幕
	setfillcolor(0x9AFF9A);//设置后面用函数画出方框的背景颜色
	//           左边1 高1 左边2 高2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(0, 0, 100, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("楷体"));
	outtextxy(215, 70, _T("超市销售业绩信息管理系统"));//超市坐标

	settextstyle(15, 0, _T("楷体"));//设置文字格式
	setbkmode(TRANSPARENT);// 去掉文字背景
	outtextxy(445, 208, _T("创建员工信息"));
	outtextxy(445, 258, _T("增加员工信息"));
	outtextxy(440, 308, _T("返回上一级菜单"));
	outtextxy(450, 358, _T("返回主菜单"));
	outtextxy(20, 8, _T("退出系统"));

	while (1)
	{
		//获取鼠标消息
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//画出红色的矩形框线
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//进入创建信息
			if (m.uMsg == WM_LBUTTONDOWN) //鼠标左键点击消息
			{
				closegraph();

				head = StaffCreate(head);
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//进入增加信息
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = StaffRead(head);
				head = StaffAdd(head);
				system("cls");
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//返回上一级菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				StaffDataMenu();//返回上一级菜单
			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//返回主菜单
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				menu();

			}
		}
		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//退出系统
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//清空鼠标消息缓存区
				exit(1);//退出系统

			}
		}
		else
		{
			setlinecolor(WHITE);
			rectangle(385, 195, 595, 235);
			rectangle(385, 245, 595, 285);
			rectangle(385, 295, 595, 335);
			rectangle(385, 345, 595, 385);
			rectangle(0, 0, 100, 30);
		}
	}
	getchar();
	closegraph();
}


