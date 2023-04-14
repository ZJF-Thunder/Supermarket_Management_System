//Main.cpp 
#pragma once
#include"Menu.h"
#include"PassWord.h"
#include<stdio.h>
#include<Graphics.h>
#include<easyX.h>
#include<conio.h>
#include<iostream>
using namespace std;

//主函数 
int main()
{
	initgraph(980, 500); //定义画布大小也就是黑框大小
	IMAGE img;
	loadimage(&img, _T("背景.jpg"), 980, 500);
	putimage(0, 0, &img);    // 在另一个地方再次显示背景
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("黑体"));
	settextcolor(0x9AFF9A);
	outtextxy(230, 220, _T("超市销售业绩信息管理系统"));//超市坐标
	_getch();        // 按任意键退出
	closegraph();    // 关闭图片

	system("color B0");   //设置背景及其字体颜色
	Password pass;//登录密码
	pass.input_code();
	menu();//调用菜单函数 
	system("pause");
	return 0;
}