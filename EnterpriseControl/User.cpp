#include "StdAfx.h"
#include "User.h"


CUser::CUser(void)
{
}


CUser::~CUser(void)
{
}

CUser::CUser(unsigned long nConnID,string strIPNet,string strIPLocal,string strRemark,
		string strSYS,string strFilter,string strDelay,string strSetupTime,
		string strMac,string strCpu,string strFree,string strActTime)
{
	m_nConnID=nConnID;
	m_strIPNet=strIPNet;//������ַ
	m_strIPLocal=strIPLocal;//���ص�ַ
	m_strRemark=strRemark;//�������/��ע
	m_strSYS=strSYS;//����ϵͳ
	m_strFilter=strFilter;//ɸѡ
	m_strDelay=strDelay;//�ӳ�
	m_strSetupTime=strSetupTime;//��װʱ��
	m_strMac=strMac;//�����ַ
	m_strCpu=strCpu;//Cpu/Mhz
	m_strFree=strFree;//����
	m_strActTime=strActTime;//�ʱ��
}