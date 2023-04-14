#include "PassWord.h"
#include<iostream>
#include<conio.h>//调用_getch()函数
#include<windows.h>
using namespace std;

//构造函数的实现 
Password::Password()
{
	i = 0;
	j = 0;
	char password[20] = "000000";//密码数组 
	char user[20] = "000000";//用户名数组 
}

//析构函数
Password::~Password()
{
}

//输入密码和用户名函数的实现 
void Password::input_code()
{
	char code[20] = "123456";//指定的密码 
	char users[20] = "user";//默认指定用户名 
	while (i < 5)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);//红色蓝色绿色混合
		cout << "                            请输入你的用户名:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN);
		fgets(user, 20, stdin);//输入用户名 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);
		cout << "                            请输入你的密码:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN);
		while ((password[j] = _getch()) != 13)//当输入的字符不为回车时即以* 形式显示 
		{
			putchar('*');    //密码以*形式显示 
			j++;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN);

		user[j] = '\0';
		password[j] = '\0';

		cout << endl;
		j = 0;
		if (strcmp(password, code) == 0 && strcmp(user, users) == 0)//输入的密码和用户名与指定的密码和用户名相比较 
		{
			cout << "                                登陆成功！" << endl;
			break;
		}
		else
		{
			i++;
			cout << "                      密码或者用户名错误，您还有" << 5 - i << "次机会,请重新输入!\n";
		}
	}
	if (i == 5)
	{
		printf("                              密码错误五次，退出系统\n");
		exit(0);

		system("pause");
	}
	system("cls");//清屏 
}
