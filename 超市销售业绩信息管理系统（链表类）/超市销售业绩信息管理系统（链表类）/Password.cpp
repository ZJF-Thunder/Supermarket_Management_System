#include "PassWord.h"
#include<iostream>
#include<conio.h>//����_getch()����
#include<windows.h>
using namespace std;

//���캯����ʵ�� 
Password::Password()
{
	i = 0;
	j = 0;
	char password[20] = "000000";//�������� 
	char user[20] = "000000";//�û������� 
}

//��������
Password::~Password()
{
}

//����������û���������ʵ�� 
void Password::input_code()
{
	char code[20] = "123456";//ָ�������� 
	char users[20] = "user";//Ĭ��ָ���û��� 
	while (i < 5)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//��ɫ��ɫ��ɫ���
		cout << "                            ����������û���:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN);
		fgets(user, 20, stdin);//�����û��� 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "                            �������������:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN);
		while ((password[j] = _getch()) != 13)//��������ַ���Ϊ�س�ʱ����* ��ʽ��ʾ 
		{
			putchar('*');    //������*��ʽ��ʾ 
			j++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);

		user[j] = '\0';
		password[j] = '\0';

		cout << endl;
		j = 0;
		if (strcmp(password, code) == 0 && strcmp(user, users) == 0)//�����������û�����ָ����������û�����Ƚ� 
		{
			cout << "                                ��½�ɹ���" << endl;
			break;
		}
		else
		{
			i++;
			cout << "                      ��������û�������������" << 5 - i << "�λ���,����������!\n";
		}
	}
	if (i == 5)
	{
		printf("                              ���������Σ��˳�ϵͳ\n");
		exit(0);

		system("pause");
	}
	system("cls");//���� 
}
