// Day45_EncapsulationTicket.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "pTicket.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	const int num=10;
	pTicket test1(10);									//实例化继承自接口的类	
	for(int i=0;i<num;i++){
		test1.setSellerNum(i,(i+1)*10);
	}	
	HANDLE hThread[num];								//线程句柄数组
	pThread *thread=new pThread[num];					//初始化多个线程类对象
	for(int i=0;i<num;i++){			
		thread[i]=pThread(&test1,(void*)i);		
		hThread[i]=thread[i].createThread();			//创建线程		
	}
	WaitForMultipleObjects(num,hThread,true,INFINITE);	
	return 0;
}

