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
DWORD pTicket::threadFunc(LPVOID pPM){				//与创建线程之间的参数传递	
	int iTickerTotal=arrTicketNum[(int)pPM];		//线程的总票数
	int iTicketNum=0;								//票号
	//iarrSelled[(int)pPM]=0;
	int *iTicketRepeat=new int[iTickerTotal];		//线程每个票号卖的张数数组
	memset(iTicketRepeat,0,iTickerTotal*4);			//初始化票号卖的张数
	while(iTicketNum<iTickerTotal){
		int itemp=iTicketNum;	
		iTicketNum++;						
		printf("%d号窗口买票 %d\n",(int)pPM,itemp);
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
//		printf("%d窗口\n漏票 %d\n重票 %d\n总票 %d\n",i,iLeakNum,iRepeatNum,iarrSelled[i]);
//
//	}	
//}

pTicket::~pTicket(){
	delete arrTicketNum;
	//delete iarrSelled;
	//delete mTicketRepeat;
}