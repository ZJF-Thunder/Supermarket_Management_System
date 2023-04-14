#pragma once
#ifndef _STAFF_H//����ͷ�ļ����ظ�����
#define _STAFF_H
//Ա����Ϣ�Ľṹ�����Ͷ���
struct Staff
{
	char staffNumber[8];//Ա����� 
	char staffName[20];//Ա������ 
	char staffgender[5];//Ա���Ա� 
	int staffMonthSaleQuantity;//Ա�������������� 
	float staffMonthSaleAmount;//Ա���������۽�� 
	int staffTotalSaleQuantity;//Ա���ۼ��������� 
	float staffTotalSaleAmount;//Ա���ۼ����۽�� 	
	Staff* next;
};

//Ա���ڵ�ṹ������
struct StaffNode
{
	Staff data;
	StaffNode* next;
};

StaffNode* StaffInit(StaffNode* head);//���ݳ�ʼ��

StaffNode* StaffCreate(StaffNode* head);//������Ʒ��Ϣ
StaffNode* StaffAdd(StaffNode* head);//��������

void StaffOutput(StaffNode* head);//������� 

StaffNode* StaffDel(StaffNode* head);//ɾ�� 

StaffNode* StaffModify(StaffNode* head);//�޸� 
void StaffSelectionSort(StaffNode* head);//Ա��ҵ���������� 

int Staffearch(StaffNode* head);//��ѯ

bool StaffSave(StaffNode* head);//�������ݺ���
StaffNode* StaffRead(StaffNode* head);//��ȡ���ݺ���

#endif