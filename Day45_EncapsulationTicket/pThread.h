
#include <Windows.h>
class threadInterface{	
public:
	virtual DWORD threadFunc(LPVOID pPM)=0;
};
class pThread{	

	DWORD dwResult;

	LPDWORD pThreadID;										//�߳�IDָ��

	void *pArgList;											//�߳���ص�����ͨѶ��

	LPVOID lpParameterList;									//�߳�֮��ͨѶ�Ĵ��ݲ���

	HANDLE hThread;

	threadInterface *pthreadInce;

	//**************************************//
	//�̻߳ص�����
	//**************************************//
public:
	static DWORD WINAPI pThreadFunc(LPVOID lpParameter){
		((pThread*)lpParameter)->dwResult=((pThread*)lpParameter)->pthreadInce->threadFunc(((pThread*)lpParameter)->lpParameterList);	//�̻߳ص���������ýӿں���
		return ((pThread*)lpParameter)->dwResult;
	}
	
public:
	
	pThread();												//Ĭ�Ϲ��캯�������ڳ�ʼ���������
	
	pThread(threadInterface *ince,LPVOID lpParameterList=NULL);	//���캯�������ݻص�����ָ��Ͳ���ָ��
	
	~pThread();												//�ͷ��̶߳����IDָ��
	
	void operator=(pThread&);								//������ֵ��������������߳�IDָ��
	
	HANDLE createThread();									//�����̶߳��󣬷��ؾ��
	
	DWORD getThreadID();									//��ȡ�߳�ID

	DWORD getResult();
	
};