class Password
{
public:
	//构造函数
	Password();
	//析构函数
	~Password();
	void input_code();
private:
	int j;//输入密码时的长度
	int i;//密码总长度
	char password[20];//密码数组
	char user[20];//用户名数组
};
