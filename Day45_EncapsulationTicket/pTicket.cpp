#include "pTicket.h"
#include <stdio.h>


pTicket::pTicket(int inum){
	iSellerNum=inum;
	arrTicketNum=new int[iSellerNum];
	//iarrSelled=new int[iSellerNum];
	//iLeakNum=0;								
	//iRepeatNum=0;
	
}

void pTicket::setSellerNum(int iindex,int inum){
	arrTicketNum[iindex]=inum;
}
DWORD pTicket::threadFunc(LPVOID pPM){				//�봴���߳�֮��Ĳ�������	
	int iTickerTotal=arrTicketNum[(int)pPM];		//�̵߳���Ʊ��
	int iTicketNum=0;								//Ʊ��
	//iarrSelled[(int)pPM]=0;
	int *iTicketRepeat=new int[iTickerTotal];		//�߳�ÿ��Ʊ��������������
	memset(iTicketRepeat,0,iTickerTotal*4);			//��ʼ��Ʊ����������
	while(iTicketNum<iTickerTotal){
		int itemp=iTicketNum;	
		iTicketNum++;						
		printf("%d�Ŵ�����Ʊ %d\n",(int)pPM,itemp);
		//iTicketRepeat[itemp]++;	 		
		//iarrSelled[(int)pPM]++;		
	}	
	
	//mTicketRepeat=iTicketRepeat;
	return (DWORD)iTicketRepeat;
}

//void pTicket::print(){
//	for(int i=0;i<iSellerNum;i++){											
//		for(int j=0;j<arrTicketNum[i];j++){
//			if(mTicketRepeat[j]==0){
//				iLeakNum++;
//			}
//			else if(mTicketRepeat[j]>1){
//				iRepeatNum+=mTicketRepeat[j]-1;
//			}
//		}
//		printf("%d����\n©Ʊ %d\n��Ʊ %d\n��Ʊ %d\n",i,iLeakNum,iRepeatNum,iarrSelled[i]);
//
//	}	
//}

pTicket::~pTicket(){
	delete arrTicketNum;
	//delete iarrSelled;
	//delete mTicketRepeat;
}