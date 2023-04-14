#ifndef _CLASS_H//����ͷ�ļ����ظ�����
#define _CLASS_H
#define MAX 200
//��Ʒ��Ϣ�Ľṹ�����Ͷ���
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

//Ա����Ϣ�Ľṹ�����Ͷ���
struct Staff
{
	char staffNumber[4];//Ա����� 
	char staffName[20];//Ա������ 
	char staffgender[5];//Ա���Ա� 
	int staffMonthSaleQuantity;//Ա�������������� 
	float staffMonthSaleAmount;//Ա���������۽�� 
	int staffTotalSaleQuantity;//Ա���ۼ��������� 
	float staffTotalSaleAmount;//Ա���ۼ����۽�� 	
};

class CommodityData//��Ʒ������ 
{
public:
	//Ĭ�Ϲ��캯�� 
	CommodityData();
	//һ�㹹�캯�� 
	CommodityData(Commodity* Cd, int m);
	//�������� 
	~CommodityData();

	void input(CommodityData* Co, Commodity* Cd, int m);//��������
	void output(CommodityData* Co);//������� 
	void del(CommodityData* Co);//ɾ�� 
	void modify(CommodityData* Co);//�޸� 
	void selectionSort(CommodityData* Co, Commodity* t);//��Ʒ����
	CommodityData search(CommodityData* Co);//��ѯ
	bool SaveFile();//�������ݺ���
	bool ReadFile();//��ȡ���ݺ���
private:
	Commodity data[MAX];//����
	//Commodity *data;//����
	int size;//���� 

	//CommodityData *Co;//��Ʒ��ָ�� 

};


class StaffData :public CommodityData//Ա�������� 
{
public:
	//Ĭ�Ϲ��캯�� 
	StaffData();
	//һ�㹹�캯��
	StaffData(Staff* Sf, int m);
	//һ�㹹�캯�� 
	~StaffData();

	void input(StaffData* St, Staff* Sf, int m);//��������
	void output(StaffData* St);//������� 
	void del(StaffData* St);//ɾ�� 
	void modify(StaffData* St);//�޸� 
	void selectionSort(StaffData* St, Staff* temp);//Ա��ҵ���������� 
	StaffData search(StaffData* St);//��ѯ
	bool SaveFile();//�������ݺ���
	bool ReadFile();//��ȡ���ݺ���

private:
	int size;
	//StaffData *St;//Ա����ָ��
	Staff data[MAX];//����
	//Commodity *data;//����
};
#endif;
