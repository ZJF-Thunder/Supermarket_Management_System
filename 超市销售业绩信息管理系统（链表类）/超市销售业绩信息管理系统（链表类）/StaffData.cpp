//#define _CRT_SECURE_NO_WARNNINGS //���⾯��
#include "Staff.h"
#include<iostream>
#include<windows.h>//����̨�����Ҫͷ�ļ�
#include<iomanip>//�õ�setw()����
#include<conio.h>//_getch()
using namespace std;

//�����ļ�����   ������������ݵ��ļ���
bool StaffSave(StaffNode* head)
{
	StaffNode* p = NULL;//��ָ��p����ָ������������
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
		fopen_s(&fp, "StaffData.txt", "w+");
		if (fp == NULL)
			//if (!fp)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "�����ļ�ʧ��!" << endl;
			return 0;
		}
		i = 0;
		//��ÿ��Ա����Ϣд���ļ�
		p = head;
		while (p != NULL)
			//while (i < size)
		{
			fprintf(fp, "%s\t", p->data.staffNumber);
			fprintf(fp, "%s\t", p->data.staffName);
			fprintf(fp, "%s\t", p->data.staffgender);
			fprintf(fp, "%d\t", p->data.staffMonthSaleQuantity);
			fprintf(fp, "%f\t", p->data.staffMonthSaleAmount);
			fprintf(fp, "%d\t", p->data.staffTotalSaleQuantity);
			fprintf(fp, "%f\t\n", p->data.staffTotalSaleAmount);
			p = p->next; //ָ��ָ����һ���ڵ�
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "������" << i << "��Ա������Ϣ���ļ��У�" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		fclose(fp);
		return 1;
	}
}

