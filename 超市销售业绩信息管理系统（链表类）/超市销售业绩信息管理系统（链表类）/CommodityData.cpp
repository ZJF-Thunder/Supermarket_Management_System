//#define _CRT_SECURE_NO_WARNNINGS //���⾯��
#include "Commodity.h"
#include<iostream>
#include<windows.h>//����̨�����Ҫͷ�ļ�
#include<iomanip>//�õ�setw()����
#include<conio.h>//_getch()
#include<string.h>
using namespace std;

//�����ļ�����   ������������ݵ��ļ���
bool CommoditySave(CommodityNode* head)
{
	CommodityNode* p = NULL;//��ָ��p����ָ������������
	FILE* fp;        //�����ļ�����ָ��
	int i = 0;
	char isSave[10] = "0";//�Ƿ񱣴����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "�Ƿ񱣴棿(Y/N):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> isSave;
	while (strcmp(isSave, "Y") != 0 && strcmp(isSave, "y") != 0 && strcmp(isSave, "N") != 0 && strcmp(isSave, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�����������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> isSave;
	}

	if (strcmp(isSave, "N") == 0 || strcmp(isSave, "n") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	else if (strcmp(isSave, "Y") == 0 || strcmp(isSave, "y") == 0)
	{
		fopen_s(&fp, "./CommodityData.txt", "w+");
		if (fp == NULL)
		//if (!fp)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "�����ļ�ʧ��!" << endl;
			return 0;
		}
		i = 0;
		//��ÿ����Ʒ��Ϣд���ļ�
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
			p = p->next; //ָ��ָ����һ���ڵ�
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "������" << i << "����Ʒ����Ϣ���ļ��У�" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		fclose(fp);
		return 1;
	}
}


//��ȡ���ݺ���   ��ȡ�ļ��е����ݵ��ڴ���
CommodityNode* CommodityRead()
{
	CommodityNode* head = NULL;  //ͷָ��
	CommodityNode* p1 = NULL;  //��ָ��pָ��Ҫ������½��
	CommodityNode* p2 = NULL;  //��ָ��pָ��Ҫ������½��
	FILE* fp;               //�����ļ�����ָ��
	int i = 0;//ѭ������
	fopen_s(&fp, "CommodityData.txt", "r");
	if (fp == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "��ȡ�ļ�ʧ��!\n" << endl;
		return 0;
	}
	while (!feof(fp)) //��ʾû��ָ���ļ�ĩβ��ûָ��ĩβΪ0
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "����ȡ" << i << "����Ʒ����Ϣ���ڴ��У�" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	fclose(fp);
	return head;
}

//��Ʒ���ݳ�ʼ��
CommodityNode* CommodityInit(CommodityNode* head)
{
	head = NULL;
	CommodityNode* p1 = NULL;
	CommodityNode* p2 = NULL;
	int i = 0;

	cout << "��Ʒϵͳ��ʼ����" << endl;
	p1 = new CommodityNode;
	strcpy(p1->data.commodityNumber , "001");
	strcpy(p1->data.commodityName, "�ײ�");
	strcpy(p1->data.commodityClass, "�߲���");
	strcpy(p1->data.commodityPlaceOfOrigin, "����");
	strcpy(p1->data.commodityManufacturer, "���г�");
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
	strcpy(p1->data.commodityName, "����");
	strcpy(p1->data.commodityClass, "����");
	strcpy(p1->data.commodityPlaceOfOrigin, "����");
	strcpy(p1->data.commodityManufacturer, "���г�");
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
	strcpy(p1->data.commodityName, "����");
	strcpy(p1->data.commodityClass, "��ʳ��");
	strcpy(p1->data.commodityPlaceOfOrigin, "����");
	strcpy(p1->data.commodityManufacturer, "����");
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
	strcpy(p1->data.commodityName, "����");
	strcpy(p1->data.commodityClass, "��ʳ");
	strcpy(p1->data.commodityPlaceOfOrigin, "����");
	strcpy(p1->data.commodityManufacturer, "������");
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
	cout << "��Ʒϵͳ��ʼ���ɹ���" << endl;
	cout << "�밴���������" << endl;
	_getch();
	return head;
}

//������Ʒ��Ϣ
CommodityNode* CommodityCreate(CommodityNode* head)
{
	head = NULL;
	CommodityNode* p1 = NULL;
	CommodityNode* p2 = NULL;
	int i = 0;//ѭ������
	int m = 0;//��Ʒ������
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******��ȷ���Ƿ�Ϊ�������(Y or N)*******" << endl;
	cout << "\t\t                       *******       �� Y �������˵�        *******" << endl;
	cout << "\t\t                        *******       �� N ��������        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       ����������ѡ��:";
	char b[10] = "0";//ȷ�����������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> b;
	while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�����������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0)
	{

		cout << "��������Ҫ�������Ʒ����:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> m;
		system("cls");//���� 

		if (m == 0)
		{
			return 0;
		}

		//����Ϊ�ռ��޽��ʱ��p0��Ϊ����ĵ�һ�����
		for (int i = 0; i < m; i++)
		{

			p1 = new CommodityNode;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "�������" << i + 1 << "����Ʒ�ı��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityClass;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ĳ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPlaceOfOrigin;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityManufacturer;
			//��һ����֤�Ƿ��ʽ������ȷ�Ļ���
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ľ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPurchasePrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ���ۼ�:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ľ�������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPurchaseQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commoditySoldQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ŀ������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityInventoryQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ŀ����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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
		p2->next = NULL;//������־

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "������" << m << "����Ʒ����Ϣ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		CommoditySave(head); //�������ݵ��ļ���
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	return head;
}


//������Ʒ����Ϣ
CommodityNode* CommodityAdd(CommodityNode *head)
{
	CommodityNode* p1 = NULL;
	CommodityNode* p2 = NULL;
	int i = 0;//ѭ������
	int m = 0;//��Ʒ������

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******��ȷ���Ƿ�Ϊ�������(Y or N)*******" << endl;
	cout << "\t\t                       *******       �� Y �������˵�        *******" << endl;
	cout << "\t\t                        *******       �� N ��������        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       ����������ѡ��:";
	char b[10] = "0";//ȷ�����������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> b;
	while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�����������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0)
	{

		cout << "��������Ҫ�������Ʒ����:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> m;
		system("cls");//���� 

		if (m == 0)
		{
			return 0;
		}

		p2 = head;
		while (p2->next != NULL)//�ж��Ƿ�Ϊ��β����β�ı�־Ϊp2->next == NULL
		{
			p2 = p2->next;
		}

		for (int i = 0; i < m; i++)
		{

			p1 = new CommodityNode;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "�������" << i + 1 << "����Ʒ�ı��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityClass;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ĳ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPlaceOfOrigin;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityManufacturer;
			//��һ����֤�Ƿ��ʽ������ȷ�Ļ���
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ľ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPurchasePrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ���ۼ�:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPrice;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ľ�������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityPurchaseQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commoditySoldQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ŀ������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityInventoryQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "��Ʒ�Ŀ����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.commodityInventoryAmount;
			cout << endl;
			p2->next = p1;
			p2 = p1;

		}
		p2->next = NULL;//������־
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "������" << m << "����Ʒ����Ϣ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		CommoditySave(head); //�������ݵ��ļ���
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	return head;

}


//�����Ʒ����Ϣ
void CommodityOutput(CommodityNode* head)
{
	CommodityNode* p = head;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "���" << '\t' << "����" << '\t' << "���" << '\t'
		<< "����" << '\t' << "��������" << '\t' << "����" << '\t'
		<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t'
		<< "�������" << '\t' << "�����" << endl;
	cout << endl;
	if (p == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�ܱ�Ǹ���ļ���û����Ʒ��Ϣ�����������Ʒ��Ϣ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�밴���������" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		_getch();
		return ;
	}
	while (p != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
		p = p->next;//ָ����һ�����
	}

	cout << endl;
}


//��Ʒɾ��ģ��
CommodityNode* CommodityDel(CommodityNode* head)
{
	CommodityOutput(head);
	int i = 0;//���ڱ����ҵ�����ѯ��Ϣλ��
	int k = 0;//�����ж��Ƿ��д���Ʒ
	CommodityNode* q;//��ѭ�����
	CommodityNode* p = head;//ָ�����ָ��
	if (p == NULL)
		return 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	char choose[10] = "0";//����һ��ѡ���ַ�
	cout << "\t\t                           *****************************" << endl;
	cout << "\t\t                          *******   ��ѡ��ɾ������:  *******" << endl;
	cout << "\t\t                        *******     1-->����Ʒ���    *******" << endl;
	cout << "\t\t                       *******      2-->����Ʒ����     *******" << endl;
	cout << "\t\t                      *******       3-->����Ʒ���      *******" << endl;
	cout << "\t\t                       *******      4-->������         *******" << endl;
	cout << "\t\t                        *******     5-->����������    *******" << endl;
	cout << "\t\t                         *******    6-->�������˵�   *******" << endl;
	cout << "\t\t                           *****************************" << endl;
	cout << "\t\t                      ����������ѡ��1-6��:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> choose;
	while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0 && strcmp(choose, "4") != 0 && strcmp(choose, "5") != 0 && strcmp(choose, "6") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                   ����������������루1-6��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> choose;
	}
	system("cls");//���� 
	if (strcmp(choose, "1") == 0)
	{
		char Cnum[8];//��Ҫɾ������Ʒ��� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t  ����������Ҫɾ������Ʒ���:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Cnum;//������Ҫɾ������Ʒ���
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Cnum, p->data.commodityNumber) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
			{
				int j = 1;
				if (i == 1)//��ɾ�������ǵ�һ��ʱ
				{
					head = p->next;
					i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//��ɾ��λ�õ�ǰһλ
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//��¼qָ��ָ��λ�ã�������i�Ա��ҵ�����в����ĵط�
					}
				}
				k++;//�ж��Ƿ�����ɾ����Ϣ����
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                       *************     ����Ʒ�����ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t           *************       �ɹ�ɾ�����Ϊ" << Cnum << "��" << k << "����Ʒ��Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "2") == 0)
	{
		char Cname[20];//��Ҫɾ������Ʒ���� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t  ����������Ҫɾ������Ʒ����:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Cname;//������Ҫɾ������Ʒ����
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Cname, p->data.commodityName) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
			{
				int j = 1;
				if (i == 1)//��ɾ�������ǵ�һ��ʱ
				{
					head = p->next;
					i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//��ɾ��λ�õ�ǰһλ
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//��¼qָ��ָ��λ�ã�������i�Ա��ҵ�����в����ĵط�
					}
				}
				k++;//�ж��Ƿ�����ɾ����Ϣ����
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                       *************     ����Ʒ�����ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t           *************       �ɹ�ɾ������Ϊ" << Cname << "��" << k << "����Ʒ��Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "3") == 0)
	{
		char Ccla[20];//��Ҫɾ������Ʒ��� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t  ����������Ҫɾ������Ʒ���:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Ccla;//������Ҫɾ������Ʒ���
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Ccla, p->data.commodityClass) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
			{
				int j = 1;
				if (i == 1)//��ɾ�������ǵ�һ��ʱ
				{
					head = p->next;
					i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//��ɾ��λ�õ�ǰһλ
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//��¼qָ��ָ��λ�ã�������i�Ա��ҵ�����в����ĵط�
					}
				}
				k++;//�ж��Ƿ�����ɾ����Ϣ����
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                       *************     ����Ʒ�����ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t           *************       �ɹ�ɾ�����Ϊ" << Ccla << "��" << k << "����Ʒ��Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "4") == 0)
	{
		char Cpla[10];//��Ҫɾ������Ʒ���� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t  ����������Ҫɾ������Ʒ����:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Cpla;//������Ҫɾ������Ʒ����
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Cpla, p->data.commodityPlaceOfOrigin) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
			{
				int j = 1;
				if (i == 1)//��ɾ�������ǵ�һ��ʱ
				{
					head = p->next;
					i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//��ɾ��λ�õ�ǰһλ
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//��¼qָ��ָ��λ�ã�������i�Ա��ҵ�����в����ĵط�
					}
				}
				k++;//�ж��Ƿ�����ɾ����Ϣ����
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                       *************     ����Ʒ�����ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t           *************       �ɹ�ɾ������Ϊ" << Cpla << "��" << k << "����Ʒ��Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "5") == 0)
	{
		char Cman[20];//��Ҫɾ������Ʒ�������� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t  ����������Ҫɾ������Ʒ��������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Cman;//������Ҫɾ������Ʒ��������
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Cman, p->data.commodityManufacturer) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
			{
				int j = 1;
				if (i == 1)//��ɾ�������ǵ�һ��ʱ
				{
					head = p->next;
					i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
				}
				else
				{
					q = head;
					while (q != NULL)
					{
						if (j + 1 == i)//��ɾ��λ�õ�ǰһλ
						{
							if (q->next->next != NULL)
							{
								q->next = q->next->next;
								i--;//ɾ�����¼λ�ü�һ������֮��ɾ��λ�õ���ȷ
							}
							else
							{
								q->next = NULL;
							}
						}
						q = q->next;
						j++;//��¼qָ��ָ��λ�ã�������i�Ա��ҵ�����в����ĵط�
					}
				}
				k++;//�ж��Ƿ�����ɾ����Ϣ����
			}
			p = p->next;
		}
		if (k == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                       *************     ����Ʒ�����ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t          *************       �ɹ�ɾ����������Ϊ" << Cman << "��" << k << "����Ʒ��Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "6") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (k > 0)
		CommoditySave(head); //�������ݵ��ļ���

	char choi[10] = "0";
	i = 0; //�����ж���ѡ���Ƿ��������ʱ��ѡ���Ƿ����
	while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
	{
		if (i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "\t\t                                     �Ƿ����룡���������룡" << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                           *******    �Ƿ����ɾ����Ʒ��  *******" << endl;
		cout << "\t\t                          *******       Y-->����ɾ��       *******" << endl;
		cout << "\t\t                           *******      N-->�������˵�    *******" << endl;
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                          ����������ѡ��(Y or N):";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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
	cout << "�޸�ǰ��Ʒ��ţ�" << p->data.commodityNumber << endl;
	cout << "��������Ʒ���:";
	cin >> p->data.commodityNumber;
	cout << "�޸�ǰ��Ʒ���ƣ�" << p->data.commodityName << endl;
	cout << "��������Ʒ����:";
	cin >> p->data.commodityName;
	cout << "�޸�ǰ��Ʒ���" << p->data.commodityClass << endl;
	cout << "��������Ʒ���:";
	cin >> p->data.commodityClass;
	cout << "�޸�ǰ���أ�" << p->data.commodityPlaceOfOrigin << endl;
	cout << "���������:";
	cin >> p->data.commodityPlaceOfOrigin;
	cout << "�޸�ǰ�������ң�" << p->data.commodityManufacturer << endl;
	cout << "��������������:";
	cin >> p->data.commodityManufacturer;
	cout << "�޸�ǰ��Ʒ���ۣ�" << p->data.commodityPurchasePrice << endl;
	cout << "��������Ʒ����:";
	cin >> p->data.commodityPurchasePrice;
	cout << "�޸�ǰ��Ʒ�ۼۣ�" << p->data.commodityPrice << endl;
	cout << "��������Ʒ�ۼ�:";
	cin >> p->data.commodityPrice;
	cout << "�޸�ǰ��Ʒ����������" << p->data.commodityPurchaseQuantity << endl;
	cout << "��������Ʒ��������:";
	cin >> p->data.commodityPurchaseQuantity;
	cout << "�޸�ǰ��Ʒ����������" << p->data.commoditySoldQuantity << endl;
	cout << "��������Ʒ��������:";
	cin >> p->data.commoditySoldQuantity;
	cout << "�޸�ǰ��Ʒ���������" << p->data.commodityInventoryQuantity << endl;
	cout << "��������Ʒ�������:";
	cin >> p->data.commodityInventoryQuantity;
	cout << "�޸�ǰ��Ʒ����" << p->data.commodityInventoryAmount << endl;
	cout << "��������Ʒ�����:";
	cin >> p->data.commodityInventoryAmount;
}*/


//�޸���Ʒ����Ϣ
CommodityNode* CommodityModify(CommodityNode* head)
{//1
	CommodityOutput(head);
	CommodityNode* p = NULL;
	char Name[20] = "0";
	char Number[8] = "0";
	char H = '0';
	char f[5] = "0";
	int i = 0;//��������Ҫ�޸ĵ���Ʒ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                        *******��ѡ����Ҫ��ѯ�ķ�ʽ��*******" << endl;
	cout << "\t\t                       *******      1-->����Ų�ѯ    *******" << endl;
	cout << "\t\t                       *******      2-->�����Ʋ�ѯ    *******" << endl;
	cout << "\t\t                        *******     3-->�������˵�   *******" << endl;
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                      ����������ѡ��(1-3):";
	char b[10] = "0";//ȷ�����������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> b;
	while (strcmp(b, "1") != 0 && strcmp(b, "2") != 0 && strcmp(b, "3") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�����������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(b, "1") == 0)
	{
		cout << "����������Ҫ�޸���Ʒ���" << endl;
		cin >> Number;
		system("cls");
		if (head == NULL)//����ǿ�����
		{
			cout << "����Ʒ��Ϣ��" << endl;
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t        ����Ʒ������!" << endl;
			CommodityModify(head);
		}
		else
		{
			cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
				<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			cout << "\t\t                        *******��ѡ����Ҫ�޸ĵķ�ʽ��*******" << endl;
			cout << "\t\t                       *******      1-->ȫ���޸�      *******" << endl;
			cout << "\t\t                        *******     2-->�ֲ��޸�     *******" << endl;
			cout << "\t\t                           ******************************" << endl;
			cout << "\t\t                       ����������ѡ��(1-2):";
			cin >> H;
			switch (H)
			{
			case '1':
				//����޸�ȫ���޸�����
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�޸�ǰ��Ʒ��ţ�" << p->data.commodityNumber << endl;
				cout << "��������Ʒ���:";
				cin >> p->data.commodityNumber;
				cout << "�޸�ǰ��Ʒ���ƣ�" << p->data.commodityName << endl;
				cout << "��������Ʒ����:";
				cin >> p->data.commodityName;
				cout << "�޸�ǰ��Ʒ���" << p->data.commodityClass << endl;
				cout << "��������Ʒ���:";
				cin >> p->data.commodityClass;
				cout << "�޸�ǰ���أ�" << p->data.commodityPlaceOfOrigin << endl;
				cout << "���������:";
				cin >> p->data.commodityPlaceOfOrigin;
				cout << "�޸�ǰ�������ң�" << p->data.commodityManufacturer << endl;
				cout << "��������������:";
				cin >> p->data.commodityManufacturer;
				cout << "�޸�ǰ��Ʒ���ۣ�" << p->data.commodityPurchasePrice << endl;
				cout << "��������Ʒ����:";
				cin >> p->data.commodityPurchasePrice;
				cout << "�޸�ǰ��Ʒ�ۼۣ�" << p->data.commodityPrice << endl;
				cout << "��������Ʒ�ۼ�:";
				cin >> p->data.commodityPrice;
				cout << "�޸�ǰ��Ʒ����������" << p->data.commodityPurchaseQuantity << endl;
				cout << "��������Ʒ��������:";
				cin >> p->data.commodityPurchaseQuantity;
				cout << "�޸�ǰ��Ʒ����������" << p->data.commoditySoldQuantity << endl;
				cout << "��������Ʒ��������:";
				cin >> p->data.commoditySoldQuantity;
				cout << "�޸�ǰ��Ʒ���������" << p->data.commodityInventoryQuantity << endl;
				cout << "��������Ʒ�������:";
				cin >> p->data.commodityInventoryQuantity;
				cout << "�޸�ǰ��Ʒ����" << p->data.commodityInventoryAmount << endl;
				cout << "��������Ʒ�����:";
				cin >> p->data.commodityInventoryAmount;
				cout << "�޸ĺ���ϢΪ��" << "��Ʒ��ţ�" << p->data.commodityNumber << "��Ʒ���ƣ�" << p->data.commodityName << endl << "��Ʒ���" << p->data.commodityClass << endl << "���أ�" << p->data.commodityPlaceOfOrigin << endl << "���ң�" << p->data.commodityManufacturer << endl << "��Ʒ���ۣ�" << p->data.commodityPurchasePrice << endl << "��Ʒ�ۼۣ�" << p->data.commodityPrice << endl << "��Ʒ����������" << p->data.commodityPurchaseQuantity << endl << "��Ʒ����������" << p->data.commoditySoldQuantity << endl << "��Ʒ���������" << p->data.commodityInventoryQuantity << endl << "��Ʒ����" << p->data.commodityInventoryAmount << endl;
				system("cls");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******�Ƿ�����޸ģ�*******" << endl;
				cout << "\t\t                       *******    1-->��      *******" << endl;
				cout << "\t\t                        *******   2-->��     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       ����������ѡ��(1-2):";
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
					cout << "�����������������!" << endl;
				}
				break;

			case '2':
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "1.��Ʒ���" << endl << "2.��Ʒ����" << endl << "3.��Ʒ���" << endl << "4.����" << endl << "5.��������" << endl << "6.��Ʒ����" << endl << "7.��Ʒ�ۼ�" << endl << "8.��Ʒ��������" << endl << "9.��Ʒ��������" << endl << "10.��Ʒ�������" << endl << "11.��Ʒ�����" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "�޸�ǰ��Ʒ��ţ�" << p->data.commodityNumber << endl;
					cout << "��������Ʒ���:";
					cin >> p->data.commodityNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "�޸�ǰ��Ʒ���ƣ�" << p->data.commodityName << endl;
					cout << "��������Ʒ����:";
					cin >> p->data.commodityName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "�޸�ǰ��Ʒ���" << p->data.commodityClass << endl;
					cout << "��������Ʒ���:";
					cin >> p->data.commodityClass;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "�޸�ǰ���أ�" << p->data.commodityPlaceOfOrigin << endl;
					cout << "���������:";
					cin >> p->data.commodityPlaceOfOrigin;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "�޸�ǰ�������ң�" << p->data.commodityManufacturer << endl;
					cout << "��������������:";
					cin >> p->data.commodityManufacturer;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "�޸�ǰ��Ʒ���ۣ�" << p->data.commodityPurchasePrice << endl;
					cout << "��������Ʒ����:";
					cin >> p->data.commodityPurchasePrice;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "�޸�ǰ��Ʒ�ۼۣ�" << p->data.commodityPrice << endl;
					cout << "��������Ʒ�ۼ�:";
					cin >> p->data.commodityPrice;
				}
				else if (strcmp(g, "8") == 0)
				{
					cout << "�޸�ǰ��Ʒ����������" << p->data.commodityPurchaseQuantity << endl;
					cout << "��������Ʒ��������:";
					cin >> p->data.commodityPurchaseQuantity;
				}
				else if (strcmp(g, "9") == 0)
				{
					cout << "�޸�ǰ��Ʒ����������" << p->data.commoditySoldQuantity << endl;
					cout << "��������Ʒ��������:";
					cin >> p->data.commoditySoldQuantity;
				}
				else if (strcmp(g, "10") == 0)
				{
					cout << "�޸�ǰ��Ʒ���������" << p->data.commodityInventoryQuantity << endl;
					cout << "��������Ʒ�������:";
					cin >> p->data.commodityInventoryQuantity;
				}
				else if (strcmp(g, "11") == 0)
				{
					cout << "�޸�ǰ��Ʒ����" << p->data.commodityInventoryAmount << endl;
					cout << "��������Ʒ�����:";
					cin >> p->data.commodityInventoryAmount;
				}
				else
				{
					cout << "�������" << endl;
					break;
				}
				system("cls");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******�Ƿ�����޸ģ�*******" << endl;
				cout << "\t\t                       *******    1-->��      *******" << endl;
				cout << "\t\t                        *******   2-->��     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       ����������ѡ��(1-2):";
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
					cout << "�����������������!" << endl;
				}
				break;
			}

		}
		return head;
	}

	else if (strcmp(b, "2") == 0)
	{

		//�������޸�����
		cout << "����������Ҫ�޸���Ʒ����" << endl;
		cin >> Name;
		system("cls");
		if (head == NULL)//����ǿ�����
		{
			cout << "����Ʒ��Ϣ��" << endl;
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t        ����Ʒ������!" << endl;
			CommodityModify(head);
		}
		else
		{
			cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
				<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			cout << "\t\t                        *******��ѡ����Ҫ�޸ĵķ�ʽ��*******" << endl;
			cout << "\t\t                       *******      1-->ȫ���޸�      *******" << endl;
			cout << "\t\t                        *******     2-->�ֲ��޸�     *******" << endl;
			cout << "\t\t                           ******************************" << endl;
			cout << "\t\t                       ����������ѡ��(1-2):";
			char h = '0';
			cin >> h;
			switch (h)
			{
			case '1':
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�޸�ǰ��Ʒ��ţ�" << p->data.commodityNumber << endl;
				cout << "��������Ʒ���:";
				cin >> p->data.commodityNumber;
				cout << "�޸�ǰ��Ʒ���ƣ�" << p->data.commodityName << endl;
				cout << "��������Ʒ����:";
				cin >> p->data.commodityName;
				cout << "�޸�ǰ��Ʒ���" << p->data.commodityClass << endl;
				cout << "��������Ʒ���:";
				cin >> p->data.commodityClass;
				cout << "�޸�ǰ���أ�" << p->data.commodityPlaceOfOrigin << endl;
				cout << "���������:";
				cin >> p->data.commodityPlaceOfOrigin;
				cout << "�޸�ǰ�������ң�" << p->data.commodityManufacturer << endl;
				cout << "��������������:";
				cin >> p->data.commodityManufacturer;
				cout << "�޸�ǰ��Ʒ���ۣ�" << p->data.commodityPurchasePrice << endl;
				cout << "��������Ʒ����:";
				cin >> p->data.commodityPurchasePrice;
				cout << "�޸�ǰ��Ʒ�ۼۣ�" << p->data.commodityPrice << endl;
				cout << "��������Ʒ�ۼ�:";
				cin >> p->data.commodityPrice;
				cout << "�޸�ǰ��Ʒ����������" << p->data.commodityPurchaseQuantity << endl;
				cout << "��������Ʒ��������:";
				cin >> p->data.commodityPurchaseQuantity;
				cout << "�޸�ǰ��Ʒ����������" << p->data.commoditySoldQuantity << endl;
				cout << "��������Ʒ��������:";
				cin >> p->data.commoditySoldQuantity;
				cout << "�޸�ǰ��Ʒ���������" << p->data.commodityInventoryQuantity << endl;
				cout << "��������Ʒ�������:";
				cin >> p->data.commodityInventoryQuantity;
				cout << "�޸�ǰ��Ʒ����" << p->data.commodityInventoryAmount << endl;
				cout << "��������Ʒ�����:";
				cin >> p->data.commodityInventoryAmount;
				cout << "�޸ĺ���ϢΪ��" << "��Ʒ��ţ�" << p->data.commodityNumber << "��Ʒ���ƣ�" << p->data.commodityName << endl << "��Ʒ���" << p->data.commodityClass << endl << "���أ�" << p->data.commodityPlaceOfOrigin << endl << "���ң�" << p->data.commodityManufacturer << endl << "��Ʒ���ۣ�" << p->data.commodityPurchasePrice << endl << "��Ʒ�ۼۣ�" << p->data.commodityPrice << endl << "��Ʒ����������" << p->data.commodityPurchaseQuantity << endl << "��Ʒ����������" << p->data.commoditySoldQuantity << endl << "��Ʒ���������" << p->data.commodityInventoryQuantity << endl << "��Ʒ����" << p->data.commodityInventoryAmount << endl;
				system("pause");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******�Ƿ�����޸ģ�*******" << endl;
				cout << "\t\t                       *******    1-->��      *******" << endl;
				cout << "\t\t                        *******   2-->��     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       ����������ѡ��(1-2):";
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
					cout << "�����������������!" << endl;
				}
				break;

			case '2':
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "1.��Ʒ���" << endl << "2.��Ʒ����" << endl << "3.��Ʒ���" << endl << "4.����" << endl << "5.��������" << endl << "6.��Ʒ����" << endl << "7.��Ʒ�ۼ�" << endl << "8.��Ʒ��������" << endl << "9.��Ʒ��������" << endl << "10.��Ʒ�������" << endl << "11.��Ʒ�����" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "�޸�ǰ��Ʒ��ţ�" << p->data.commodityNumber << endl;
					cout << "��������Ʒ���:";
					cin >> p->data.commodityNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "�޸�ǰ��Ʒ���ƣ�" << p->data.commodityName << endl;
					cout << "��������Ʒ����:";
					cin >> p->data.commodityName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "�޸�ǰ��Ʒ���" << p->data.commodityClass << endl;
					cout << "��������Ʒ���:";
					cin >> p->data.commodityClass;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "�޸�ǰ���أ�" << p->data.commodityPlaceOfOrigin << endl;
					cout << "���������:";
					cin >> p->data.commodityPlaceOfOrigin;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "�޸�ǰ�������ң�" << p->data.commodityManufacturer << endl;
					cout << "��������������:";
					cin >> p->data.commodityManufacturer;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "�޸�ǰ��Ʒ���ۣ�" << p->data.commodityPurchasePrice << endl;
					cout << "��������Ʒ����:";
					cin >> p->data.commodityPurchasePrice;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "�޸�ǰ��Ʒ�ۼۣ�" << p->data.commodityPrice << endl;
					cout << "��������Ʒ�ۼ�:";
					cin >> p->data.commodityPrice;
				}
				else if (strcmp(g, "8") == 0)
				{
					cout << "�޸�ǰ��Ʒ����������" << p->data.commodityPurchaseQuantity << endl;
					cout << "��������Ʒ��������:";
					cin >> p->data.commodityPurchaseQuantity;
				}
				else if (strcmp(g, "9") == 0)
				{
					cout << "�޸�ǰ��Ʒ����������" << p->data.commoditySoldQuantity << endl;
					cout << "��������Ʒ��������:";
					cin >> p->data.commoditySoldQuantity;
				}
				else if (strcmp(g, "10") == 0)
				{
					cout << "�޸�ǰ��Ʒ���������" << p->data.commodityInventoryQuantity << endl;
					cout << "��������Ʒ�������:";
					cin >> p->data.commodityInventoryQuantity;
				}
				else if (strcmp(g, "11") == 0)
				{
					cout << "�޸�ǰ��Ʒ����" << p->data.commodityInventoryAmount << endl;
					cout << "��������Ʒ�����:";
					cin >> p->data.commodityInventoryAmount;
				}
				else
				{
					cout << "�������" << endl;
				}
				system("pause");
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                        *******�Ƿ�����޸ģ�*******" << endl;
				cout << "\t\t                       *******    1-->��      *******" << endl;
				cout << "\t\t                        *******   2-->��     *******" << endl;
				cout << "\t\t                           **********************" << endl;
				cout << "\t\t                       ����������ѡ��(1-2):";
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
					cout << "�����������������!" << endl;
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
  


//��Ʒ��ѯ
int CommoditySearch(CommodityNode* head)
{
	CommodityOutput(head);
	char choice[10] = "0";
	char choi[10] = "0";//�����ж��Ƿ��������
	char commoditynumber[8] = "0";//Ҫ���ҵ���Ϣ���
	char commodityname[20] = "0";//Ҫ���ҵ�����
	char commodityclass[10] = "0";//Ҫ���ҵ����
	char commodityplaceoforigin[10] = "0";//Ҫ���ҵĲ���
	char commoditymanufacturer[20] = "0";//Ҫ���ҵĳ���
	char cho[10] = "0";//��ѯ��ѡ��
	int i = 0;//forѭ����ʹ��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ

	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                        *******��ѡ����Ҫ��ѯ�ķ�ʽ��*******" << endl;
	cout << "\t\t                       *******      1-->��ȷ����      *******" << endl;
	cout << "\t\t                      *******       2-->ģ������       *******" << endl;
	cout << "\t\t                        *******     3-->�������˵�   *******" << endl;
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                     ����������ѡ��(1-3):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> choice;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		CommodityOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                           *******************************" << endl;
		cout << "\t\t                          *******  ��ѡ���ѯ����:  *******" << endl;
		cout << "\t\t                        *******     1-->����Ʒ���    *******" << endl;
		cout << "\t\t                       *******      2-->����Ʒ����     *******" << endl;
		cout << "\t\t                         *******    3-->�������˵�   *******" << endl;
		cout << "\t\t                           *******************************" << endl;
		cout << "\t\t                     ����������ѡ��1-6��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout << "\t\t          ��������Ʒ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> commoditynumber;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ

			CommodityNode* p = NULL;//p�ǲ���λ��
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "����Ʒ��Ϣ��" << endl;
				cout << "�밴���������" << endl;
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ����Ʒ������!" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}
			else
			{
				cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
					<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			cout << "          ��������Ʒ����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> commodityname;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			struct CommodityNode* p = NULL;//p�ǲ���λ��
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "����Ʒ��Ϣ��" << endl;
				cout << "�밴���������" << endl;
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ����Ʒ������" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}
			else
			{
				cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
					<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                            ѡ�����\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		}
	}
	if (strcmp(choice, "2") == 0)
	{
		CommodityOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                      ************   ��ѡ���ѯ����:  *********" << endl;
		cout << "\t\t                    *************   1-->����Ʒ����     *******" << endl;
		cout << "\t\t                     **********     2-->����Ʒ���     *******" << endl;
		cout << "\t\t                     *********      3-->������          *******" << endl;
		cout << "\t\t                        *******     4-->����������    *******" << endl;
		cout << "\t\t                         *******    5-->�������˵�   *******" << endl;
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                      ����������ѡ��1-6��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");

		if (strcmp(cho, "1") == 0)
		{
			cout << "          ���������ѯ����Ʒ����:" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			char commodityclass[20] = "0";
			cin >> commodityname;
			int length = 0;//��Ʒ��������
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			struct CommodityNode* p = NULL;//p�ǲ���λ��
			int i = 0;//λ�����

			if (head == NULL)//����ǿ�����
			{
				cout << "����Ʒ��Ϣ��" << endl;
				return -1;//��ʾ��ʱ����Ϊ��
			}

			p = head;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				char* s = NULL;
				s = strstr(p->data.commodityName, commodityname);
				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
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
				cout << "û�и�������Ʒ" << endl;
				_getch();
			}
		}
		if (strcmp(cho, "2") == 0)
		{
			cout << "          ���������ѯ����Ʒ���:" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			char commodityclass[20] = "0";
			cin >> commodityclass;
			int length = 0;//��Ʒ��������
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			struct CommodityNode* p = NULL;//p�ǲ���λ��
			int i = 0;//λ�����

			if (head == NULL)//����ǿ�����
			{
				cout << "����Ʒ��Ϣ��" << endl;
				return -1;//��ʾ��ʱ����Ϊ��
			}

			p = head;

			cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
				<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				char* s = NULL;
				s = strstr(p->data.commodityClass, commodityclass);
				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
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
				cout << "û�и�������Ʒ" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> commodityplaceoforigin;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			struct CommodityNode* p = NULL;//p�ǲ���λ��
			int length = 0;//��Ʒ��������
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "����Ʒ��Ϣ��" << endl;
				_getch();
				return -1;//��ʾ��ʱ����Ϊ��
			}

			p = head;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
				<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				char* s = NULL;
				s = strstr(p->data.commodityPlaceOfOrigin, commodityplaceoforigin);
				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
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
				cout << "û�иò��ص���Ʒ" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          ��������������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> commoditymanufacturer;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			struct CommodityNode* p = NULL;//p�ǲ���λ��
			int length = 0;//������
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "����Ʒ��Ϣ��" << endl;
				_getch();
				return -1;//��ʾ��ʱ����Ϊ��
			}

			p = head;
			cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
				<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			int j = 0;
			for (p = head; p != NULL; p = p->next)
			{
				char* s = NULL;
				s = strstr(p->data.commodityManufacturer, commoditymanufacturer);

				if (s != NULL)
				{
					if (i == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
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
				cout << "û�иò��ص���Ʒ" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0 && strcmp(cho, "4") != 0 && strcmp(cho, "5") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                                  ѡ�����\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		}
	}
	else if (strcmp(choice, "3") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�������˵�!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		return 0;
	}
	else if (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "3") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                             ѡ�����!\n" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******        �Ƿ������ѯ        *******" << endl;
	cout << "\t\t                       *******       �� Y �������˵�        *******" << endl;
	cout << "\t\t                        *******       �� N ��������        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       ����������ѡ��:";
	char b[10] = "0";//ȷ�����������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> b;
	while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�����������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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



//������Ʒ���/����Ʒ�ۼ�/��Ʒ�������/��Ʒ�������� 
void CommoditySelectionSort(CommodityNode* head)
{
	system("cls");//����
	CommodityNode* p = NULL;
	CommodityNode* q = NULL;
	CommodityNode* r = NULL;
	CommodityNode* k = NULL;
	Commodity temp1;
	Commodity temp2;
	int i = 0;
	char cho[10] = "0";//��������ѡ��
	char choi[10] = "0";//�ж��Ƿ�����鿴��Ʒ����
	cout << "\t\t            ************************************************************************" << endl;
	cout << "\t\t           ********************          ��ѡ����������:         ********************" << endl;
	cout << "\t\t          ********************         1-->����Ʒ��������         ********************" << endl;
	cout << "\t\t         ********************          2-->����Ʒ�ۼ�              ********************" << endl;
	cout << "\t\t         ********************          3-->����Ʒ�������          ********************" << endl;
	cout << "\t\t          ********************         4-->����Ʒ��������         ********************" << endl;
	cout << "\t\t           ********************        5-->�������˵�            ********************" << endl;
	cout << "\t\t            ***********************************************************************" << endl;
	cout << "\t\t         ����������ѡ��1-5��:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> cho;
	while (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0 && strcmp(cho, "4") != 0 && strcmp(cho, "5") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                    ����������������루1-5��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> cho;
	}
	system("cls");//����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(cho, "1") == 0) //����Ʒ�����������򣬲���ֱ�Ӳ�������
	{

		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
			<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
			<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		//q = (StaffNode*)malloc(sizeof(StaffNode));//Ϊ�������ڴ浥Ԫ
		q = new CommodityNode;//Ϊ�������ڴ浥Ԫ
		q->next = head;//q����һ�ڵ�ָ��ͷ���
		head = q;//��ͷ�����Ϊ��
		p = head->next->next;//��ָ��p������δ����Ԫ�ص���Ϣ
		head->next->next = NULL;//ʹ��ԭ����������������ǰ����һ��Ԫ��
		while (p != NULL)//����������
		{
			k = p->next;//����λ��
			r = head;//��ָ��ָ��������
			while (r->next != NULL && r->next->data.commodityPurchaseQuantity > p->data.commodityPurchaseQuantity)//�ж�ָ��ָ�����һ��Ԫ����������ȡ��Ԫ�صĴ�С
			{
				r = r->next;
			}
			p->next = r->next;//�������
			r->next = p;
			p = k;//��pֵ�ظ���ָ����������һ���ڵ�
		}
		head = head->next;//ȥ��һ��ʼ����Ŀ�����
		//free(q);//�ͷŵ�ǰ�����ڴ�ռ�
		delete q;
		q = NULL;
		p = head;
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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

			p = p->next;//ָ����һ�����
		}
	}
	else if (strcmp(cho, "2") == 0)//����Ʒ�ۼ����򣬲���ð�������³�����
	{

		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
			<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
			<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		p = head;
		while (p != q)
		{
			while (p->next != q)
			{
				if (p->data.commodityPrice < p->next->data.commodityPrice) //�Ƚ���������ֵ�����������򽻻�
				{
					temp1 = p->data;
					p->data = p->next->data;
					p->next->data = temp1;
				}
				p = p->next;
			}
			q = p;//ÿ�ε�����whileѭ�������һ��ֵ���ﵽÿ���ٱȽ�һ����Ŀ��
			p = head;
		}
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			p = p->next;//ָ����һ�����
		}
	}
	else if (strcmp(cho, "3") == 0)//����Ʒ����������򣬲���ֱ��ѡ������
	{

		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
			<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
			<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		q = p = head;
		while (q)//�ӵ�һ������
		{
			r = p;//�����������������λ��
			temp1 = p->data;//�������������Ϣ
			p = p->next;//ָ���������ڶ����ڵ�
			while (p)
			{
				if (p->data.commodityInventoryQuantity > temp1.commodityInventoryQuantity)
				{
					r = p;//�����������������λ��
					temp1 = p->data;
				}
				p = p->next;
			}
			p = r;//ָ�����ֵλ��
			temp2 = p->data;//�����ֵλ���뵱ǰλ�ý���
			p->data = q->data;
			q->data = temp2;
			q = q->next;//ָ����һ���ڵ�λ��
			p = q;//��pֵ�ظ���ָ����������һ���ڵ�
		}
		p = head;
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			p = p->next;//ָ����һ�����
		}
	}
	else if (strcmp(cho, "4") == 0) //����Ʒ�����������򣬲���ֱ��ѡ������
	{
	cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
		<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
		<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
	cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		q = p = head;
		while (q)
		{
			r = p;
			temp1 = p->data;
			p = p->next;//ָ����������һ���ڵ�
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
			p = q;//��pֵ�ظ���ָ����������һ���ڵ�
		}
		p = head;
		while (p != NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			p = p->next;//ָ����һ�����
		}
	}
	else if (strcmp(cho, "5") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		return;
	}
	i = 0; //�����ж���ѡ���Ƿ��������ʱ��ѡ���Ƿ����
	while (strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
	{
		if (i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "\t\t                                     �Ƿ����룡���������룡" << endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                           *******  �Ƿ�����鿴��Ʒ����*******" << endl;
		cout << "\t\t                          *******       Y-->�����鿴       *******" << endl;
		cout << "\t\t                           *******      N-->�������˵�    *******" << endl;
		cout << "\t\t                              ********************************" << endl;
		cout << "\t\t                          ����������ѡ��(Y or N):";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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
