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

//������ 
int main()
{
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	IMAGE img;
	loadimage(&img, _T("����.jpg"), 980, 500);
	putimage(0, 0, &img);    // ����һ���ط��ٴ���ʾ����
	setbkmode(TRANSPARENT);
	settextstyle(40, 0, _T("����"));
	settextcolor(0x9AFF9A);
	outtextxy(230, 220, _T("��������ҵ����Ϣ����ϵͳ"));//��������
	_getch();        // ��������˳�
	closegraph();    // �ر�ͼƬ

	system("color B0");   //���ñ�������������ɫ
	Password pass;//��¼����
	pass.input_code();
	menu();//���ò˵����� 
	system("pause");
	return 0;
}