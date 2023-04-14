//#define _CRT_SECURE_NO_WARNNINGS //���⾯��
#ifndef _COMMODITYDATA_//����ͷ�ļ����ظ�����
#define _COMMODITYDATA_//����ͷ�ļ����ظ�����
#include"Class.h"
#include<iostream>
#include<windows.h>//����̨�����Ҫͷ�ļ�
#include<iomanip>//�õ�setw()����
#include<conio.h>//_getch()
#endif//����ͷ�ļ����ظ�����
using namespace std;

CommodityData::CommodityData()
{
	size = 0;
	//data = new Commodity[size];
	//Commodity *data = new Commodity[size];//����
}
//��Ʒ���캯����ʵ��   ���ݳ�Ա��ʼ��
CommodityData::CommodityData(Commodity Cd[],int m)
{
	int i = 0;//ѭ�����Ʊ���
	for (i = 0; i < m; i ++)
	{
		strcpy(data[i].commodityNumber, Cd[i].commodityNumber);
		strcpy(data[i].commodityName, Cd[i].commodityName);
		strcpy(data[i].commodityClass, Cd[i].commodityClass);
		strcpy(data[i].commodityPlaceOfOrigin, Cd[i].commodityPlaceOfOrigin);
		strcpy(data[i].commodityManufacturer , Cd[i].commodityManufacturer);
		data[i].commodityPurchasePrice = Cd[i].commodityPurchasePrice;
		data[i].commodityInventoryAmount = Cd[i].commodityInventoryAmount;
		data[i].commodityInventoryQuantity = Cd[i].commodityInventoryQuantity;
		data[i].commodityPurchaseQuantity = Cd[i].commodityPurchaseQuantity;
		data[i].commoditySoldQuantity = Cd[i].commoditySoldQuantity;
		data[i].commodityPrice = Cd[i].commodityPrice;
	}
	size = m;
}

//��Ʒ����������ʵ�� 
CommodityData::~CommodityData()
{

}


//�����ļ�����   ������������ݵ��ļ���
bool CommodityData::SaveFile()
{
	FILE *fp;//����д��,�����ļ�ָ��
	int i = 0;
	char isSave[10] = "0" ;//�Ƿ񱣴����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "�Ƿ񱣴棿(Y/N):";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> isSave;
	while (strcmp(isSave, "Y") != 0 && strcmp(isSave, "y") != 0 && strcmp(isSave, "N") != 0 && strcmp(isSave, "n") != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout<< "�����������������:" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> isSave;
	} 

	if (strcmp(isSave, "N") == 0 || strcmp(isSave, "n") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return 0;
	}
	else if (strcmp(isSave, "Y") == 0 || strcmp(isSave, "y") == 0)
	{
		//fp = fopen("CommodityData.txt","w+");
		fopen_s(&fp, "CommodityData.txt","w+");
		if(!fp)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<<"�����ļ�ʧ��!"<<endl;
			return 0;
		}
		i = 0;
		while(i < size)
		{
			fprintf(fp,"%s\t",data[i].commodityNumber);	
			fprintf(fp,"%s\t",data[i].commodityName);
			fprintf(fp,"%s\t",data[i].commodityClass);
			fprintf(fp,"%s\t",data[i].commodityPlaceOfOrigin);	
			fprintf(fp,"%s\t",data[i].commodityManufacturer);
			fprintf(fp,"%f\t",data[i].commodityPurchasePrice);
			fprintf(fp,"%f\t",data[i].commodityPrice);
			fprintf(fp,"%d\t",data[i].commodityPurchaseQuantity);
			fprintf(fp,"%d\t",data[i].commoditySoldQuantity);
			fprintf(fp,"%d\t",data[i].commodityInventoryQuantity);
			fprintf(fp,"%d\t\n",data[i].commodityInventoryAmount);
			i++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "������" << i << "����Ʒ����Ϣ���ļ��У�" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		fclose(fp);
		return true;
	}
}

//��ȡ���ݺ���   ��ȡ�ļ��е����ݵ��ڴ���
bool CommodityData::ReadFile()
{
	FILE *fp;//�ļ�ָ��
	int i=0;//ѭ������
	fp=fopen("CommodityData.txt","r");
	while(!feof(fp))
	{
		//fscanf_s(fp,"%s\t",data[i].commodityNumber, 8);
		fscanf(fp,"%s\t",data[i].commodityNumber);	
		fscanf(fp,"%s\t",data[i].commodityName);
		fscanf(fp,"%s\t",data[i].commodityClass);
		fscanf(fp,"%s\t",data[i].commodityPlaceOfOrigin);	
		fscanf(fp,"%s\t",data[i].commodityManufacturer);
		fscanf(fp,"%f\t",&data[i].commodityPurchasePrice);
		fscanf(fp,"%f\t",&data[i].commodityPrice);
		fscanf(fp,"%d\t",&data[i].commodityPurchaseQuantity);
		fscanf(fp,"%d\t",&data[i].commoditySoldQuantity);
		fscanf(fp,"%d\t",&data[i].commodityInventoryQuantity);
		fscanf(fp,"%d\t\n",&data[i].commodityInventoryAmount);
		i++;
	}
	size = i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "����ȡ" << size << "����Ʒ����Ϣ���ڴ��У�" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	fclose(fp);
	return true;
}



