#ifndef _MENU_//����ͷ�ļ����ظ�����
#define _MENU_
#include"Class.h"
#include"Menu.h"
#include"Help.h"
#include<Graphics.h>
#include<easyx.h>
#include<conio.h>
#include<iostream>
#endif
using namespace std;
void CommodityDataMenu();//��Ʒ�˵�������
void StaffMenu();//Ա���˵�������

//�˵�
void menu()
{
	MOUSEMSG m;//���������� m
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(0, 0, 70, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("����"));
	outtextxy(215, 70, _T("��������ҵ����Ϣ����ϵͳ"));//��������

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(460, 208, _T("��Ʒϵͳ"));
	outtextxy(460, 258, _T("Ա��ϵͳ"));
	outtextxy(460, 308, _T("�˳�ϵͳ"));
	outtextxy(20, 8, _T("����"));
	while (1)
	{
		//��ȡ�����Ϣ
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//������ɫ�ľ��ο���
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//������Ʒ�Ӳ˵�
			if (m.uMsg == WM_LBUTTONDOWN) //�����������Ϣ
			{
				closegraph();
				CommodityDataMenu();
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();			

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//����Ա���Ӳ˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				StaffMenu();
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//�˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				exit(1);//�˳�ϵͳ
			}
		}
		else if (m.x >= 0 && m.x <= 70 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(0, 0, 70, 30);
			//��ȡ����
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				help();
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
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

//��Ʒ�Ӳ˵�
void CommodityDataMenu()
{
	int b = 0;//��Ʒ�����鳤��
	CommodityData* co = new CommodityData;//��̬������Ʒ�����
	Commodity* Cd = new Commodity[MAX];//��Ʒ����
	Commodity* t = new Commodity; //������ʱ��Ʒ

	MOUSEMSG m;//���������� m
	//�˵�
	//initgraph(1000, 500);
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(390, 450, 590, 480);
	fillrectangle(0, 0, 100, 30);


	settextcolor(BLACK);//����������ɫΪ��ɫ
	settextstyle(45, 0, _T("����"));
	outtextxy(215, 70, _T("��������ҵ����Ϣ����ϵͳ"));//��������

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(445, 158, _T("������Ʒ��Ϣ"));
	outtextxy(445, 208, _T("ɾ����Ʒ��Ϣ"));
	outtextxy(445, 258, _T("�޸���Ʒ��Ϣ"));
	outtextxy(445, 308, _T("��ѯ��Ʒ��Ϣ"));
	outtextxy(445, 358, _T("�����Ʒ��Ϣ"));
	outtextxy(460, 408, _T("��Ʒ����"));
	outtextxy(465, 458, _T("���˵�"));
	outtextxy(20, 8, _T("�˳�ϵͳ"));


	while (1)
	{
		
		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//�����������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				co->input(co, Cd, b); //������Ʒ��Ϣ
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}

		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//��������ɾ��
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				co->del(co);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//������޸�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				co->modify(co);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//����˲�ѯ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				co->search(co);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//��������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				co->output(co);//������������Ʒ��Ϣ
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);

			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				co->selectionSort(co, t);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 450 && m.y <= 480)
		{
			setlinecolor(RED);
			rectangle(385, 445, 595, 485);

			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();//�������˵�
			}
		}
		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//�˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				exit(1);
				return;
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
		}
	}
	getchar();
	closegraph();
	delete co;//�ͷŶ�̬����
	delete[]Cd;//�ͷŶ�̬����
}

//Ա���Ӳ˵�
void StaffMenu()
{
	int n = 0;//Ա�������鳤��
	StaffData* st = new StaffData;//��̬����Ա�������
	Staff* St = new Staff[MAX];//Ա������
	Staff* temp = new Staff; //������ʱԱ��
	MOUSEMSG m;//���������� m
	//�˵�
	//initgraph(1000, 500);
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С

	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls)
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 150, 590, 180);
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(390, 400, 590, 430);
	fillrectangle(390, 450, 590, 480);
	fillrectangle(0, 0, 100, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("����"));
	outtextxy(215, 70, _T("��������ҵ����Ϣ����ϵͳ"));//��������

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���

	outtextxy(445, 158, _T("����Ա����Ϣ"));
	outtextxy(445, 208, _T("ɾ��Ա����Ϣ"));
	outtextxy(445, 258, _T("�޸�Ա����Ϣ"));
	outtextxy(445, 308, _T("��ѯԱ����Ϣ"));
	outtextxy(445, 358, _T("���Ա����Ϣ"));
	outtextxy(460, 408, _T("Ա������"));
	outtextxy(465, 458, _T("���˵�"));
	outtextxy(20, 8, _T("�˳�ϵͳ"));
	while (1)
	{
		//
		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{//
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//�����������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				st->input(st, St, n); //������Ʒ��Ϣ
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//��������ɾ��
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				st->del(st);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//������޸�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				st->modify(st);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//����˲�ѯ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				st->search(st);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffMenu();

			}
		}
		//
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//��������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				st->output(st);//������������Ʒ��Ϣ
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);

			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				st->selectionSort(st, temp);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 450 && m.y <= 480)
		{
			setlinecolor(RED);
			rectangle(385, 445, 595, 485);

			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				menu();//�������˵�
			}
		}
		else if (m.x >= 0 && m.x <= 100 && m.y >= 0 && m.y <= 30)
		{//
			setlinecolor(RED);
			rectangle(0, 0, 100, 30);
			//�˳�ϵͳ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				exit(1);//�˳�ϵͳ

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
		}
	}
	getchar();
	closegraph();
	delete st;//�ͷŶ�̬����
	delete[]St;//�ͷŶ�̬����
}