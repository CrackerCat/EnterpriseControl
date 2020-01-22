#pragma once
#include "Report.h"
#include "Server.h"
//��ҵ��
class CMainBusiness
{
private:  
	CMainBusiness();
	virtual ~CMainBusiness(void);
	static CMainBusiness *m_pInstance;  
public:  
	static CMainBusiness * GetInstance()  
	{  
		if(m_pInstance == NULL)  //�ж��Ƿ��һ�ε���  
		{
			m_pInstance = new CMainBusiness(); 
		}
		return m_pInstance;  
	} 
public:
	void                  Init(HWND hwnd);
	void                  SetPort(unsigned short nPort);//���ö˿ڣ�����ʼ����
	void                  DisposeBusiness(ITcpServer* pSender, CONNID dwConnID, const BYTE* pRecvData);//����ҵ��	
	void                  Close(CONNID dwConnID);	//�ر��û�
	void                  AddThread();//���һ���߳���
	void                  AddExitThread();//���һ���˳��߳���	
	bool                  GetExit();//��ȡ�Ƿ��˳�
	void                  SetExit();//�����˳�
	bool                  WaitAllThreadExit();//�ȴ������߳��˳�	
	CReport               GetReport();//��ȡ�б�
private:
	CReport               m_Report;   //�б�
	CServer               m_Server;   //ͨ��
	HWND                  m_hWnd;
	unsigned short        m_nPort;
	bool                  m_bExit;
	int                   m_nThreadTotal;//�߳�����
	int                   m_nExitThreadTotal;//�˳��߳�����	
private:
	void                  Login(CONNID dwConnID,ITcpServer* pSender,const BYTE* pData);//��½
	string                GetUserSYS(void*	pLoginInfo);	
	static DWORD WINAPI   CloseUserThread(LPVOID lpParam);//�û��˳��߳�
};