//���ӣ����룩��Ʒ����Ϣ
void CommodityData::input(CommodityData *Co, Commodity *Cd, int m)
{
	//Co = new CommodityData;
	Co->ReadFile();//��ȡ�ļ��е����ݵ��ڴ���,�õ�size��ֵ
	//ReadFile();
	if (size != 0)
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )
		{
			cout << "���������ӵ���Ʒ����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> m;
			if (m < 0)
			{
				cout << "�Ƿ����룡���������룡" << endl;
				cin >> m;
			}
			Cd = new Commodity[m];//��̬�ڴ����һ����ʱ����������

			/*��������ټ�һ��ѯ���û��Ƿ���Ҫ������Ʒ�������Ĺ��ܣ����Ǵ�����Ʒ�������������Ҫ���ĵĿ����ԣ�*/
			system("cls");//���� 

			//size = m;

			//data = new CommodityData[size];//��Ʒ�ද̬���� 

			for (int i = 0; i < m; i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "����Ʒ�ı��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> (&Cd)[i]->commodityNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "����Ʒ������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "����Ʒ�����:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityClass;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ĳ���:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPlaceOfOrigin;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityManufacturer;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ľ���:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPurchasePrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ���ۼ�:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ľ�������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPurchaseQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commoditySoldQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ŀ������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityInventoryQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"�������"<< i + 1 <<"����Ʒ�Ŀ����:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityInventoryAmount;

				strcpy(data[size+i].commodityNumber, Cd[i].commodityNumber);
				strcpy(data[size+i].commodityName, Cd[i].commodityName);
				strcpy(data[size+i].commodityClass, Cd[i].commodityClass);
				strcpy(data[size+i].commodityPlaceOfOrigin, Cd[i].commodityPlaceOfOrigin);
				strcpy(data[size+i].commodityManufacturer , Cd[i].commodityManufacturer);
				data[size+i].commodityPurchasePrice = Cd[i].commodityPurchasePrice;	
				data[size+i].commodityPrice = Cd[i].commodityPrice;
				data[size+i].commodityPurchaseQuantity = Cd[i].commodityPurchaseQuantity;
				data[size+i].commoditySoldQuantity = Cd[i].commoditySoldQuantity;
				data[size+i].commodityInventoryQuantity = Cd[i].commodityInventoryQuantity;
				data[size+i].commodityInventoryAmount = Cd[i].commodityInventoryAmount;
	
				//system("cls");
			}	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "������" << m << "����Ʒ����Ϣ��" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			size = size + m;
			Co->SaveFile(); //�������ݵ��ļ���
			delete []Cd;
		}
		else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> b ;
		while (strcmp(b, "Y") != 0 && strcmp(b, "y") != 0 && strcmp(b, "N") != 0 && strcmp(b, "n") != 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<< "�����������������:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> b;
		} 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		if (strcmp(b, "N") == 0 || strcmp(b, "n") == 0 )
		{
			cout << "size = " << size<<endl;
			cout << "���������ӵ���Ʒ����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> m;

			Cd = new Commodity[m];//��̬�ڴ����һ����ʱ����������

			/*��������ټ�һ��ѯ���û��Ƿ���Ҫ������Ʒ�������Ĺ��ܣ����Ǵ�����Ʒ�������������Ҫ���ĵĿ����ԣ�*/
			system("cls");//���� 

			for (int i = 0; i < m; i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "����Ʒ�ı��:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityNumber;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "����Ʒ������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityName;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������" << i + 1 << "����Ʒ�����:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityClass;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ĳ���:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPlaceOfOrigin;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityManufacturer;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ľ���:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPurchasePrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ���ۼ�:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPrice;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ľ�������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityPurchaseQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ����������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commoditySoldQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "�������"<< i + 1 <<"����Ʒ�Ŀ������:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityInventoryQuantity;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout<<"�������"<< i + 1 <<"����Ʒ�Ŀ����:";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> Cd[i].commodityInventoryAmount;

				strcpy(data[i].commodityNumber, Cd[i].commodityNumber);
				strcpy(data[i].commodityName, Cd[i].commodityName);
				strcpy(data[i].commodityClass, Cd[i].commodityClass);
				strcpy(data[i].commodityPlaceOfOrigin, Cd[i].commodityPlaceOfOrigin);
				strcpy(data[i].commodityManufacturer , Cd[i].commodityManufacturer);
				data[i].commodityPurchasePrice = Cd[i].commodityPurchasePrice;	
				data[i].commodityPrice = Cd[i].commodityPrice;
				data[i].commodityPurchaseQuantity = Cd[i].commodityPurchaseQuantity;
				data[i].commoditySoldQuantity = Cd[i].commoditySoldQuantity;
				data[i].commodityInventoryQuantity = Cd[i].commodityInventoryQuantity;  
				data[i].commodityInventoryAmount = Cd[i].commodityInventoryAmount;
	
				//system("cls");
			}	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "������" << m << "����Ʒ����Ϣ��" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			size = m;
			Co->SaveFile(); //�������ݵ��ļ���
			//SaveFile();
			delete []Cd;
		}
		else if (strcmp(b, "Y") == 0 || strcmp(b, "y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			return ;
		}
		
	}
	//delete Co;
	//system("pause");
}


