#pragma  once
#include "pThread.h"

class pTicket:public threadInterface{
	int iSellerNum;								//�ܵ���Ʊ����
	int *arrTicketNum;						//����ÿ�����ڵ���Ʊ����
	//int *iarrSelled;							//�ܵ���Ʊ��
	//int *mTicketRepeat;						//�߳�ÿ��Ʊ����������
	//int iLeakNum;								//©Ʊ
	//int iRepeatNum;							//��Ʊ
								
	
public:
	pTicket();
	pTicket(int);
	~pTicket();
	//void init(CRITICAL_SECTION);
	void setSellerNum(int,int);
	DWORD threadFunc(LPVOID);					//�봴���߳�֮��Ĳ�������	
	//void print();								
	
};