#pragma once
//�û���Ϣ
#include<string>
using namespace std;
class CUser
{
public:
	CUser(void);
	CUser(unsigned long nConnID,string strIPNet="",string strIPLocal="",string strRemark="",
		string strSYS="",string strFilter="",string strDelay="",string strSetupTime="",
		string strMac="",string strCpu="",string strFree="",string strActTime="");
	~CUser(void);
public:	
	unsigned long m_nConnID;
	string        m_strIPNet;//������ַ
	string        m_strIPLocal;//���ص�ַ
	string        m_strRemark;//�������/��ע
	string        m_strSYS;//����ϵͳ
	string        m_strFilter;//ɸѡ
	string        m_strDelay;//�ӳ�
	string        m_strSetupTime;//��װʱ��
	string        m_strMac;//�����ַ
	string        m_strCpu;//Cpu/Mhz
	string        m_strFree;//����
	string        m_strActTime;//�ʱ��
};