//��ȡ���ݺ���   ��ȡ�ļ��е����ݵ��ڴ���
StaffNode* StaffRead(StaffNode* head)
{
	head = NULL;  //ͷָ��
	StaffNode* p1 = NULL;  //��ָ��pָ��Ҫ������½��
	StaffNode* p2 = NULL;  //��ָ��pָ��Ҫ������½��
	FILE* fp;               //�����ļ�����ָ��
	int i = 0;//ѭ������
	fopen_s(&fp, "StaffData.txt", "r");
	if (fp == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "��ȡ�ļ�ʧ��!\n" << endl;
		return 0;
	}
	while (!feof(fp)) //��ʾû��ָ���ļ�ĩβ��ûָ��ĩβΪ0
	{
		p1 = new StaffNode;
		fscanf_s(fp, "%s\t", &p1->data.staffNumber, 8);
		fscanf_s(fp, "%s\t", &p1->data.staffName, 20);
		fscanf_s(fp, "%s\t", &p1->data.staffgender, 20);
		fscanf_s(fp, "%d\t", &p1->data.staffMonthSaleQuantity, 20);
		fscanf_s(fp, "%f\t", &p1->data.staffMonthSaleAmount, 20);
		fscanf_s(fp, "%d\t", &p1->data.staffTotalSaleQuantity, 20);
		fscanf_s(fp, "%f\t\n", &p1->data.staffTotalSaleAmount, 20);
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
	//size = i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "����ȡ" << i << "��Ա������Ϣ���ڴ��У�" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	fclose(fp);
	return head;
}


//Ա�����ݳ�ʼ��
StaffNode* StaffInit(StaffNode* head)
{
	head = NULL;
	StaffNode* p1 = NULL;
	StaffNode* p2 = NULL;
	int i = 0;
	p1 = new StaffNode;
	cout << "Ա��ϵͳ��ʼ����" << endl;
	strcpy(p1->data.staffNumber, "001");
	strcpy(p1->data.staffName, "������");
	strcpy(p1->data.staffgender, "��");
	p1->data.staffMonthSaleQuantity = 2222;
	p1->data.staffMonthSaleAmount = 3333;
	p1->data.staffTotalSaleQuantity = 2777;
	p1->data.staffTotalSaleAmount = 5555;
	head = p1;
	p2 = p1;

	p1 = new StaffNode;
	strcpy(p1->data.staffNumber, "002");
	strcpy(p1->data.staffName, "����Ө");
	strcpy(p1->data.staffgender, "Ů");
	p1->data.staffMonthSaleQuantity = 2777;
	p1->data.staffMonthSaleAmount = 2222;
	p1->data.staffTotalSaleQuantity = 1122;
	p1->data.staffTotalSaleAmount = 2222;
	p2->next = p1;
	p2 = p1;

	p1 = new StaffNode;
	strcpy(p1->data.staffNumber, "003");
	strcpy(p1->data.staffName, "����ӱ");
	strcpy(p1->data.staffgender, "Ů");
	p1->data.staffMonthSaleQuantity = 1111;
	p1->data.staffMonthSaleAmount = 4777;
	p1->data.staffTotalSaleQuantity = 3333;
	p1->data.staffTotalSaleAmount = 1122;
	p2->next = p1;
	p2 = p1;

	p1 = new StaffNode;
	strcpy(p1->data.staffNumber, "004");
	strcpy(p1->data.staffName, "��");
	strcpy(p1->data.staffgender, "��");
	p1->data.staffMonthSaleQuantity = 3333;
	p1->data.staffMonthSaleAmount = 4555;
	p1->data.staffTotalSaleQuantity = 4777;
	p1->data.staffTotalSaleAmount = 2777;
	p2->next = p1;
	p2 = p1;
	p2->next = NULL;

	StaffSave(head);
	cout << "Ա��ϵͳ��ʼ���ɹ���" << endl;
	cout << "�밴���������" << endl;
	_getch();
	return head;
}

//����Ա����Ϣ
StaffNode* StaffCreate(StaffNode* head)
{
	head = NULL;
	StaffNode* p1 = NULL;
	StaffNode* p2 = NULL;
	int i = 0;//ѭ������
	int m = 0;//Ա��������

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

		cout << "��������Ҫ�����Ա������:";
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
			p1 = new StaffNode;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "�������" << i + 1 << "��Ա���ı��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա��������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա�����Ա�:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffgender;
			while (strcmp(p1->data.staffgender, "��") != 0 && strcmp(p1->data.staffgender, "Ů") != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�Ƿ����룡����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> p1->data.staffgender;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա���ĵ�����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffMonthSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա���ĵ������۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffMonthSaleAmount;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա�����ۼ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffTotalSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա�����ۼ����۽�� :";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffTotalSaleAmount;
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
		cout << "������" << m << "��Ա������Ϣ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		StaffSave(head); //�������ݵ��ļ���
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	return head;
}

//����Ա������Ϣ
StaffNode* StaffAdd(StaffNode* head)
{
	StaffNode* p1 = NULL;
	StaffNode* p2 = NULL;
	int i = 0;//ѭ������
	int m = 0;//Ա��������

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

		cout << "��������Ҫ�����Ա������:";
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
			p1 = new StaffNode;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "�������" << i + 1 << "��Ա���ı��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffNumber;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա��������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffName;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա�����Ա�:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffgender;
			while (strcmp(p1->data.staffgender, "��") != 0 && strcmp(p1->data.staffgender, "Ů") != 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�Ƿ����룡����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> p1->data.staffgender;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա���ĵ�����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffMonthSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա���ĵ������۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffMonthSaleAmount;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա�����ۼ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffTotalSaleQuantity;

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "Ա�����ۼ����۽�� :";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> p1->data.staffTotalSaleAmount;
			cout << endl;
			p2->next = p1;
			p2 = p1;

		}
		p2->next = NULL;//������־
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "������" << m << "��Ա������Ϣ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		StaffSave(head); //�������ݵ��ļ���
	}
	else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	return head;

}


//���Ա������Ϣ
void StaffOutput(StaffNode* head)
{
	StaffNode* p = head;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
		<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
	cout << endl;

	if (p == NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�ܱ�Ǹ���ļ���û��Ա����Ϣ���������Ա����Ϣ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�밴���������" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		_getch();
		return;
	}
	while (p != NULL)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << setw(3) << p->data.staffNumber << '\t'
			<< setw(3) << p->data.staffName << '\t'
			<< setw(3) << p->data.staffgender << '\t'
			<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
			<< setw(8) << p->data.staffMonthSaleAmount << '\t'
			<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
			<< setw(8) << p->data.staffTotalSaleAmount << '\t'
			<< endl;
		p = p->next;//ָ����һ�����
	}
	cout << endl;
}