//�����Ʒ����Ϣ
void CommodityData::output(CommodityData *Co)
{
	//Co = new CommodityData;
	Co->ReadFile();
	//ReadFile();
	if (size != 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' 
			<< "����" << '\t' << "��������" << '\t' << "����" << '\t'
			<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' 
			<< "�������" << '\t' << "�����" << endl;
		cout << endl;
		for (int i = 0; i < size; i++)
		{		//setw()�����ַ�֮��Ŀ��
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout<< setw(3)<< data[i].commodityNumber << '\t'
				<< setw(3)<< data[i].commodityName << '\t'
				<< setw(3)<< data[i].commodityClass << '\t'
				<< setw(3)<< data[i].commodityPlaceOfOrigin<<'\t'
				<< setw(3)<< data[i].commodityManufacturer<<'\t' 
				<< setw(10)<< data[i].commodityPurchasePrice<<'\t'
				<< setw(3)<< data[i].commodityPrice<<'\t'
				<< setw(8)<< data[i].commodityPurchaseQuantity<<'\t'
				<< setw(8)<< data[i].commoditySoldQuantity<<'\t'
				<< setw(8)<< data[i].commodityInventoryQuantity<<'\t'
				<< setw(8)<< data[i].commodityInventoryAmount<<'\t'
				<< endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout << "�밴���������"  <<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		_getch();
	}
	//system("pause");	
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
	//delete Co;
	
}

//��Ʒɾ��ģ��
 void CommodityData::del(CommodityData *Co)
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
		cout << "�����������������:" ;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> a;
	} 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0 )//�����������
	{

		//CommodityData *Co;//����һ����Ʒ����
		Co->output(Co);//ָ���������

		char choose[10] = "0";//����һ��ѡ���ַ�
		cout << "************* ��ӭ����ɾ����Ʒ��Ϣģ�� ********\n"; 
	    cout << "*************   ��ѡ��ɾ����ʽ   *************\n";
	    cout << "*************  1  ����Ʒ���     *************\n";
	    cout << "*************  2  ����Ʒ����     *************\n";
	    cout << "************* ����������ѡ�� 1 or 2 ***********\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	    cin >> choose;
		while (strcmp(choose, "1") != 0 && strcmp(choose, "2") != 0)//����
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "�����������������:" ;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> choose;
		} 
		if (strcmp(choose, "1") == 0)
		{
			char CommodityNumber[8];//��Ҫɾ������Ʒ��� 
			int v = 0;//�����ж��Ƿ��ҵ�����Ʒ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	        cout << "����������Ҫɾ������Ʒ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	        cin >> CommodityNumber;//������Ҫɾ������Ʒ����
	        //search();
	        int num = 0;//Ѱ����Ʒ�����ͬʱ���±�
	        int i = 0;//����������Ʒ��ŵ��±�
         	for (i = 0; i < size; i++)
         	{
	        	if (strcmp(CommodityNumber, data[i].commodityNumber) == 0)//�ж��������Ʒ����Ƿ�Ϳ�����һ��
	         	{
		        	num = i;
		        	for (int j = num; j < size; j++)
					{
			        	data[j] = data[j + 1];//���������Ʒ������ǰ��
					}
					size = size - 1;
					v = v + 1;
					
		            break;
				}
				
			}
			
			if(v > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "*************       ɾ���ɹ���      *************" << endl;
				Co->SaveFile();
				cout << "***********   �Ƿ����ɾ����(G or I):  ***********" << endl;
				char exit1[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit1;
				while(strcmp(exit1, "G") != 0 && strcmp(exit1, "g") != 0 && strcmp(exit1, "I") != 0 && strcmp(exit1, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit1;
				}
				while(strcmp(exit1, "I") == 0 || strcmp(exit1, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return ;
				}
				while(strcmp(exit1, "G") == 0 || strcmp(exit1, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					del(Co);
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "************* �Բ���û���ҵ�����Ʒ *************" << endl;
				cout << "***********   �Ƿ����ɾ����(G or I):  ***********" << endl;
				char exit2[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit2;
				while(strcmp(exit2, "G") != 0 && strcmp(exit2, "g") != 0 && strcmp(exit2, "I") != 0 && strcmp(exit2, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit2;
				}
				while(strcmp(exit2, "I") == 0 || strcmp(exit2, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return ;
				}
				while(strcmp(exit2, "G") == 0 || strcmp(exit2, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					del(Co);
				}
			}
			
		}
		else if (strcmp(choose, "2") == 0)
		{
	    	char CommodityName[8];//��Ҫɾ������Ʒ���� 
			int v = 0;//�����ж��Ƿ��ҵ��˸���Ʒ
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "����������Ҫɾ������Ʒ������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
         	cin >> CommodityName;//������Ҫɾ������Ʒ����
         	//search();
        	int u = 0;//Ѱ����Ʒ������ͬʱ���±�
        	int t = 0;//����������Ʒ���Ƶ��±�
        	for (t = 0; t < size; t++)
        	{
	        	if (strcmp(CommodityName, data[t].commodityName) == 0)//�ж��������Ʒ�����Ƿ�Ϳ�����һ��
	        	{
		        	u = t;
					for (int s = u; s < size; s++)
					{
		    	    	data[s] = data[s + 1];//���������Ʒ������ǰ��
					}
	 		    	size = size - 1;//��Ʒ������1
					v = v + 1;
		        	//cout << "ɾ���ɹ���" << endl;
					break;
	        	}
			}
			if(v > 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "*************        ɾ���ɹ���     *************" << endl;
				Co->SaveFile();
				cout << "***********   �Ƿ����ɾ����(G or I):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit;
				while(strcmp(exit, "G") != 0 && strcmp(exit, "g") != 0 && strcmp(exit, "I") != 0 && strcmp(exit, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit;
				}
				while(strcmp(exit, "I") == 0 || strcmp(exit, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return ;
				}
				while(strcmp(exit, "G") == 0 || strcmp(exit, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					del(Co);
				}
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "************* �Բ���û���ҵ�����Ʒ *************" << endl;
				cout << "***********   �Ƿ����ɾ����(G or I):  ***********" << endl;
				char exit[10] = "1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
				cin >> exit;
				while(strcmp(exit, "G") != 0 && strcmp(exit, "g") != 0 && strcmp(exit, "I") != 0 && strcmp(exit, "i") != 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�����������������:" ;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
					cin >> exit;
				}
				while(strcmp(exit, "I") == 0 || strcmp(exit, "i") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					return ;
				}
				while(strcmp(exit, "G") == 0 || strcmp(exit, "g") == 0 )
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					del(Co);
				}
			}
    	}
	
		Co->SaveFile();
		//delete Co;
	}

	else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
	{
		return ;
	}
}


//�޸���Ʒ��Ϣ
void CommodityData::modify(CommodityData* Co)
{
	Co->ReadFile();
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
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if (strcmp(a, "N") == 0 || strcmp(a, "n") == 0)
	{
		int f1 = 0;
		int n = 0;
		int i = 0;
		cout << "���ҷ�ʽ ��1.��� 2.����" << endl;
		int m = 0;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> m;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		switch (m)
		{
		case 1:
			char Number[8];
			cout << "����������Ҫ�޸���Ʒ���" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> Number;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i++)//�����������Ʒ
			{

				if ((strcmp(Number, data[i].commodityNumber) == 0))
				{
					n = 1;
					cout << "�޸���ϢΪ:" << endl;

					cout << "��Ʒ���:" << data[i].commodityName << endl;

					cout << "��Ʒ���:" << data[i].commodityClass << endl;

					cout << "����:" << data[i].commodityPlaceOfOrigin << endl;

					cout << "��������:" << data[i].commodityManufacturer << endl;

					cout << "��Ʒ����:" << data[i].commodityPurchasePrice << endl;

					cout << "��Ʒ�ۼ�:" << data[i].commodityPrice << endl;

					cout << "��Ʒ��������:" << data[i].commodityPurchaseQuantity << endl;

					cout << "��Ʒ��������:" << data[i].commoditySoldQuantity << endl;

					cout << "��Ʒ�������:" << data[i].commodityInventoryQuantity << endl;

					cout << "��Ʒ�����:" << data[i].commodityInventoryAmount << endl;
					cout << "��ȷ���Ƿ��޸ĸ���Ʒ����Ϣ��Y or N����";
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
							cout << "�޸�ǰ��Ʒ��ţ�" << data[i].commodityNumber << endl;
							cout << "��������Ʒ���:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���ƣ�" << data[i].commodityName << endl;
							cout << "��������Ʒ����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���" << data[i].commodityClass << endl;
							cout << "��������Ʒ���:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityClass;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ���أ�" << data[i].commodityPlaceOfOrigin << endl;
							cout << "���������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPlaceOfOrigin;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ�������ң�" << data[i].commodityManufacturer << endl;
							cout << "��������������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityManufacturer;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���ۣ�" << data[i].commodityPurchasePrice << endl;
							cout << "��������Ʒ����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPurchasePrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ�ۼۣ�" << data[i].commodityPrice << endl;
							cout << "��������Ʒ�ۼ�:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ����������" << data[i].commodityPurchaseQuantity << endl;
							cout << "��������Ʒ��������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPurchaseQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ����������" << data[i].commoditySoldQuantity << endl;
							cout << "��������Ʒ��������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commoditySoldQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���������" << data[i].commodityInventoryQuantity << endl;
							cout << "��������Ʒ�������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityInventoryQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ����" << data[i].commodityInventoryAmount << endl;
							cout << "��������Ʒ�����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityInventoryAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> f1;
							if (f1)
							{
								modify(Co);
							}
						}
						else if (z == 2)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "������Ҫ�޸ĵı�ţ�" << endl;
							cout << "1.��Ʒ���" << endl << "2.��Ʒ����" << endl << "3.��Ʒ���" << endl << "4.����" << endl << "5.��������" << endl << "6.��Ʒ����" << endl << "7.��Ʒ�ۼ�" << endl << "8.��Ʒ��������" << endl << "9.��Ʒ��������" << endl << "10.��Ʒ�������" << endl << "11.��Ʒ�����" << endl;
							int k = 0;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							switch (k)
							{
							case 1:
								cout << "�޸�ǰ��Ʒ��ţ�" << data[i].commodityNumber << endl;
								cout << "��������Ʒ���:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 2:
								cout << "�޸�ǰ��Ʒ���ƣ�" << data[i].commodityName << endl;
								cout << "��������Ʒ����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 3:
								cout << "�޸�ǰ��Ʒ���" << data[i].commodityClass << endl;
								cout << "��������Ʒ���:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityClass;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 4:
								cout << "�޸�ǰ���أ�" << data[i].commodityPlaceOfOrigin << endl;
								cout << "���������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPlaceOfOrigin;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 5:
								cout << "�޸�ǰ�������ң�" << data[i].commodityManufacturer << endl;
								cout << "��������������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityManufacturer;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 6:
								cout << "�޸�ǰ��Ʒ���ۣ�" << data[i].commodityPurchasePrice << endl;
								cout << "��������Ʒ����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPurchasePrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 7:
								cout << "�޸�ǰ��Ʒ�ۼۣ�" << data[i].commodityPrice << endl;
								cout << "��������Ʒ�ۼ�:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 8:
								cout << "�޸�ǰ��Ʒ����������" << data[i].commodityPurchaseQuantity << endl;
								cout << "��������Ʒ��������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPurchaseQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 9:
								cout << "�޸�ǰ��Ʒ����������" << data[i].commoditySoldQuantity << endl;
								cout << "��������Ʒ��������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commoditySoldQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 10:
								cout << "�޸�ǰ��Ʒ���������" << data[i].commodityInventoryQuantity << endl;
								cout << "��������Ʒ�������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityInventoryQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 11:
								cout << "�޸�ǰ��Ʒ����" << data[i].commodityInventoryAmount << endl;
								cout << "��������Ʒ�����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityInventoryAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
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

				if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�Ҳ����޸ĵ�Ŀ��" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			Co->SaveFile();
			break;

		case 2:
			cout << "����������Ҫ�޸���Ʒ���֣�" << endl;
			char Name[20];
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> Name;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i++)//�����������Ʒ
			{

				if ((strcmp(Name, data[i].commodityName) == 0))
				{
					n = 1;
					cout << "�޸���ϢΪ:" << endl;

					cout << "��Ʒ���:" << data[i].commodityNumber << endl;

					cout << "��Ʒ����:" << data[i].commodityName << endl;

					cout << "��Ʒ���:" << data[i].commodityClass << endl;

					cout << "����:" << data[i].commodityPlaceOfOrigin << endl;

					cout << "��������:" << data[i].commodityManufacturer << endl;

					cout << "��Ʒ����:" << data[i].commodityPurchasePrice << endl;

					cout << "��Ʒ�ۼ�:" << data[i].commodityPrice << endl;

					cout << "��Ʒ��������:" << data[i].commodityPurchaseQuantity << endl;

					cout << "��Ʒ��������:" << data[i].commoditySoldQuantity << endl;

					cout << "��Ʒ�������:" << data[i].commodityInventoryQuantity << endl;

					cout << "��Ʒ�����:" << data[i].commodityInventoryAmount << endl;

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
						if (z == 1)
						{
							cout << "�޸�ǰ��Ʒ��ţ�" << data[i].commodityNumber << endl;
							cout << "��������Ʒ���:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityNumber;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���ƣ�" << data[i].commodityName << endl;
							cout << "��������Ʒ����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityName;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���" << data[i].commodityClass << endl;
							cout << "��������Ʒ���:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityClass;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ���أ�" << data[i].commodityPlaceOfOrigin << endl;
							cout << "���������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPlaceOfOrigin;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ�������ң�" << data[i].commodityManufacturer << endl;
							cout << "��������������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityManufacturer;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���ۣ�" << data[i].commodityPurchasePrice << endl;
							cout << "��������Ʒ����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPurchasePrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ�ۼۣ�" << data[i].commodityPrice << endl;
							cout << "��������Ʒ�ۼ�:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPrice;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ����������" << data[i].commodityPurchaseQuantity << endl;
							cout << "��������Ʒ��������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityPurchaseQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ����������" << data[i].commoditySoldQuantity << endl;
							cout << "��������Ʒ��������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commoditySoldQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ���������" << data[i].commodityInventoryQuantity << endl;
							cout << "��������Ʒ�������:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityInventoryQuantity;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "�޸�ǰ��Ʒ����" << data[i].commodityInventoryAmount << endl;
							cout << "��������Ʒ�����:";
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> data[i].commodityInventoryAmount;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> f1;
							if (f1)
							{
								modify(Co);
							}
						}
						else if (z == 2)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							cout << "������Ҫ�޸ĵı�ţ�" << endl;
							cout << "1.��Ʒ���" << endl << "2.��Ʒ����" << endl << "3.��Ʒ���" << endl << "4.����" << endl << "5.��������" << endl << "6.��Ʒ����" << endl << "7.��Ʒ�ۼ�" << endl << "8.��Ʒ��������" << endl << "9.��Ʒ��������" << endl << "10.��Ʒ�������" << endl << "11.��Ʒ�����" << endl;
							int k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
							cin >> k;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
							switch (k)
							{
							case 1:
								cout << "�޸�ǰ��Ʒ��ţ�" << data[i].commodityNumber << endl;
								cout << "��������Ʒ���:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityNumber;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 2:
								cout << "�޸�ǰ��Ʒ���ƣ�" << data[i].commodityName << endl;
								cout << "��������Ʒ����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityName;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 3:
								cout << "�޸�ǰ��Ʒ���" << data[i].commodityClass << endl;
								cout << "��������Ʒ���:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityClass;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 4:
								cout << "�޸�ǰ���أ�" << data[i].commodityPlaceOfOrigin << endl;
								cout << "���������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPlaceOfOrigin;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 5:
								cout << "�޸�ǰ�������ң�" << data[i].commodityManufacturer << endl;
								cout << "��������������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityManufacturer;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 6:
								cout << "�޸�ǰ��Ʒ���ۣ�" << data[i].commodityPurchasePrice << endl;
								cout << "��������Ʒ����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPurchasePrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 7:
								cout << "�޸�ǰ��Ʒ�ۼۣ�" << data[i].commodityPrice << endl;
								cout << "��������Ʒ�ۼ�:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPrice;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;

							case 8:
								cout << "�޸�ǰ��Ʒ����������" << data[i].commodityPurchaseQuantity << endl;
								cout << "��������Ʒ��������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityPurchaseQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 9:
								cout << "�޸�ǰ��Ʒ����������" << data[i].commoditySoldQuantity << endl;
								cout << "��������Ʒ��������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commoditySoldQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 10:
								cout << "�޸�ǰ��Ʒ���������" << data[i].commodityInventoryQuantity << endl;
								cout << "��������Ʒ�������:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityInventoryQuantity;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
								}
								break;
							case 11:
								cout << "�޸�ǰ��Ʒ����" << data[i].commodityInventoryAmount << endl;
								cout << "��������Ʒ�����:";
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> data[i].commodityInventoryAmount;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
								cout << "!!!!!!!!!!!!�Ƿ�����޸ģ����������1����������0:" << endl;
								SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
								cin >> f1;
								if (f1)
								{
									modify(Co);
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

				if (n == 0)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout << "�Ҳ����޸ĵ�Ŀ��" << endl;
					break;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			Co->SaveFile();
			break;
		}

	}
	else if (strcmp(a, "Y") == 0 || strcmp(a, "y") == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		return;
	}

}


//��Ʒ���Һ�����ʵ��
CommodityData  CommodityData::search(CommodityData *Co)
{
	char choice[10] = "0";
	char choi[10] = "0";//�����ж��Ƿ��������
	char cnum[8] = "0";//Ҫ���ҵ���Ϣ���
	char cnam[20] = "0";//Ҫ���ҵ�����
	char ccla[10] = "0";//Ҫ���ҵ����
	char cpoo[10] = "0";//Ҫ���ҵĲ���
	char cmft[20] = "0";//Ҫ���ҵĳ���
	char cho[10] = "0";//��ѯ��ѡ��
	int n = 0;//�ж���Ʒ�Ƿ����
	int m = 0;//��Ʒ����ʱ���һ������
	int i = 0;//forѭ����ʹ��
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                        *******��ѡ����Ҫ��ѯ�ķ�ʽ��*******"<<endl;
	cout<<"\t\t                       *******      1-->��ȷ����      *******"<<endl;
	cout<<"\t\t                      *******       2-->ģ������       *******"<<endl;
	cout<<"\t\t                        *******     3-->�������˵�   *******"<<endl;
	cout<<"\t\t                           ******************************" << endl;
	cout<<"\t\t                      ����������ѡ��(1-3):"; 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin>>choice;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	system("cls");
	if (strcmp(choice, "1") == 0)
	{
		Co->ReadFile();                //��ȡ�ļ��е����ݵ��ڴ���
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                          *******  ��ѡ���ѯ����:  *******"<<endl;
		cout<<"\t\t                        *******     1-->����Ʒ���    *******"<<endl;
		cout<<"\t\t                       *******      2-->����Ʒ����     *******"<<endl;
		cout<<"\t\t                      *******       3-->����Ʒ���      *******"<<endl;
		cout<<"\t\t                       *******      4-->������         *******"<<endl;
		cout<<"\t\t                        *******     5-->����������    *******"<<endl;
		cout<<"\t\t                         *******    6-->�������˵�   *******"<<endl;
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                      ����������ѡ��1-6��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		if (strcmp(cho, "1") == 0)
		{

			cout << "\t\t          ��������Ʒ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cnum;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)//�����ļ�������
			{
				if (strcmp(cnum, data[i].commodityNumber) == 0)//�ж��Ƿ������ѯ���һ�µ���Ϣ
				{
					if(m == 0)//��Ʒ���ڵ�����£����һ������
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++; //�ı�mֵ��֮��Ͳ��������
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
					n = 1;  //���д˲�������Ʒ����
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ����Ʒ������" << endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          ��������Ʒ����:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cnam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strcmp(cnam, data[i].commodityName) == 0)//�ж��Ƿ������ѯ����һ�µ���Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
							<<data[i].commodityName << '\t'
							<<data[i].commodityClass << '\t'
							<<data[i].commodityPlaceOfOrigin<<'\t'
							<<data[i].commodityManufacturer<<'\t'
							<<data[i].commodityPurchasePrice<<'\t'
							<<data[i].commodityPrice<<'\t'
							<<data[i].commodityPurchaseQuantity<<'\t'
							<<data[i].commoditySoldQuantity<<'\t'
							<<data[i].commodityInventoryQuantity<<'\t'
							<<data[i].commodityInventoryAmount
							<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ����Ʒ������" << endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          ��������Ʒ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> ccla;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strcmp(ccla, data[i].commodityClass) == 0)//�ж��Ƿ������ѯ���һ�µ���Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
							<<data[i].commodityName << '\t'
							<<data[i].commodityClass << '\t'
							<<data[i].commodityPlaceOfOrigin<<'\t'
							<<data[i].commodityManufacturer<<'\t'
							<<data[i].commodityPurchasePrice<<'\t'
							<<data[i].commodityPrice<<'\t'
							<<data[i].commodityPurchaseQuantity<<'\t'
							<<data[i].commoditySoldQuantity<<'\t'
							<<data[i].commodityInventoryQuantity<<'\t'
							<<data[i].commodityInventoryAmount
							<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ����Ʒ������" << endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          ���������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cpoo;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strcmp(cpoo, data[i].commodityPlaceOfOrigin) == 0)//�ж��Ƿ������ѯ����һ�µ���Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
							<<data[i].commodityName << '\t'
							<<data[i].commodityClass << '\t'
							<<data[i].commodityPlaceOfOrigin<<'\t'
							<<data[i].commodityManufacturer<<'\t'
							<<data[i].commodityPurchasePrice<<'\t'
							<<data[i].commodityPrice<<'\t'
							<<data[i].commodityPurchaseQuantity<<'\t'
							<<data[i].commoditySoldQuantity<<'\t'
							<<data[i].commodityInventoryQuantity<<'\t'
							<<data[i].commodityInventoryAmount
							<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ����Ʒ������" << endl;
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "          ��������������:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cmft;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strcmp(cmft, data[i].commodityManufacturer) == 0)//�ж��Ƿ������ѯ����һ�µ���Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
							<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        ����Ʒ������" << endl;
			}
		}
		else if (strcmp(cho, "6") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			return *Co;
		}
		else
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			cout << "\t\t                            ѡ�����\n" << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		}
	}
	else if (strcmp(choice, "2") == 0)
	{
		Co->ReadFile();
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                          *******  ��ѡ���ѯ����:  *******"<<endl;
		cout<<"\t\t                        *******     1-->����Ʒ���    *******"<<endl;
		cout<<"\t\t                       *******      2-->����Ʒ����     *******"<<endl;
		cout<<"\t\t                      *******       3-->����Ʒ���      *******"<<endl;
		cout<<"\t\t                       *******      4-->������         *******"<<endl;
		cout<<"\t\t                        *******     5-->����������    *******"<<endl;
		cout<<"\t\t                         *******    6-->�������˵�   *******"<<endl;
		cout<<"\t\t                           *****************************" << endl;
		cout<<"\t\t                      ����������ѡ��1-6��:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin >> cho;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		system("cls");
		if (strcmp(cho, "1") == 0)
		{
			cout << "          ��������Ʒ��Źؼ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cnum;
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityNumber, cnum) != NULL)//�ж�������Ʒ������Ƿ��в�ѯ��Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
							n = 1;
					}
				}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        �ؼ��ʲ����ڣ�" << endl;
			}
		}
		else if (strcmp(cho, "2") == 0)
		{
			cout << "          ��������Ʒ���ƹؼ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cnam;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityName, cnam) != NULL)//�ж�������Ʒ�������Ƿ��в�ѯ��Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
						n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        �ؼ��ʲ����ڣ�" << endl;
			}
		}
		else if (strcmp(cho, "3") == 0)
		{
			cout << "          ��������Ʒ���ؼ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> ccla;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityClass, ccla) != NULL)//�ж�������Ʒ������Ƿ��в�ѯ��Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
							<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        �ؼ��ʲ����ڣ�" << endl;
			}
		}
		else if (strcmp(cho, "4") == 0)
		{
			cout << "          ��������عؼ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cpoo;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityPlaceOfOrigin, cpoo) != NULL)//�ж�������Ʒ�������Ƿ��в�ѯ��Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        �ؼ��ʲ����ڣ�" << endl;
			}
		}
		else if (strcmp(cho, "5") == 0)
		{
			cout << "          �������������ҹؼ���:";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
			cin >> cmft;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			for (i = 0; i < size; i ++)
			{
				if (strstr(data[i].commodityManufacturer, cmft) != NULL)//�ж�������Ʒ�����������Ƿ��в�ѯ��Ϣ
				{
					if(m == 0)
					{
						cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t' << "��������" << '\t' << "����" << '\t'
							<< "�ۼ�" << '\t' << "��������" << '\t' << "��������" << '\t' << "�������" << '\t' << "�����" << endl;
						cout << endl;
						m++;
					}
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
					cout<< data[i].commodityNumber << '\t'
						<< data[i].commodityName << '\t'
						<< data[i].commodityClass << '\t'
						<< data[i].commodityPlaceOfOrigin<<'\t'
						<< data[i].commodityManufacturer<<'\t'
						<< data[i].commodityPurchasePrice<<'\t'
						<< data[i].commodityPrice<<'\t'
						<< data[i].commodityPurchaseQuantity<<'\t'
						<< data[i].commoditySoldQuantity<<'\t'
						<< data[i].commodityInventoryQuantity<<'\t'
						<< data[i].commodityInventoryAmount
						<< endl;
					n = 1;
				}
			}
			if (n == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
				cout << "\t\t        �ؼ��ʲ����ڣ�" << endl;
			}
		}
		else if (strcmp(cho, "6") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
			return *Co;
		}
		else
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
		return *Co;
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
		cout<<"\t\t                             ѡ�����!\n"<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	}
	i = 0; //�����ж���ѡ���Ƿ��������ʱ��ѡ���Ƿ����
	while(strcmp(choi, "Y") != 0 && strcmp(choi, "y") != 0 && strcmp(choi, "N") != 0 && strcmp(choi, "n") != 0)
	{
		if(i > 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN);
			cout<<"\t\t                                     �Ƿ����룡���������룡"<<endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout<<"\t\t                              ********************************" << endl;
		cout<<"\t\t                           *******    �Ƿ����������Ʒ��  *******"<<endl;
		cout<<"\t\t                          *******       Y-->��������       *******"<<endl;
		cout<<"\t\t                           *******      N-->�������˵�    *******"<<endl;
		cout<<"\t\t                              ********************************" << endl;
		cout<<"\t\t                          ����������ѡ��(Y or N):"; 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
		cin>>choi;
		system("cls");
		if(strcmp(choi, "N") == 0||strcmp(choi, "n") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			return *Co;
		}
		else if(strcmp(choi, "y") == 0||strcmp(choi, "Y") == 0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
			search(Co);
		}
		i++;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	cout << "�밴���������"  <<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	_getch();
	//system("pause");
	return *Co;
}



//������Ʒ���/����Ʒ�ۼ�/��Ʒ�������/��Ʒ�������� 
void CommodityData::selectionSort(CommodityData* Co, Commodity* t)
{
	system("cls");//����
	Co->ReadFile();
	t = new Commodity;
	char cho[10] = "0";//��������ѡ��
	char choi[10] = "0";//�ж��Ƿ�����鿴��Ʒ����
	cout << "\t\t            ************************************************************************" << endl;
	cout << "\t\t           ********************          ��ѡ����������:         ********************" << endl;
	cout << "\t\t          ********************         1-->����Ʒ���             ********************" << endl;
	cout << "\t\t         ********************          2-->����Ʒ�ۼ�              ********************" << endl;
	cout << "\t\t         ********************          3-->����Ʒ�������          ********************" << endl;
	cout << "\t\t          ********************         4-->����Ʒ��������         ********************" << endl;
	cout << "\t\t           ********************        5-->�������˵�            ********************" << endl;
	cout << "\t\t            ***********************************************************************" << endl;
	cout << "\t\t         ����������ѡ��1-5��:";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> cho;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ

	if (strcmp(cho, "1") == 0)
	{
		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
			<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
			<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 1; i < size; i++)    //����Ʒ������򣬲���ֱ�Ӳ�������
		{
			*t = data[i];
			int j = i - 1;
			while (j >= 0 && t->commodityNumber > data[j].commodityNumber)
			{
				data[j + 1] = data[j];
				j--;
			}
			j++;
			data[j] = *t;
		}

		for (int i = 0; i < size; i++)
		{
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
				<< endl;
		}

	}

	else if (strcmp(cho, "2") == 0)
	{

		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
			<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
			<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);

		for (int i = 0; i < size; i++)   //����Ʒ�ۼ����򣬲���ð�������³����� 
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (data[j + 1].commodityPrice > data[j].commodityPrice)
				{
					*t = data[j + 1];
					data[j + 1] = data[j];
					data[j] = *t;
				}
			}
		}

		for (int i = 0; i < size; i++)
		{
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
				<< endl;
		}
	}

	else if (strcmp(cho, "3") == 0)
	{

		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
			<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
			<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);

		for (int i = 0; i < size; i++)    //����Ʒ����������򣬲���ֱ��ѡ������
		{
			int k = i;
			*t = data[i];
			for (int j = i + 1; j < size; j++)
			{
				if (data[j].commodityInventoryQuantity > t->commodityInventoryQuantity)
				{
					*t = data[j];
					k = j;
				}
			}
			data[k] = data[i];
			data[i] = *t;
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
				<< endl;
		}

	}

	else if (strcmp(cho, "4") == 0)
	{
		cout << "���" << '\t' << "����" << '\t' << "���" << '\t' << "����" << '\t'
			<< "��������" << '\t' << "����" << '\t' << "�ۼ�" << '\t' << "��������" << '\t'
			<< "��������" << '\t' << "�������" << '\t' << "�����" << '\t' << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		for (int i = 0; i < size; i++)    //����Ʒ�����������򣬲���ֱ��ѡ������
		{
			int k = i;
			*t = data[i];
			for (int j = i + 1; j < size; j++)
			{
				if (data[j].commoditySoldQuantity > t->commoditySoldQuantity)
				{
					*t = data[j];
					k = j;
				}
			}
			data[k] = data[i];
			data[i] = *t;
			cout << setw(3) << data[i].commodityNumber << '\t'
				<< setw(3) << data[i].commodityName << '\t'
				<< setw(3) << data[i].commodityClass << '\t'
				<< setw(8) << data[i].commodityPlaceOfOrigin << '\t'
				<< setw(8) << data[i].commodityManufacturer << '\t'
				<< setw(8) << data[i].commodityPurchasePrice << '\t'
				<< setw(8) << data[i].commodityPrice << '\t'
				<< setw(8) << data[i].commodityPurchaseQuantity << '\t'
				<< setw(8) << data[i].commoditySoldQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryQuantity << '\t'
				<< setw(8) << data[i].commodityInventoryAmount << '\t'
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
			cout << "\t\t                                     ����������������룡" << endl;
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
			selectionSort(Co, t);
		}
		i++;
	}

	delete t;
	cout << "�밴���������" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);
	_getch();
	//system("pause");
}
