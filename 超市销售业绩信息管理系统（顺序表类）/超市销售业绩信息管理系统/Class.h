#ifndef _CLASS_H//避免头文件被重复包含
#define _CLASS_H
#define MAX 200
//商品信息的结构体类型定义
struct Commodity
{
	char commodityNumber[8];//商品编号 
	char commodityName[20];//商品名称 
	char commodityClass[20];//商品类别  
	char commodityPlaceOfOrigin[10];//产地 
	char commodityManufacturer[20];//生产厂家
	float commodityPurchasePrice;//商品进价
	float commodityPrice;//商品售价
	int commodityPurchaseQuantity;//商品进货数量
	int commoditySoldQuantity;//商品销售数量
	int commodityInventoryQuantity;//商品库存数量
	int commodityInventoryAmount;//商品库存金额 
};

//员工信息的结构体类型定义
struct Staff
{
	char staffNumber[4];//员工编号 
	char staffName[20];//员工名称 
	char staffgender[5];//员工性别 
	int staffMonthSaleQuantity;//员工当月销售数量 
	float staffMonthSaleAmount;//员工当月销售金额 
	int staffTotalSaleQuantity;//员工累计销售数量 
	float staffTotalSaleAmount;//员工累计销售金额 	
};

class CommodityData//商品数据类 
{
public:
	//默认构造函数 
	CommodityData();
	//一般构造函数 
	CommodityData(Commodity* Cd, int m);
	//析构函数 
	~CommodityData();

	void input(CommodityData* Co, Commodity* Cd, int m);//输入数据
	void output(CommodityData* Co);//输出数据 
	void del(CommodityData* Co);//删除 
	void modify(CommodityData* Co);//修改 
	void selectionSort(CommodityData* Co, Commodity* t);//商品排序
	CommodityData search(CommodityData* Co);//查询
	bool SaveFile();//保存数据函数
	bool ReadFile();//读取数据函数
private:
	Commodity data[MAX];//数据
	//Commodity *data;//数据
	int size;//长度 

	//CommodityData *Co;//商品类指针 

};


class StaffData :public CommodityData//员工数据类 
{
public:
	//默认构造函数 
	StaffData();
	//一般构造函数
	StaffData(Staff* Sf, int m);
	//一般构造函数 
	~StaffData();

	void input(StaffData* St, Staff* Sf, int m);//输入数据
	void output(StaffData* St);//输出数据 
	void del(StaffData* St);//删除 
	void modify(StaffData* St);//修改 
	void selectionSort(StaffData* St, Staff* temp);//员工业绩降序排序 
	StaffData search(StaffData* St);//查询
	bool SaveFile();//保存数据函数
	bool ReadFile();//读取数据函数

private:
	int size;
	//StaffData *St;//员工类指针
	Staff data[MAX];//数据
	//Commodity *data;//数据
};
#endif;