//ɾ��Ա����Ϣ
StaffNode* StaffDel(StaffNode* head)
{
	StaffOutput(head);
	StaffNode* p = head;//ָ�����ָ��
	if (p == NULL)
		return 0;
	StaffNode* q;//��ѭ�����
	int i = 0;//���ڱ����ҵ�����ѯ��Ϣλ��
	int k = 0;//�����ж��Ƿ��д�Ա��
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	char choose[10] = "0";
	cout << "\t\t                            *****************************" << endl;
	cout << "\t\t                          *******  ��ѡ��ɾ������:  *******" << endl;
	cout << "\t\t                        *******     1-->��Ա�����    *******" << endl;
	cout << "\t\t                       *******      2-->��Ա������     *******" << endl;
	cout << "\t\t                        *******     3-->��Ա���Ա�    *******" << endl;
	cout << "\t\t                         *******    4-->�������˵�   *******" << endl;
	cout << "\t\t                            *****************************" << endl;
	cout << "\t\t                       ����������ѡ��1-4��:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> choose;
	while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0 && strcmp(choose, "3") != 0 && strcmp(choose, "4") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                    ����������������루1-4��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> choose;
	}
	system("cls");//����
	if (strcmp(choose, "1") == 0)
	{
		char Snum[8] = "0";//��Ҫɾ����Ա����� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "����������Ҫɾ����Ա�����:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Snum;//������Ҫɾ����Ա�����
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Snum, p->data.staffNumber) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
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
			cout << "\t\t                            *************     ��Ա�������ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t             *************       �ɹ�ɾ�����Ϊ" << Snum << "��" << k << "λԱ����Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "2") == 0)
	{
		char Snam[20];//��Ҫɾ����Ա������ 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "����������Ҫɾ����Ա������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Snam;//������Ҫɾ����Ա������
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Snam, p->data.staffName) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
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
			cout << "\t\t                            *************     ��Ա�������ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t             *************       �ɹ�ɾ������Ϊ" << Snam << "��" << k << "λԱ����Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "3") == 0)
	{
		char Sgen[5];//��Ҫɾ����Ա���Ա� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "����������Ҫɾ����Ա���Ա�:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> Sgen;//������Ҫɾ����Ա���Ա�
		while (p != NULL)
		{
			i++;//��¼λ�ã�����ɾ����������Ϣ��ȵ�����
			if (strcmp(Sgen, p->data.staffgender) == 0)//�ж���Ҫɾ����������Ϣ�Ƿ����
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
			cout << "\t\t                            *************     ��Ա�������ڣ�   *************" << endl;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t             *************       �ɹ�ɾ���Ա�Ϊ" << Sgen << "��" << k << "λԱ����Ϣ��      *************" << endl;
		}
	}
	else if (strcmp(choose, "4") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (k > 0)
		StaffSave(head);//���浽�ļ���

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
		cout << "\t\t                           *******    �Ƿ����ɾ��Ա����  *******" << endl;
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
			return 0;
		}
		else if (strcmp(choi, "y") == 0 || strcmp(choi, "Y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			StaffDel(head);
		}
		i++;
	}
	return head;
}


