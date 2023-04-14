#pragma once
#ifndef _STAFF_H//避免头文件被重复包含
#define _STAFF_H
//员工信息的结构体类型定义
struct Staff
{
	char staffNumber[8];//员工编号 
	char staffName[20];//员工名称 
	char staffgender[5];//员工性别 
	int staffMonthSaleQuantity;//员工当月销售数量 
	float staffMonthSaleAmount;//员工当月销售金额 
	int staffTotalSaleQuantity;//员工累计销售数量 
	float staffTotalSaleAmount;//员工累计销售金额 	
	Staff* next;
};

//员工节点结构体声明
struct StaffNode
{
	Staff data;
	StaffNode* next;
};

StaffNode* StaffInit(StaffNode* head);//数据初始化

StaffNode* StaffCreate(StaffNode* head);//创建商品信息
StaffNode* StaffAdd(StaffNode* head);//增加数据

void StaffOutput(StaffNode* head);//输出数据 

StaffNode* StaffDel(StaffNode* head);//删除 

StaffNode* StaffModify(StaffNode* head);//修改 
void StaffSelectionSort(StaffNode* head);//员工业绩降序排序 

int Staffearch(StaffNode* head);//查询

bool StaffSave(StaffNode* head);//保存数据函数
StaffNode* StaffRead(StaffNode* head);//读取数据函数

#endif