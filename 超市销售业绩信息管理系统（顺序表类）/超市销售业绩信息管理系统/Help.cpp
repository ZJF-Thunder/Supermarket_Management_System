#ifndef _HELP_//����ͷ�ļ����ظ�����
#define _HELP_
#include"Help.h"
#include<conio.h>
#include<iostream>
#include<windows.h>
#endif
using namespace std;

void help()
{
	cout << "************* �Ƿ�ȷ�Ͻ������ģ�飿  *************\n";
	cout << "1 ȷ�Ͻ���\n2 ȡ������\n";
	int s = 0;//����һ��ѡ��ı���
	cout << "��������ѡ��:\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	cin >> s;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	if(s == 1)
	{
		cout <<"************* ��ӭ�������ģ�� ********\n"; 
	    int choose;//����һ��ѡ�����
	    cout<<"*************   �밴������ѡ��ѡ��   *************"<<endl;
		cout<<"*************     1  ϵͳ���     *************"<<endl;
	    //cout<<"*2  �����ʾ��ʾ����Y����ȴ������y������ô�죿*****"<<endl;
	    //cout<<"*********     3  ʹ�ñ�ϵͳ��ע������   *********"<<endl;
	    //cout<<"************* ����������ѡ�� 1 or 2***********\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY |FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//ǳ��ɫ
	    cin>>choose;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | 0 | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ
	    switch(choose)
		{
		case 1:
			{
				cout << "�װ����û������ã���ϵͳ������Ϊ����������ҵ����Ϣ����ϵͳ\n";
				cout << "��ϵͳ�������ԱΪ�������塢����ӱ������Ө������\n";
				cout << "��ϵͳ��ʵ�ֵĹ���Ϊ���£�\n";
				cout << "������Ʒ��Ϣģ�飺ʹ���������Ϣ��ʽ����ʹ��Ϣ����ȥһĿ��Ȼ\n";
				cout << "����Ա����Ϣģ�飺����Ҫ��������Ӧ��Ա����Ϣ��ʹ�ù�����Ա���ӱ��\n";
				cout << "ɾ����Ʒ��Ϣģ�飺�ڴ�ģ�飬�����ɾ������ɾ������Ʒ��Ϣ����ʱ����ϵͳ��Ϣ\n";
				cout << "ɾ��Ա����Ϣģ�飺�ڴ�ģ�飬�����ɾ����ְԱ������Ϣ����ʱ����ϵͳ��Ϣ\n";
				cout << "�޸���Ʒ��Ϣģ�飺�ڴ�ģ�飬����Ը����г��Ĳ�ͬ����ʱ������Ʒ�ĸ�����Ϣ��������Ʒ�Ľ��ۡ��ۼ۵�\n";
				cout << "�޸�Ա����Ϣģ�飺�ڴ�ģ�飬����Լ�ʱ����Ա���ĸ�����Ϣ������ÿ�����۵�������ۼ����������\n";
				cout << "��ѯ��Ʒ��Ϣģ�飺�ڴ�ģ�飬����Ը�����Ʒ�ı�Ż������ƵȽ��о�׼��ѯ���߸��ݲ��ء����ҵȽ���ģ����ѯ\n";
				cout << "��ѯԱ����Ϣģ�飺�ڴ�ģ�飬����Ը���Ա�����������߱�ŵȽ��о�׼��ѯ���߸����Ա�Ƚ���ģ����ѯ\n";
				cout << "�����Ʒ��Ϣģ�飺�ڴ�ģ�飬��������������Ʒ��ȫ����Ϣ\n";
				cout << "���Ա����Ϣģ�飺�ڴ�ģ�飬������������Ա����ȫ����Ϣ\n";
				cout << "ͳ�Ʋ���ʾ��Ա����������ģ�飺�ڴ�ģ�飬����Կ���ÿ��Ա���Ӹߵ��͵�������\n";
				cout << "------------------------------------------------------------------------------------------------------------------\n";
				cout << "------------------------------------------------------------------------------------------------------------------\n";
				cout << "��ϵͳּ�ڰ��������õĹ����У���Լ����ɱ���ʵ�ֹ���ĸ�Ч�Ժ�׼ȷ��\n";		
				cout << "��л����ʹ�ã�ϣ��������һ���õ����飡\n";
				break;
			}
		default:cout<<"************* ѡ�����������ѡ��*************\n"<<endl;
		}
	}
	else
	{
		cout<<"************* ѡ�����������ѡ��*************\n"<<endl;
	}
	cout << "�밴�����������" << endl;
	_getch();
}