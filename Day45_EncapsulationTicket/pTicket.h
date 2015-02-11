#pragma  once
#include "pThread.h"

class pTicket:public threadInterface{
	int iSellerNum;								//总的卖票窗口
	int *arrTicketNum;						//给定每个窗口的卖票张数
	//int *iarrSelled;							//总的卖票数
	//int *mTicketRepeat;						//线程每个票号卖的张数
	//int iLeakNum;								//漏票
	//int iRepeatNum;							//重票
								
	
public:
	pTicket();
	pTicket(int);
	~pTicket();
	//void init(CRITICAL_SECTION);
	void setSellerNum(int,int);
	DWORD threadFunc(LPVOID);					//与创建线程之间的参数传递	
	//void print();								
	
};