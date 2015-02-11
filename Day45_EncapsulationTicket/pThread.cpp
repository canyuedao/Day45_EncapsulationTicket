#include "stdafx.h"
#include "pThread.h"

//***********************************//
//Ĭ�Ϲ��캯�������ڳ�ʼ���������
//***********************************//
pThread::pThread(){
	lpParameterList=NULL;
	pArgList=this;
	hThread=NULL;
	pThreadID=new DWORD;
	pthreadInce=NULL;
}


//***************************************//
//���캯��������ʵ�ֽӿ���Ķ���Ͳ���ָ��
//***************************************//
pThread::pThread(threadInterface *ince,LPVOID pPM){
	lpParameterList=pPM; 
	pArgList=this;
	hThread=NULL;
	pThreadID=new DWORD;
	pthreadInce=ince;
}


//*****************************************************************//
//������ֵ��������������߳�IDָ�룬ֻ�����ӿ�������ָ��Ͳ���ָ��
//*****************************************************************//
void pThread::operator=(pThread&rhs){	
	this->lpParameterList=rhs.lpParameterList;
	this->pthreadInce=rhs.pthreadInce;
}


//**********************//
//�ͷ��̶߳����IDָ��
//**********************//
pThread::~pThread(){	
	CloseHandle(hThread);
	delete pThreadID;
}


//**********************//
//�����̶߳��󣬷��ؾ��
//**********************//
HANDLE pThread::createThread(){	
	hThread=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)pThreadFunc,pArgList,0,pThreadID);		
	return hThread;
}


//**********************//
//��ȡ�߳�ID
//**********************//
DWORD pThread::getThreadID(){
	return *pThreadID;
}


DWORD pThread::getResult(){
	return dwResult;
}