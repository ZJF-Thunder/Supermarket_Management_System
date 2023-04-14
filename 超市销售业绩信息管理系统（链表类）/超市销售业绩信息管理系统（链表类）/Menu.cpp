#include "Commodity.h"
#include "Staff.h"
#include "Menu.h"
#include "Help.h"
#include<Graphics.h>
#include<easyx.h>
#include<conio.h>
#include<iostream>
using namespace std;

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
				StaffDataMenu();
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
	CommodityNode* head = NULL;
	system("cls");

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
	fillrectangle(880, 0, 980, 30);


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
	outtextxy(890, 8, _T("ϵͳ��ʼ��"));

	while (1)
	{

		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//������������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				CommodityInput();

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

				head = CommodityRead();
				head = CommodityDel(head);

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
				
				head = CommodityRead();
				head = CommodityModify(head);
				CommoditySave(head);

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

				int location = 0;
				head = CommodityRead();
				CommoditySearch(head);

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

				head = CommodityRead();
				CommodityOutput(head);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�밴���������" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				_getch();

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
			//���������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = CommodityRead();
				CommoditySelectionSort(head);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 450 && m.y <= 480)
		{
			setlinecolor(RED);
			rectangle(385, 445, 595, 485);
			//�������˵�
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

		else if (m.x >= 880 && m.x <= 980 && m.y >= 0 && m.y <= 30)
		{
			setlinecolor(RED);
			rectangle(880, 0, 980, 30);
			//ϵͳ��ʼ��
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = CommodityInit(head);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
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

//Ա���Ӳ˵�
void StaffDataMenu()
{
	StaffNode* head = NULL;
	system("cls");

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
	fillrectangle(880, 0, 980, 30);

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
	outtextxy(890, 8, _T("ϵͳ��ʼ��"));

	while (1)
	{
		//
		m = GetMouseMsg();

		if (m.x >= 390 && m.x <= 590 && m.y >= 150 && m.y <= 180)
		{//
			setlinecolor(RED);
			rectangle(385, 145, 595, 185);
			//������������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();

				StaffInput();

				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();

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

				head = StaffRead(head);
				head = StaffDel(head);

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();

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

				head = StaffRead(head);
				head = StaffModify(head);
				StaffSave(head);

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();

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

				head = StaffRead(head);
				Staffearch(head);

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();

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

				head = StaffRead(head);
				StaffOutput(head);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�밴���������" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				_getch();

				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 400 && m.y <= 430)
		{//
			setlinecolor(RED);
			rectangle(385, 395, 595, 435);
			//���������
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = StaffRead(head);
				StaffSelectionSort(head);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
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

		else if (m.x >= 880 && m.x <= 980 && m.y >= 0 && m.y <= 30)
		{
		setlinecolor(RED);
		rectangle(880, 0, 980, 30);
		//ϵͳ��ʼ��
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			closegraph();
			head = StaffInit(head);
			system("cls");
			FlushMouseMsgBuffer();//��������Ϣ������
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

//��Ʒ�����Ӳ˵���ʵ��
void CommodityInput()
{
	CommodityNode* head = NULL;
	system("cls");

	MOUSEMSG m;//���������� m
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(0, 0, 100, 30);


	settextcolor(BLACK);
	settextstyle(45, 0, _T("����"));
	outtextxy(215, 70, _T("��������ҵ����Ϣ����ϵͳ"));//��������

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(445, 208, _T("������Ʒ��Ϣ"));
	outtextxy(445, 258, _T("������Ʒ��Ϣ"));
	outtextxy(440, 308, _T("������һ���˵�"));
	outtextxy(450, 358, _T("�������˵�"));
	outtextxy(20, 8, _T("�˳�ϵͳ"));

	while (1)
	{
		//��ȡ�����Ϣ
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//������ɫ�ľ��ο���
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//���봴����Ϣ
			if (m.uMsg == WM_LBUTTONDOWN) //�����������Ϣ
			{
				closegraph();

				head = CommodityCreate(head);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//����������Ϣ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = CommodityRead();
				head = CommodityAdd(head);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//������һ���˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				CommodityDataMenu();//������һ���˵�
			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//�������˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();

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

//Ա�������Ӳ˵���ʵ��
void StaffInput()
{
	StaffNode* head = NULL;
	system("cls");

	MOUSEMSG m;//���������� m
	initgraph(980, 500); //���廭����СҲ���Ǻڿ��С
	setbkcolor(0xAFEEEE);//���ñ�����ɫ ����RGB���Ӧ��16���ƴ����ʾ
	cleardevice();//ˢ��һ�� �Ե����Ǹ�system(cls) �õ�ǰ����ɫ�����Ļ
	setfillcolor(0x9AFF9A);//���ú����ú�����������ı�����ɫ
	//           ���1 ��1 ���2 ��2
	fillrectangle(390, 200, 590, 230);
	fillrectangle(390, 250, 590, 280);
	fillrectangle(390, 300, 590, 330);
	fillrectangle(390, 350, 590, 380);
	fillrectangle(0, 0, 100, 30);

	settextcolor(BLACK);
	settextstyle(45, 0, _T("����"));
	outtextxy(215, 70, _T("��������ҵ����Ϣ����ϵͳ"));//��������

	settextstyle(15, 0, _T("����"));//�������ָ�ʽ
	setbkmode(TRANSPARENT);// ȥ�����ֱ���
	outtextxy(445, 208, _T("����Ա����Ϣ"));
	outtextxy(445, 258, _T("����Ա����Ϣ"));
	outtextxy(440, 308, _T("������һ���˵�"));
	outtextxy(450, 358, _T("�������˵�"));
	outtextxy(20, 8, _T("�˳�ϵͳ"));

	while (1)
	{
		//��ȡ�����Ϣ
		m = GetMouseMsg();
		if (m.x >= 390 && m.x <= 590 && m.y >= 200 && m.y <= 230)
		{
			//������ɫ�ľ��ο���
			setlinecolor(RED);
			rectangle(385, 195, 595, 235);
			//���봴����Ϣ
			if (m.uMsg == WM_LBUTTONDOWN) //�����������Ϣ
			{
				closegraph();

				head = StaffCreate(head);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 250 && m.y <= 280)
		{
			setlinecolor(RED);
			rectangle(385, 245, 595, 285);
			//����������Ϣ
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				head = StaffRead(head);
				head = StaffAdd(head);
				system("cls");
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();

			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 300 && m.y <= 330)
		{
			setlinecolor(RED);
			rectangle(385, 295, 595, 335);
			//������һ���˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				StaffDataMenu();//������һ���˵�
			}
		}
		else if (m.x >= 390 && m.x <= 590 && m.y >= 350 && m.y <= 380)
		{
			setlinecolor(RED);
			rectangle(385, 345, 595, 385);
			//�������˵�
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				closegraph();
				FlushMouseMsgBuffer();//��������Ϣ������
				menu();

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


