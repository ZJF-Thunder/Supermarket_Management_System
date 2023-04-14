//#define _CRT_SECURE_NO_WARNNINGS //���⾯��
#ifndef _STAFFDATA_//����ͷ�ļ����ظ�����
#define _STAFFDATA_
#include"Class.h"
#include<iostream>
#include<windows.h>//����̨�����Ҫͷ�ļ�
#include<iomanip>//�õ�setw()����
#include<conio.h>//_getch()
#endif
using namespace std;

StaffData::StaffData()
{
	size = 0;
}

//Ա�����캯����ʵ��   ���ݳ�Ա��ʼ��
StaffData::StaffData(Staff *Sf,int m)
{
	int i=0;//ѭ�����Ʊ���
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

//Ա������������ʵ�� 
StaffData::~StaffData()
{

}


//�����ļ�����   ������������ݵ��ļ���
bool StaffData::SaveFile()
{
	FILE *fp;//����д��,�����ļ�ָ��
	int i = 0;
	char isSave[10] = "0" ;//�Ƿ񱣴����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout<<"�Ƿ񱣴棿(Y/N):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
	cin>> isSave;
	while (strcmp(isSave, "Y") != 0 && strcmp(isSave, "y") != 0 && strcmp(isSave, "N") != 0 && strcmp(isSave, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<< "�����������������:" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cin >> isSave;
	} 

	if (strcmp(isSave, "N") == 0 || strcmp(isSave, "n") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			cout<<"�����ļ�ʧ��!"<<endl;
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
		cout << "������" << i << "��Ա������Ϣ���ļ��У�" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		fclose(fp);
		return true;
	}
}

//��ȡ���ݺ���   ��ȡ�ļ��е����ݵ��ڴ���
bool StaffData::ReadFile()
{
	FILE *fp;//�ļ�ָ��
	int i=0;//ѭ������
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
	cout << "����ȡ" << size << "��Ա������Ϣ���ڴ��У�" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	fclose(fp);
	return true;
	//return 1;
}


//���ӣ����룩Ա������Ϣ
void StaffData::input(StaffData *St, Staff *Sf,int m)
{
	St->ReadFile();//��ȡ�ļ��е����ݵ��ڴ���
	if (size != 0)
	{
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                        *******��ȷ���Ƿ�Ϊ�������(Y or N)*******" << endl;
		cout << "\t\t                       *******       �� Y �������˵�        *******" << endl;
		cout << "\t\t                        *******       �� N ��������        *******" << endl;
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                       ����������ѡ��:";
		char a[10] = "0" ;//ȷ�����������
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cin >> a ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout<< "�����������������:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cin >> a;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		} 
		if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout << "���������ӵ�Ա������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cin >> m;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
			Sf = new Staff[m];
			/*��������ټ�һ��ѯ���û��Ƿ���Ҫ����Ա���������Ĺ��ܣ����Ǵ���Ա���������������Ҫ���ĵĿ����ԣ�*/
			system("cls");//���� 

			//size = m;

			//data = new StaffData[size];//Ա���ද̬���� 
			for (int i = 0; i < m; i++)
			{

				cout << "�������" << i + 1 << "��Ա���ı��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "�������" << i + 1 << "��Ա��������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "�������" << i + 1 << "��Ա�����Ա�:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffgender;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "�������"<< i + 1 <<"��Ա���ĵ�����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffMonthSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "�������"<< i + 1 <<"��Ա���ĵ������۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffMonthSaleAmount;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "�������"<< i + 1 <<"��Ա�����ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffTotalSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout << "�������"<< i + 1 <<"��Ա�����ۼ����۽�� :";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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
			cout << "������" << m << "��Ա������Ϣ��" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			size = size + m;
			St->SaveFile(); //�������ݵ��ļ���
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
		cout << "\t\t                        *******��ȷ���Ƿ�Ϊ�������(Y or N)*******" << endl;
		cout << "\t\t                       *******       �� Y �������˵�        *******" << endl;
		cout << "\t\t                        *******       �� N ��������        *******" << endl;
		cout << "\t\t                           ************************************" << endl;
		cout << "\t\t                       ����������ѡ��:";
		char b[10] = "0" ;//ȷ�����������
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cin >> b ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<< "�����������������:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> b;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		} 
		if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0 )
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "���������ӵ�Ա������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> m;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			Sf = new Staff[m];//��̬�ڴ��������
			/*��������ټ�һ��ѯ���û��Ƿ���Ҫ����Ա���������Ĺ��ܣ����Ǵ���Ա���������������Ҫ���ĵĿ����ԣ�*/
			system("cls");//���� 

			//size = m;

			//data = new StaffData[size];//Ա���ද̬���� 


			for (int i = 0; i < m; i++)
			{

				cout << "�������" << i + 1 << "��Ա���ı��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "��Ա��������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "��Ա�����Ա�:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffgender;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"��Ա���ĵ�����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffMonthSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"��Ա���ĵ������۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffMonthSaleAmount;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"��Ա�����ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffTotalSaleQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"��Ա�����ۼ����۽�� :";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Sf[i].staffTotalSaleAmount;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ

				strcpy(data[i].staffNumber, Sf[i].staffNumber);
				strcpy(data[i].staffName, Sf[i].staffName);
				strcpy(data[i].staffgender, Sf[i].staffgender);
				data[i].staffMonthSaleQuantity = Sf[i].staffMonthSaleQuantity;
				data[i].staffMonthSaleAmount = Sf[i].staffMonthSaleAmount;
				data[i].staffTotalSaleQuantity = Sf[i].staffTotalSaleQuantity;
				data[i].staffTotalSaleAmount = Sf[i].staffTotalSaleAmount;
			
			//system("cls");
			}
			cout << "������" << m << "��Ա������Ϣ��" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			size = size + m;
			St->SaveFile(); //�������ݵ��ļ���
			delete []Sf;
			//system("pause");	
		}
		else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
		{
			return ;
		}
	}

}

//���Ա������Ϣ
void StaffData::output(StaffData *St)
{
	St->ReadFile();
	if (size != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�밴���������"  <<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		_getch();
	}

	else if (size = 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout<< "�ܱ�Ǹ���ļ���û����Ʒ��Ϣ�����������Ʒ��Ϣ��" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�밴���������"  <<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		_getch();
		return ;
	}
	cout << endl;
	//system("pause");
}


//ɾ��Ա����Ϣģ��
void StaffData::del(StaffData *St)
{
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******��ȷ���Ƿ�Ϊ�������(Y or N)*******" << endl;
	cout << "\t\t                       *******       �� Y �������˵�        *******" << endl;
	cout << "\t\t                        *******       �� N ��������        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       ����������ѡ��:";
	char a[10] = "0" ;//ȷ�����������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> a ;
	while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout<< "�����������������:" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> a;
	} 
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
	{
		St->output(St);

		char choose[10] = "0";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "************��ӭ����ɾ��Ա����Ϣģ��************\n";
		cout<<"*************   ��ѡ��ɾ����ʽ   *************"<<endl;
    	cout<<"*************  1  ��Ա�����     *************"<<endl;
    	cout<<"*************  2  ��Ա������     *************"<<endl;
    	cout<<"************* ����������ѡ�� 1 or 2 ***********\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	    cin >> choose;
		while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "�����������������:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> choose;
		} 
		if (strcmp(choose, "1") == 0)
		{
			char StaffData[8];//��Ҫɾ����Ա����� 
            int k = 0;//�����ж��Ƿ��ҵ��˸�Ա��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	        cout << "����������Ҫɾ����Ա�����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
            cin >> StaffData;//������Ҫɾ����Ա�����
            //search();
            int num = 0;//Ѱ��Ա�������ͬʱ���±�
            int i = 0;//��������Ա����ŵ��±�
            for (i = 0; i < size; i++)
			{
				if (strcmp(StaffData, data[i].staffNumber) == 0)//�ж������Ա������Ƿ�Ϳ�����һ��
				{
					num = i;
					for (int j = num; j < size; j++)
					{
						data[j] = data[j + 1];//�������Ա��������ǰ��
					}
					size = size - 1;
					k = k + 1;
					break;
				}
			}
			if(k > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "*************       ɾ���ɹ���      *************" << endl;
				St->SaveFile();
				cout << "***********   �Ƿ����ɾ����Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "************* �Բ���û���ҵ���Ա�� *************" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "***********   �Ƿ����ɾ����Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
			char StaffName[8];//��Ҫɾ����Ա������ 
            int m = 0;//�����ж��Ƿ��ҵ��˸�Ա��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	        cout << "����������Ҫɾ����Ա��������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
            cin >> StaffName;//������Ҫɾ����Ա������
            //search();
            int num2 = 0;//Ѱ��Ա��������ͬʱ���±�
            int i2 = 0;//��������Ա�����Ƶ��±�
            for (i2 = 0; i2 < size; i2++)
			{
				if (strcmp(StaffName, data[i2].staffName) == 0)//�ж������Ա�������Ƿ�Ϳ�����һ��
				{
					num2 = i2;
					for (int j2 = num2; j2 < size; j2++)
					{
		        	    data[j2] = data[j2 + 1];//�������Ա��������ǰ��
					}
					size = size - 1;
					m = m + 1;
					break;
				}
			}
	        if(m > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	         	cout << "*************       ɾ���ɹ���      *************" << endl;
				St->SaveFile();
				cout << "***********   �Ƿ����ɾ����Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "************* �Բ���û���ҵ���Ա�� *************" << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "***********   �Ƿ����ɾ����Y or N):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit;
				while(strcmp(exit, "Y") != 0 && strcmp(exit, "y") != 0 && strcmp(exit, "N") != 0 && strcmp(exit, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return ;
	}
}
 

//�޸�Ա����Ϣ
void StaffData::modify(StaffData* St)
{
	St->ReadFile();
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                        *******��ȷ���Ƿ�Ϊ�������(Y or N)*******" << endl;
	cout << "\t\t                       *******       �� Y �������˵�        *******" << endl;
	cout << "\t\t                        *******       �� N ��������        *******" << endl;
	cout << "\t\t                           ************************************" << endl;
	cout << "\t\t                       ����������ѡ��:";
	char a[10] = "0";//ȷ�����������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> a;
	while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�����������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> a;
	}
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
	{

		int f1 = 0;
		int i = 0;;
		int n = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "���ҷ�ʽ ��1.��� 2.����" << endl;
		int m = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> m;
		switch (m)
		{
		case 1:
			char Number[4];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "����������Ҫ�޸�Ա�����" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> Number;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i++)//�����������Ʒ
			{

				if ((strcmp(Number, data[i].staffNumber) == 0))
				{
					n = 1;
					cout << "�޸���ϢΪ:" << endl;

					cout << "Ա�����:" << data[i].staffNumber << endl;

					cout << "Ա������:" << data[i].staffName << endl;

					cout << "Ա���Ա�:" << data[i].staffgender << endl;

					cout << "Ա���ĵ�����������:" << data[i].staffMonthSaleQuantity << endl;

					cout << "Ա���ĵ������۽��:" << data[i].staffMonthSaleAmount << endl;

					cout << "Ա�����ۼ���������:" << data[i].staffTotalSaleQuantity << endl;

					cout << "Ա�����ۼ����۽��:" << data[i].staffTotalSaleAmount << endl;

					cout << "��ȷ���Ƿ��޸ĸ�Ա������Ϣ��Y or N����";
					char check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					if (check == 'Y' || check == 'y')
					{
						cout << "ȫ���޸�����1���ֲ��޸�����2:" << endl;
						int z = 0;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
						cin >> z;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
						if (z == 1)
						{
							cout << "�޸�ǰԱ����ţ�" << data[i].staffNumber << endl;
							cout << "������Ա�����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ�����ƣ�" << data[i].staffName << endl;
							cout << "������Ա������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���Ա�" << data[i].staffgender << endl;
							cout << "������Ա���Ա�:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffgender;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ����������������" << data[i].staffMonthSaleQuantity << endl;
							cout << "������Ա���ĵ�����������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffMonthSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���������۽�" << data[i].staffMonthSaleAmount << endl;
							cout << "������Ա���ĵ������۽��:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffMonthSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���ۼ�����������" << data[i].staffTotalSaleQuantity << endl;
							cout << "������Ա�����ۼ���������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffTotalSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���ۼ����۽�" << data[i].staffTotalSaleAmount << endl;
							cout << "������Ա�����ۼ����۽��:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffTotalSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> f1;
							if (f1)
							{
								modify(St);
							}
						}
						else if (z == 2)
						{
							cout << "������Ҫ�޸ĵı�ţ�" << endl;
							cout << "1.Ա�����" << endl << "2.Ա������" << endl << "3.Ա���Ա�" << endl << "4.Ա���ĵ�����������" << endl << "5.Ա���ĵ������۽��" << endl << "6.Ա�����ۼ���������" << endl << "7.Ա�����ۼ����۽��" << endl;
							int k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							switch (k)
							{
							case 1:
								cout << "�޸�ǰԱ����ţ�" << data[i].staffNumber << endl;
								cout << "������Ա�����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;

							case 2:
								cout << "�޸�ǰԱ�����ƣ�" << data[i].staffName << endl;
								cout << "������Ա������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 3:
								cout << "�޸�ǰԱ���Ա�" << data[i].staffgender << endl;
								cout << "������Ա���Ա�:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffgender;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 4:
								cout << "�޸�ǰԱ����������������" << data[i].staffMonthSaleQuantity << endl;
								cout << "������Ա���ĵ�����������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffMonthSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 5:
								cout << "�޸�ǰԱ���������۽�" << data[i].staffMonthSaleAmount << endl;
								cout << "������Ա���ĵ������۽��:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffMonthSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 6:
								cout << "�޸�ǰԱ���ۼ�����������" << data[i].staffTotalSaleQuantity << endl;
								cout << "������Ա�����ۼ���������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffTotalSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 7:
								cout << "�޸�ǰԱ���ۼ����۽�" << data[i].staffTotalSaleAmount << endl;
								cout << "������Ա�����ۼ����۽��:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffTotalSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�޸ĳɹ�" << endl;
				}

				else if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�Ҳ����޸ĵ�Ŀ��" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			St->SaveFile();
			break;

		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "����������Ҫ�޸�Ա�����֣�" << endl;
			char Name[20];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> Name;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i++)//�����������Ʒ
			{

				if ((strcmp(Name, data[i].staffName) == 0))
				{
					n = 1;
					cout << "�޸���ϢΪ:" << endl;

					cout << "Ա�����:" << data[i].staffNumber << endl;

					cout << "Ա������:" << data[i].staffName << endl;

					cout << "Ա���Ա�:" << data[i].staffgender << endl;

					cout << "Ա���ĵ�����������:" << data[i].staffMonthSaleQuantity << endl;

					cout << "Ա���ĵ������۽��:" << data[i].staffMonthSaleAmount << endl;

					cout << "Ա�����ۼ���������:" << data[i].staffTotalSaleQuantity << endl;

					cout << "Ա�����ۼ����۽��:" << data[i].staffTotalSaleAmount << endl;

					cout << "��ȷ���Ƿ��޸ĸ���Ʒ����Ϣ��Y or N����";
					char check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> check;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					if (check == 'Y' || check == 'y')
					{
						cout << "ȫ���޸�����1���ֲ��޸�����2:" << endl;
						int z;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
						cin >> z;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
						if (z == 1)
						{
							cout << "�޸�ǰԱ����ţ�" << data[i].staffNumber << endl;
							cout << "������Ա�����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ�����ƣ�" << data[i].staffName << endl;
							cout << "������Ա������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���Ա�" << data[i].staffgender << endl;
							cout << "������Ա���Ա�:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffgender;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ����������������" << data[i].staffMonthSaleQuantity << endl;
							cout << "������Ա���ĵ�����������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffMonthSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���������۽�" << data[i].staffMonthSaleAmount << endl;
							cout << "������Ա���ĵ������۽��:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffMonthSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���ۼ�����������" << data[i].staffTotalSaleQuantity << endl;
							cout << "������Ա�����ۼ���������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffTotalSaleQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰԱ���ۼ����۽�" << data[i].staffTotalSaleAmount << endl;
							cout << "������Ա�����ۼ����۽��:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].staffTotalSaleAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> f1;
							if (f1)
							{
								modify(St);
							}
						}
						else if (z == 2)
						{
							cout << "������Ҫ�޸ĵı�ţ�" << endl;
							cout << "1.Ա�����" << endl << "2.Ա������" << endl << "3.Ա���Ա�" << endl << "4.Ա���ĵ�����������" << endl << "5.Ա���ĵ������۽��" << endl << "6.Ա�����ۼ���������" << endl << "7.Ա�����ۼ����۽��" << endl;
							int k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							switch (k)
							{
							case 1:
								cout << "�޸�ǰԱ����ţ�" << data[i].staffNumber << endl;
								cout << "������Ա�����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;

							case 2:
								cout << "�޸�ǰԱ�����ƣ�" << data[i].staffName << endl;
								cout << "������Ա������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 3:
								cout << "�޸�ǰԱ���Ա�" << data[i].staffgender << endl;
								cout << "������Ա���Ա�:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffgender;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 4:
								cout << "�޸�ǰԱ����������������" << data[i].staffMonthSaleQuantity << endl;
								cout << "������Ա���ĵ�����������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffMonthSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 5:
								cout << "�޸�ǰԱ���������۽�" << data[i].staffMonthSaleAmount << endl;
								cout << "������Ա���ĵ������۽��:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffMonthSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 6:
								cout << "�޸�ǰԱ���ۼ�����������" << data[i].staffTotalSaleQuantity << endl;
								cout << "������Ա�����ۼ���������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffTotalSaleQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(St);
								}
								break;
							case 7:
								cout << "�޸�ǰԱ���ۼ����۽�" << data[i].staffTotalSaleAmount << endl;
								cout << "������Ա�����ۼ����۽��:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].staffTotalSaleAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�޸ĳɹ�" << endl;
				}

				else if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�Ҳ����޸ĵ�Ŀ��" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			St->SaveFile();
			break;
		}

	}
	else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return;
	}

}


//Ա�����Һ�����ʵ��
StaffData  StaffData::search(StaffData *St)
{
	char ch[10] = "0";     //�����ж��Ƿ��������
	char choice[10] = "0";//ѡ���ѯ��ʽ
	char cho[10] = "0";//ѡ���ѯ����
	int n = 0;//�ж���Ʒ�Ƿ����ʹ��
	int m = 0;//���ڷ�������Ա��ʱ�����һ������ʹ��
	int i = 0;//forѭ������
	char snum[4] = "0";
	char snam[20] = "0";
	char sgen[5] = "0";
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                        *******��ѡ����Ҫ��ѯ�ķ�ʽ��*******"<<endl;
	cout<<"\t\t                       *******      1-->��ȷ����      *******"<<endl;
	cout<<"\t\t                      *******       2-->ģ������       *******"<<endl;
	cout<<"\t\t                       *******      3-->��Χ����      *******"<<endl;
	cout<<"\t\t                        *******     4-->�������˵�   *******"<<endl;
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                      ����������ѡ��(1-4):"; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin>>choice;
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		//Ա����ȷ����
		ReadFile();
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                          *******  ��ѡ���ѯ����:  *******"<<endl;
		cout<<"\t\t                        *******     1-->��Ա�����    *******"<<endl;
		cout<<"\t\t                       *******      2-->��Ա������     *******"<<endl;
		cout<<"\t\t                        *******     3-->��Ա���Ա�    *******"<<endl;
		cout<<"\t\t                         *******    4-->�������˵�   *******"<<endl;
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                       ����������ѡ��1-4��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin>>cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout<<"          ������Ա�����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>snum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(strcmp(snum,data[i].staffNumber)==0)
				{
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        ��Ա��������"<<endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout<<"          ������Ա������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>snam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(strcmp(snam,data[i].staffName)==0)
				{
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        ��Ա��������"<<endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout<<"          ������Ա���Ա�:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>sgen;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(strcmp(sgen,data[i].staffgender)==0)
				{
				
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        ��Ա��������"<<endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "\t\t                           �������˵�!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			system("cls");
			return *St;
		}
		else
		{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t                         ѡ�����\n"<<endl;
		}
	}

	else if (strcmp(choice, "2") == 0)
	{
		//Ա��ģ������
		ReadFile();
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                         *******  ��ѡ���ѯ��ʽ:  *******"<<endl;
		cout<<"\t\t                        *******    1-->��Ա�����   *******"<<endl;
		cout<<"\t\t                        *******    2-->��Ա������   *******"<<endl;
		cout<<"\t\t                         *******   3-->�������˵�  *******"<<endl;
		cout<<"\t\t                           ******************************" << endl;
		cout<<"\t\t                        ����������ѡ��1-3��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin>>cho;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		if (strcmp(cho, "1") == 0)
		{
			cout<<"          ������Ա����Źؼ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>snum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(strstr(data[i].staffNumber,snum)!=NULL)
				{
				
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        �ؼ��ʲ����ڣ�"<<endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout<<"          ������Ա�����ƹؼ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>snam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(strstr(data[i].staffName,snam)!=NULL)
				{
				
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        �ؼ��ʲ����ڣ�"<<endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "�������˵�!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			system("cls");
			return *St;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<<"\t\t                                    ѡ�����\n"<<endl;
		}
	}
	else if (strcmp(choice, "3") == 0)//Ա����Χ����
	{
		ReadFile();
		int smsq1 = 0;
		int smsq2 = 0;
		int stsq1 = 0;
		int stsq2 = 0;//����������������/����������������/�������۽������/�������۽������
		float smsa1 = 0;
		float smsa2 = 0;
		float stsa1 = 0;
		float stsa2 = 0;//�ۼ�������������/�ۼ�������������/�ۼ����۽������/�ۼ����۽������
		char a[10] = "0";
		cout<<"\t\t                          ***********************************" << endl;
		cout<<"\t\t                        *******      ��ѡ���ѯ��ʽ:    *******"<<endl;
		cout<<"\t\t                       *******   1-->��Ա��������������  *******"<<endl;
		cout<<"\t\t                      *******    2-->��Ա���������۽��   *******"<<endl;
		cout<<"\t\t                      *******    3-->��Ա���ۼ���������   *******"<<endl;
		cout<<"\t\t                       *******   4-->��Ա���ۼ����۽��  *******"<<endl;
		cout<<"\t\t                        *******  5-->�������˵�         *******"<<endl;
		cout<<"\t\t                          ***********************************" << endl;
		cout<<"\t\t                      ����������ѡ��1-5��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin>>cho;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout<<"          ��������͵�����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>smsq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<<"          ��������ߵ�����������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>smsq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			while(smsq1 > smsq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                           �Ƿ����루���>���)������������!"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout<<"\t\t                      *******    Y-->��������    *******" << endl;
				cout<<"\t\t                       *******   N-->�������˵� *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< "                 �������!����������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return *St;
				}
				cout<<"          ��������͵�����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>smsq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"          ��������ߵ�����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>smsq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(smsq1 <=data[i].staffMonthSaleQuantity && smsq2 >= data[i].staffMonthSaleQuantity)
				{
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        �����ڷ���������Ա����Ϣ��"<<endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout<<"          ��������͵������۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>smsa1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<<"          ��������ߵ������۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>smsa2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			while(smsa1 > smsa2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"                       �Ƿ����루���>���)������������!"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout<<"\t\t                      *******    Y-->��������    *******" << endl;
				cout<<"\t\t                       *******   N-->�������˵� *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< "                 �������!����������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return *St;
				}
				cout<<"          ��������͵������۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>smsa1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"          ��������ߵ������۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>smsa2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(smsa1 <=data[i].staffMonthSaleAmount && smsa2 >= data[i].staffMonthSaleAmount)
				{
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        �����ڷ���������Ա����Ϣ��"<<endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout<<"          ����������ۼ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>stsq1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<<"          ����������ۼ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>stsq2;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			while(stsq1 > stsq2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"               �Ƿ����루���>���)�����������룡"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout<<"\t\t                      *******    Y-->��������    *******" << endl;
				cout<<"\t\t                       *******   N-->�������˵� *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< "                 �������!����������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return *St;
				}
				cout<<"          ����������ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>stsq1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"          ����������ۼ���������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>stsq2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(stsq1 <=data[i].staffTotalSaleQuantity && stsq2 >= data[i].staffTotalSaleQuantity)
				{
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        �����ڷ���������Ա����Ϣ��"<<endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout<<"          ����������ۼ����۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>stsa1;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<<"          ����������ۼ����۽��:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin>>stsa2;
			while(stsa1 > stsa2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"                     �Ƿ����루���>���)�����������룡"<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                       ******* �Ƿ������Χ���ң�******" << endl;
				cout<<"\t\t                      *******    Y-->��������    *******" << endl;
				cout<<"\t\t                       *******   N-->�������˵� *******" << endl;
				cout<<"\t\t                         ****************************" << endl;
				cout<<"\t\t                      ����������ѡ��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>a;
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				while (strcmp(a, "Y") != 0 && strcmp(a, "y") != 0 && strcmp(a, "N") != 0 && strcmp(a, "n") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< "                 �������!����������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> a;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				} 
				if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return *St;
				}
				cout<<"          ����������ۼ����۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>stsa1;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"          ����������ۼ����۽��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin>>stsa2;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			}
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if(stsa1 <=data[i].staffTotalSaleAmount && stsa2 >= data[i].staffTotalSaleAmount)
				{
					if(m == 0)//Ա�����ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
							<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"\t\t        �����ڷ���������Ա����Ϣ��"<<endl;
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "�������˵�!" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			system("cls");
			return *St;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<<"\t\t                               ѡ�����\n"<<endl;
		}
	}

	else if (strcmp(choice, "4") == 0)
	{
		cout << "�������˵�!" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		return *St;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<<"\t\t                                          ѡ�����!\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	}
	i = 0; //�����ж���ѡ���Ƿ��������ʱ��ѡ���Ƿ����
	while(strcmp(ch, "Y") != 0 && strcmp(ch, "y") != 0 && strcmp(ch, "N") != 0 && strcmp(ch, "n") != 0)
	{
		if(i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout<<"\t\t                                     �Ƿ����룡���������룡"<<endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<<"\t\t                             *******************************" << endl;
		cout<<"\t\t                           *******   �Ƿ�������ң�    *******"<<endl;
		cout<<"\t\t                         *******      Y-->��������      *******"<<endl;
		cout<<"\t\t                          *******     N-->�������˵�  *******"<<endl;
		cout<<"\t\t                             ******************************" << endl;
		cout<<"\t\t                         ����������ѡ��(Y or N):"; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
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
	cout << "�밴���������"  <<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	_getch();
	return *St;
}


//���ݵ�����������/�������۽��/�ۼ���������/�ۼ����۽�������
void StaffData::selectionSort(StaffData* St, Staff* temp)
{
	system("cls");//����
	St->ReadFile();
	temp = new Staff;
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(cho, "1") == 0)
	{

		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 1; i < size; i++)    //�����������������򣬲���ֱ�Ӳ�������
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

		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)   //���������۽�����򣬲���ð�������³����� 
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

		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)    //���ۼ������������򣬲���ֱ��ѡ������
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
		cout << "���" << '\t' << "����" << '\t' << "�Ա�" << '\t' << "������������" << '\t'
			<< "�������۽��" << '\t' << "�ۼ���������" << '\t' << "�ۼ����۽��" << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)    //���ۼ����۽�����򣬲���ֱ��ѡ������
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
		cout << "\t\t             ѡ�����������ѡ��\n" << endl;
	}
	int i = 0; //�����ж���ѡ���Ƿ��������ʱ��ѡ���Ƿ����
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
			selectionSort(St, temp);
		}
		i++;
	}
	delete temp;
	cout << "�밴���������" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	_getch();
	//system("pause");
}
