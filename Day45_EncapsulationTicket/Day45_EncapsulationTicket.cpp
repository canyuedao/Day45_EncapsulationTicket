// Day45_EncapsulationTicket.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "pTicket.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	const int num=10;
	pTicket test1(10);									//ʵ�����̳��Խӿڵ���	
	for(int i=0;i<num;i++){
		test1.setSellerNum(i,(i+1)*10);
	}	
	HANDLE hThread[num];								//�߳̾������
	pThread *thread=new pThread[num];					//��ʼ������߳������
	for(int i=0;i<num;i++){			
		thread[i]=pThread(&test1,(void*)i);		
		hThread[i]=thread[i].createThread();			//�����߳�		
	}
	WaitForMultipleObjects(num,hThread,true,INFINITE);	
	return 0;
}