//�޸�Ա������Ϣ
StaffNode* StaffModify(StaffNode* head)
{
	StaffOutput(head);
	StaffNode* p = NULL;
	char Number[4] = "0";
	char Name[20] = "0";
	char H = '0';
	char f[5] = "0";
	int q = 0;
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
	while (strcmp(b, "1") != 0 && strcmp(b, "2") != 0 && strcmp(b, "3") != 0 )
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�����������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> b;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(b, "1") == 0)
	{
		cout << "����������Ҫ�޸�Ա�����" << endl;
		cin >> Number;
		system("cls");
		if (head == NULL)//����ǿ�����
		{
			cout << "����Ʒ��Ϣ��" << endl;
			StaffModify(head);
		}
		p = head;
		while (p != NULL && strcmp(Number, p->data.staffNumber) != 0)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t        ��Ա��������!" << endl;
			StaffModify(head);
		}
		else
		{
			cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
				<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
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
			case '1'://ȫ���޸�
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�޸�ǰԱ����ţ�" << p->data.staffNumber << endl;
				cout << "������Ա�����:";
				cin >> p->data.staffNumber;
				cout << "�޸�ǰԱ�����ƣ�" << p->data.staffName << endl;
				cout << "������Ա������:";
				cin >> p->data.staffName;
				cout << "�޸�ǰԱ���Ա�" << p->data.staffgender << endl;
				cout << "������Ա���Ա�:";
				cin >> p->data.staffgender;
				cout << "�޸�ǰԱ����������������" << p->data.staffMonthSaleQuantity << endl;
				cout << "������Ա��������������:";
				cin >> p->data.staffMonthSaleQuantity;
				cout << "�޸�ǰ�������۽�" << p->data.staffMonthSaleAmount << endl;
				cout << "�����뵱�����۽��:";
				cin >> p->data.staffMonthSaleAmount;
				cout << "�޸�ǰ�ۼ�����������" << p->data.staffTotalSaleQuantity << endl;
				cout << "�������ۼ���������:";
				cin >> p->data.staffTotalSaleQuantity;
				cout << "�޸�ǰ�ۼ����۽�" << p->data.staffTotalSaleAmount << endl;
				cout << "�������ۼ����۽��:";
				cin >> p->data.staffTotalSaleAmount;
				cout << "�޸ĺ���ϢΪ��" << "��ţ�" << p->data.staffNumber << endl << "������" << p->data.staffName << endl << "�Ա�" << p->data.staffgender << endl << "��������������" << p->data.staffMonthSaleQuantity << endl << "�������۽�" << p->data.staffMonthSaleAmount << endl << "�ۼ�����������" << p->data.staffTotalSaleQuantity << endl << "�ۼ����۽��" << p->data.staffTotalSaleAmount << endl;
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
					StaffModify(head);
				}
				else if(strcmp(f, "2") == 0)
				{
					return head;
				}
				else
				{
					cout << "�����������������!" << endl;
				}
				break;

			case '2'://�ֲ��޸�
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "1.Ա�����" << endl << "2.Ա������" << endl << "3.Ա���Ա�" << endl << "4.Ա��������������" << endl << "5.Ա���������۽��" << endl << "6.�ۼ���������" << endl << "7.�ۼ����۽��" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "�޸�ǰԱ����ţ�" << p->data.staffNumber << endl;
					cout << "������Ա�����:";
					cin >> p->data.staffNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "�޸�ǰԱ�����ƣ�" << p->data.staffName << endl;
					cout << "������Ա������:";
					cin >> p->data.staffName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "�޸�ǰԱ���Ա�" << p->data.staffgender << endl;
					cout << "������Ա���Ա�:";
					cin >> p->data.staffgender;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "�޸�ǰԱ����������������" << p->data.staffMonthSaleQuantity << endl;
					cout << "������Ա��������������:";
					cin >> p->data.staffMonthSaleQuantity;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "�޸�ǰ�������۽�" << p->data.staffMonthSaleAmount << endl;
					cout << "�����뵱�����۽��:";
					cin >> p->data.staffMonthSaleAmount;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "�޸�ǰ�ۼ�����������" << p->data.staffTotalSaleQuantity << endl;
					cout << "�������ۼ���������:";
					cin >> p->data.staffTotalSaleQuantity;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "�޸�ǰ�ۼ����۽�" << p->data.staffTotalSaleAmount << endl;
					cout << "�������ۼ����۽��:";
					cin >> p->data.staffTotalSaleAmount;
					cout << "�޸ĺ���ϢΪ��" << "��ţ�" << p->data.staffNumber << endl << "������" << p->data.staffName << endl << "�Ա�" << p->data.staffgender << endl << "��������������" << p->data.staffMonthSaleQuantity << endl << "�������۽�" << p->data.staffMonthSaleAmount << endl << "�ۼ�����������" << p->data.staffTotalSaleQuantity << endl << "�ۼ����۽��" << p->data.staffTotalSaleAmount << endl;
				}
				else
				{
					cout << "�������" << endl;
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
					StaffModify(head);
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
	else if (strcmp(b, "2") == 0 )
	{
		cout << "����������Ҫ�޸�Ա������" << endl;
		cin >> Name;
		system("cls");
		if (head == NULL)//����ǿ�����
		{
			cout << "��Ա����Ϣ��" << endl;
			StaffModify(head);
		}
		p = head;
		while (p != NULL && strcmp(Name, p->data.staffName) != 0)
		{
			p = p->next;
		}
		if (p == NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t        ��Ա��������!" << endl;
			StaffModify(head);
		}
		else
		{
			cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
				<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
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
				cout << "�޸�ǰԱ����ţ�" << p->data.staffNumber << endl;
				cout << "������Ա�����:";
				cin >> p->data.staffNumber;
				cout << "�޸�ǰԱ�����ƣ�" << p->data.staffName << endl;
				cout << "������Ա������:";
				cin >> p->data.staffName;
				cout << "�޸�ǰԱ���Ա�" << p->data.staffgender << endl;
				cout << "������Ա���Ա�:";
				cin >> p->data.staffgender;
				cout << "�޸�ǰԱ����������������" << p->data.staffMonthSaleQuantity << endl;
				cout << "������Ա��������������:";
				cin >> p->data.staffMonthSaleQuantity;
				cout << "�޸�ǰ�������۽�" << p->data.staffMonthSaleAmount << endl;
				cout << "�����뵱�����۽��:";
				cin >> p->data.staffMonthSaleAmount;
				cout << "�޸�ǰ�ۼ�����������" << p->data.staffTotalSaleQuantity << endl;
				cout << "�������ۼ���������:";
				cin >> p->data.staffTotalSaleQuantity;
				cout << "�޸�ǰ�ۼ����۽�" << p->data.staffTotalSaleAmount << endl;
				cout << "�������ۼ����۽��:";
				cin >> p->data.staffTotalSaleAmount;
				cout << "�޸ĺ���ϢΪ��" << "��ţ�" << p->data.staffNumber << endl << "������" << p->data.staffName << endl << "�Ա�" << p->data.staffgender << endl << "��������������" << p->data.staffMonthSaleQuantity << endl << "�������۽�" << p->data.staffMonthSaleAmount << endl << "�ۼ�����������" << p->data.staffTotalSaleQuantity << endl << "�ۼ����۽��" << p->data.staffTotalSaleAmount << endl;
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
					StaffModify(head);
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
				cout << "1.Ա�����" << endl << "2.Ա������" << endl << "3.Ա���Ա�" << endl << "4.Ա��������������" << endl << "5.Ա���������۽��" << endl << "6.�ۼ���������" << endl << "7.�ۼ����۽��" << endl;
				char g[10] = "0";
				cin >> g;
				system("cls");
				if (strcmp(g, "1") == 0)
				{
					cout << "�޸�ǰԱ����ţ�" << p->data.staffNumber << endl;
					cout << "������Ա�����:";
					cin >> p->data.staffNumber;
				}
				else if (strcmp(g, "2") == 0)
				{
					cout << "�޸�ǰԱ�����ƣ�" << p->data.staffName << endl;
					cout << "������Ա������:";
					cin >> p->data.staffName;
				}
				else if (strcmp(g, "3") == 0)
				{
					cout << "�޸�ǰԱ���Ա�" << p->data.staffgender << endl;
					cout << "������Ա���Ա�:";
					cin >> p->data.staffgender;
				}
				else if (strcmp(g, "4") == 0)
				{
					cout << "�޸�ǰԱ����������������" << p->data.staffMonthSaleQuantity << endl;
					cout << "������Ա��������������:";
					cin >> p->data.staffMonthSaleQuantity;
				}
				else if (strcmp(g, "5") == 0)
				{
					cout << "�޸�ǰ�������۽�" << p->data.staffMonthSaleAmount << endl;
					cout << "�����뵱�����۽��:";
					cin >> p->data.staffMonthSaleAmount;
				}
				else if (strcmp(g, "6") == 0)
				{
					cout << "�޸�ǰ�ۼ�����������" << p->data.staffTotalSaleQuantity << endl;
					cout << "�������ۼ���������:";
					cin >> p->data.staffTotalSaleQuantity;
				}
				else if (strcmp(g, "7") == 0)
				{
					cout << "�޸�ǰ�ۼ����۽�" << p->data.staffTotalSaleAmount << endl;
					cout << "�������ۼ����۽��:";
					cin >> p->data.staffTotalSaleAmount;
					cout << "�޸ĺ���ϢΪ��" << "��ţ�" << p->data.staffNumber << endl << "������" << p->data.staffName << endl << "�Ա�" << p->data.staffgender << endl << "��������������" << p->data.staffMonthSaleQuantity << endl << "�������۽�" << p->data.staffMonthSaleAmount << endl << "�ۼ�����������" << p->data.staffTotalSaleQuantity << endl << "�ۼ����۽��" << p->data.staffTotalSaleAmount << endl;
				}
				else
				{
					cout << "�������" << endl;
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
					StaffModify(head);
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
	else if (strcmp(b, "3") == 0 )
	{
		return head;
	}

}


//Ա����ѯ
int Staffearch(StaffNode* head)
{
	StaffOutput(head);
	char ch[10] = "0";     //�����ж��Ƿ��������
	char choice[10] = "0";//ѡ���ѯ��ʽ
	char cho[10] = "0";//ѡ���ѯ����	
	int i = 0;//forѭ������
	char snum[4] = "0";
	char snam[20] = "0";
	char sgen[5] = "0";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                        *******��ѡ����Ҫ��ѯ�ķ�ʽ��*******" << endl;
	cout << "\t\t                       *******      1-->��ȷ����      *******" << endl;
	cout << "\t\t                       *******      2-->��Χ����      *******" << endl;
	cout << "\t\t                        *******     3-->�������˵�   *******" << endl;
	cout << "\t\t                           ******************************" << endl;
	cout << "\t\t                      ����������ѡ��(1-3):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> choice;
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		StaffOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                          *******  ��ѡ���ѯ����:  *******" << endl;
		cout << "\t\t                         *******    1-->��Ա�����    *******" << endl;
		cout << "\t\t                        ******      2-->��Ա���Ա�       *******" << endl;
		cout << "\t\t                         *******    3-->��Ա������    *******" << endl;
		cout << "\t\t                          *******   4-->�������˵�   *******" << endl;
		cout << "\t\t                           *****************************" << endl;
		cout << "\t\t                       ����������ѡ��1-3��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout << "          ������Ա�����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> snum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			StaffNode* p = NULL;//p�ǲ���λ��
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "��Ա����Ϣ!" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}
			p = head;
			while (p != NULL && strcmp(snum, p->data.staffNumber) != 0)
			{
				p = p->next;
				i++;
			}
			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ��Ա��������" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}
			else
			{
				cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
					<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << setw(3) << p->data.staffNumber << '\t'
					<< setw(3) << p->data.staffName << '\t'
					<< setw(3) << p->data.staffgender << '\t'
					<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
					<< setw(8) << p->data.staffMonthSaleAmount << '\t'
					<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
					<< setw(8) << p->data.staffTotalSaleAmount << '\t'
					<< endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          ������Ա���Ա�:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> sgen;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			StaffNode* p = NULL;//p�ǲ���λ��
			int i = 0;//λ�����
			int length = 0;//Ա��������
			if (head == NULL)//����ǿ�����
			{
				cout << "��Ա����Ϣ!" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}

			p = head;
			while (p != NULL && strstr(sgen, p->data.staffgender) != 0)
			{
				length = length + 1;
				p = p->next;
				i++;
			}
			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ��Ա��������" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}
			else
			{
				cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
					<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
				cout << endl;
				int j = 0;
				for (p = head; p != NULL; p = p->next)
				{
					char* s = NULL;
					s = strstr(p->data.staffgender, sgen);
					j = j + 1;
					if (j == 0)
					{
						cout << "û�и�Ա��" << endl;
					}
					else if (s != NULL)
					{

						cout << setw(3) << p->data.staffNumber << '\t'
							<< setw(3) << p->data.staffName << '\t'
							<< setw(3) << p->data.staffgender << '\t'
							<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
							<< setw(8) << p->data.staffMonthSaleAmount << '\t'
							<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
							<< setw(8) << p->data.staffTotalSaleAmount << '\t'
							<< endl;
					}
				}
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          ������Ա������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> snam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			StaffNode* p = NULL;//p�ǲ���λ��
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "��Ա����Ϣ!" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}
			p = head;
			while (p != NULL && strcmp(snam, p->data.staffName) != 0)
			{
				p = p->next;
				i++;
			}
			if (p == NULL)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ��Ա��������" << endl;
				cout << "�밴���������" << endl;
				_getch();
			}
			else
			{
				cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
					<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << setw(3) << p->data.staffNumber << '\t'
					<< setw(3) << p->data.staffName << '\t'
					<< setw(3) << p->data.staffgender << '\t'
					<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
					<< setw(8) << p->data.staffMonthSaleAmount << '\t'
					<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
					<< setw(8) << p->data.staffTotalSaleAmount << '\t'
					<< endl;

			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "\t\t                           �������˵�!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			system("cls");
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                         ѡ�����\n" << endl;
		}
	}
	if (strcmp(choice, "2") == 0)
	{
		StaffOutput(head);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "\t\t                          ***********************************" << endl;
		cout << "\t\t                        *******      ��ѡ���ѯ��ʽ:    *******" << endl;
		cout << "\t\t                      *******    1-->��Ա��������������    *******" << endl;
		cout << "\t\t                      *******    2-->��Ա���������۽��   *******" << endl;
		cout << "\t\t                      *******    3-->��Ա���ۼ���������   *******" << endl;
		cout << "\t\t                       *******   4-->��Ա���ۼ����۽��  *******" << endl;
		cout << "\t\t                        *******  5-->�������˵�         *******" << endl;
		cout << "\t\t                          ***********************************" << endl;
		cout << "\t\t                      ����������ѡ��1-5��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> cho;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		int sq1 = 0;//����������������
		int sq2 = 0;//����������������
		int tq1 = 0;//�������۽������
		int tq2 = 0;//�������۽������
		float ssq1 = 0;//�ۼ������������� 
		float ssq2 = 0;//�ۼ������������� 
		float ssa1 = 0;//�ۼ����۽������ 
		float ssa2 = 0;//�ۼ����۽������ 
		char a[10] = "0";
		if (strcmp(cho, "1") == 0)
		{
			cout << "          ��������͵�����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> sq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "          ��������ߵ�����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> sq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			while (sq1 > sq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "                       �Ƿ����루���>���)������������!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout << "\t\t                      *******    Y-->��������    *******" << endl;
				cout << "\t\t                       *******   N-->�������˵� *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "                 �������!����������:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return 0;
				}
				cout << "          ��������͵�����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> sq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "          ��������ߵ�����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> sq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			struct StaffNode* p = NULL;//p�ǲ���λ��
			int length = 0;//Ա����������
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "��Ա����Ϣ��" << endl;
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
				if (sq1 <= p->data.staffMonthSaleQuantity && sq2 >= p->data.staffMonthSaleQuantity)
				{
					if (i == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						i++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "û�и÷�Χ�ڵ�Ա��" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          ��������͵������۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> tq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "          ��������ߵ������۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> tq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			while (tq1 > tq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "                       �Ƿ����루���>���)������������!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout << "\t\t                      *******    Y-->��������    *******" << endl;
				cout << "\t\t                       *******   N-->�������˵� *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "                 �������!����������:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return 0;
				}
				cout << "          ��������͵������۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> tq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "          ��������ߵ������۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> tq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			struct StaffNode* p = NULL;//p�ǲ���λ��
			int length = 0;//Ա����������
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "��Ա����Ϣ��" << endl;
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
				if (tq1 <= p->data.staffMonthSaleAmount && tq2 >= p->data.staffMonthSaleAmount)
				{
					if (i == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						i++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "û���ڸ÷�Χ�ڵ�Ա��" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          ����������ۼ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> ssq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "          ����������ۼ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> ssq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			while (ssq1 > ssq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "                       �Ƿ����루���>���)������������!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout << "\t\t                      *******    Y-->��������    *******" << endl;
				cout << "\t\t                       *******   N-->�������˵� *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "                 �������!����������:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return 0;
				}
				cout << "          ����������ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> ssq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "          ����������ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> ssq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			struct StaffNode* p = NULL;//p�ǲ���λ��
			int length = 0;//Ա����������
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "��Ա����Ϣ��" << endl;
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
				if (ssq1 <= p->data.staffTotalSaleQuantity && ssq2 >= p->data.staffTotalSaleQuantity)
				{
					if (i == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						i++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "û���ڸ÷�Χ�ڵ�Ա��" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          ����������ۼ����۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> ssa1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "          ����������ۼ����۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> ssa2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			while (ssa1 > ssa2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "                       �Ƿ����루���>���)������������!" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout << "\t\t                      *******    Y-->��������    *******" << endl;
				cout << "\t\t                       *******   N-->�������˵� *******" << endl;
				cout << "\t\t                         ****************************" << endl;
				cout << "\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "                 �������!����������:";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				}
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return 0;
				}
				cout << "          ����������ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> ssa1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "          ����������ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> ssa2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			struct StaffNode* p = NULL;//p�ǲ���λ��
			int length = 0;//Ա����������
			int i = 0;//λ�����
			if (head == NULL)//����ǿ�����
			{
				cout << "��Ա����Ϣ��" << endl;
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
				if (ssa1 <= p->data.staffTotalSaleAmount && ssa2 >= p->data.staffTotalSaleAmount)
				{
					if (i == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						i++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << setw(3) << p->data.staffNumber << '\t'
						<< setw(3) << p->data.staffName << '\t'
						<< setw(3) << p->data.staffgender << '\t'
						<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
						<< setw(8) << p->data.staffMonthSaleAmount << '\t'
						<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
						<< setw(8) << p->data.staffTotalSaleAmount << '\t'
						<< endl;
					j++;
				}
			}
			if (j == 0)
			{
				cout << "û���ڸ÷�Χ�ڵ�Ա��" << endl;
				_getch();
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "�������˵�!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			system("cls");
			return 0;
		}
		else if (strcmp(cho, "1") != 0 && strcmp(cho, "2") != 0 && strcmp(cho, "3") != 0 && strcmp(cho, "4") != 0 && strcmp(cho, "5") != 0 && strcmp(cho, "6") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "\t\t                                          ѡ�����!\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
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
		Staffearch(head);
	}
	if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		return 0;
	}
}



//���ݵ�����������/�������۽��/�ۼ���������/�ۼ����۽�������
void StaffSelectionSort(StaffNode* head)
{
	system("cls");//����
	StaffNode* p = NULL;
	StaffNode* q = NULL;
	StaffNode* r = NULL;
	StaffNode* k = NULL;
	Staff temp1;
	Staff temp2;
	int i = 0;
	char cho[10] = "0";//��������ѡ��
	char choi[10] = "0";//�ж��Ƿ�����鿴Ա������
	cout << "\t\t            *****************************************************************" << endl;
	cout << "\t\t           *******************            ��ѡ����������:      ***************" << endl;
	cout << "\t\t          *****************         1-->��Ա��������������      ***************" << endl;
	cout << "\t\t         *****************          2-->��Ա���������۽��       ***************" << endl;
	cout << "\t\t         ******************         3-->��Ա���ۼ���������       ***************" << endl;
	cout << "\t\t           *****************        4-->��Ա���ۼ����۽��     ***************" << endl;
	cout << "\t\t            *****************       5-->�������˵�            ***************" << endl;
	cout << "\t\t             ***************************************************************" << endl;
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
	if (strcmp(cho, "1") == 0) //�����������������򣬲���ֱ�Ӳ�������
	{

		cout << "\t\t���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		//q = (StaffNode*)malloc(sizeof(StaffNode));//Ϊ�������ڴ浥Ԫ
		q = new StaffNode;
		q->next = head;//q����һ�ڵ�ָ��ͷ���
		head = q;//��ͷ�����Ϊ��
		p = head->next->next;//��ָ��p������δ����Ԫ�ص���Ϣ
		head->next->next = NULL;//ʹ��ԭ����������������ǰ����һ��Ԫ��
		while (p != NULL)//����������
		{
			k = p->next;//����λ��
			r = head;//��ָ��ָ��������
			while (r->next != NULL && r->next->data.staffMonthSaleQuantity > p->data.staffMonthSaleQuantity)//�ж�ָ��ָ�����һ��Ԫ����������ȡ��Ԫ�صĴ�С
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
			cout <<"\t\t" << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;
			p = p->next;//ָ����һ�����
		}
	}
	else if (strcmp(cho, "2") == 0)//���������۽�����򣬲���ð�������³�����
	{

		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		p = head;
		while (p != q)
		{
			while (p->next != q)
			{
				if (p->data.staffMonthSaleAmount < p->next->data.staffMonthSaleAmount) //�Ƚ���������ֵ�����������򽻻�
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
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;
			p = p->next;//ָ����һ�����
		}
	}
	else if (strcmp(cho, "3") == 0)//���ۼ������������򣬲���ֱ��ѡ������
	{

		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
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
				if (p->data.staffTotalSaleQuantity > temp1.staffTotalSaleQuantity)
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
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
				<< endl;
			p = p->next;//ָ����һ�����
		}
	}
	else if (strcmp(cho, "4") == 0) //���ۼ����۽�����򣬲���ֱ��ѡ������
	{
		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
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
				if (p->data.staffTotalSaleAmount > temp1.staffTotalSaleAmount)
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
			cout << setw(3) << p->data.staffNumber << '\t'
				<< setw(3) << p->data.staffName << '\t'
				<< setw(3) << p->data.staffgender << '\t'
				<< setw(8) << p->data.staffMonthSaleQuantity << '\t'
				<< setw(8) << p->data.staffMonthSaleAmount << '\t'
				<< setw(8) << p->data.staffTotalSaleQuantity << '\t'
				<< setw(8) << p->data.staffTotalSaleAmount << '\t'
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
		cout << "\t\t                           *******  �Ƿ�����鿴Ա������*******" << endl;
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
			StaffSelectionSort(head);
		}
		i++;
	}
}
