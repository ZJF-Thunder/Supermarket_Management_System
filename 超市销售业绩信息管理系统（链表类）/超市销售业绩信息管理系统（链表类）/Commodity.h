#ifndef _COMMODITY_H//避免头文件被重复包含
#define _COMMODITY_H

//因为是类，所以不能直接访问类中的私有数据，所以只能定义一个类的对象间接访问类中的私有数据；
//结构体没有私有数据，所以不需要额外定义一个变量间接访问其中的数据

//商品信息的结构体类型声明
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

//商品节点结构体声明
struct CommodityNode
{
	Commodity data;
	CommodityNode* next;
};

CommodityNode* CommodityInit(struct CommodityNode *head);//数据初始化
CommodityNode* CommodityCreate(CommodityNode* head);//创建商品信息
CommodityNode* CommodityAdd(CommodityNode* head);//增加数据
void CommodityOutput(CommodityNode* head);//输出数据 

CommodityNode* CommodityDel(CommodityNode* head);//删除 

/*void allmodify(CommodityNode* head);*/

CommodityNode* CommodityModify(CommodityNode* head);//修改 

void CommoditySelectionSort(CommodityNode* head);//商品排序
int CommoditySearch(CommodityNode* head);//查询

bool CommoditySave(CommodityNode* head);//保存数据函数
CommodityNode* CommodityRead();//读取数据函数

#endif;
