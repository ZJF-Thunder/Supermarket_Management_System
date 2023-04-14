#ifndef _COMMODITY_H//����ͷ�ļ����ظ�����
#define _COMMODITY_H

//��Ϊ���࣬���Բ���ֱ�ӷ������е�˽�����ݣ�����ֻ�ܶ���һ����Ķ����ӷ������е�˽�����ݣ�
//�ṹ��û��˽�����ݣ����Բ���Ҫ���ⶨ��һ��������ӷ������е�����

//��Ʒ��Ϣ�Ľṹ����������
struct Commodity
{
	char commodityNumber[8];//��Ʒ��� 
	char commodityName[20];//��Ʒ���� 
	char commodityClass[20];//��Ʒ���  
	char commodityPlaceOfOrigin[10];//���� 
	char commodityManufacturer[20];//��������
	float commodityPurchasePrice;//��Ʒ����
	float commodityPrice;//��Ʒ�ۼ�
	int commodityPurchaseQuantity;//��Ʒ��������
	int commoditySoldQuantity;//��Ʒ��������
	int commodityInventoryQuantity;//��Ʒ�������
	int commodityInventoryAmount;//��Ʒ����� 
};

//��Ʒ�ڵ�ṹ������
struct CommodityNode
{
	Commodity data;
	CommodityNode* next;
};

CommodityNode* CommodityInit(struct CommodityNode *head);//���ݳ�ʼ��
CommodityNode* CommodityCreate(CommodityNode* head);//������Ʒ��Ϣ
CommodityNode* CommodityAdd(CommodityNode* head);//��������
void CommodityOutput(CommodityNode* head);//������� 

CommodityNode* CommodityDel(CommodityNode* head);//ɾ�� 

/*void allmodify(CommodityNode* head);*/

CommodityNode* CommodityModify(CommodityNode* head);//�޸� 

void CommoditySelectionSort(CommodityNode* head);//��Ʒ����
int CommoditySearch(CommodityNode* head);//��ѯ

bool CommoditySave(CommodityNode* head);//�������ݺ���
CommodityNode* CommodityRead();//��ȡ���ݺ���

#endif;
