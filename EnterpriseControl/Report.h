#pragma once
//�б�
#include "Group.h"
#include<list>
class CReport
{
public:
	CReport(void);
	~CReport(void);
private:
	CRITICAL_SECTION  m_crit_User;
	map<string,CGroup>m_mapGroup;//keyΪ����
	CRITICAL_SECTION  m_cs_CloseUser;
	list<int>         m_listCloseUser;//�ر��û�
	CUser             m_UserUpdate;//��ǰ���/ɾ��/�޸ĵ��û�
	CUser             m_curSelUser;	//��ǰѡ����û�
public:
	string          GetGroupName(CUser user);//��ȡ����
	int             GetGroupUserSize(string strName);//��ȡ���û���С
	int             GetAllGroupUserSize();//��ȡ�������û���С
	void            GroupAddUser(const string strGroupName,CUser user);//������û�
	CUser           GroupDelUser(unsigned long dwConnID);//��ɾ���û�	
	void            GetAllGroup(map<string,CGroup>&mapAllGroup);//��ȡ����������
	void            AddCloseUser(const unsigned long nConnID);//��ӹرյ��û�
	void            GetCloseUser(list<int>&listCloseUser);//��ȡ�رյ��û�
	void            DelCloseUser(const unsigned long nConnID);//ɾ���رյ��û�
    void            SetUserUpdate(CUser user);//���õ�ǰ���/ɾ��/�޸ĵ��û�
	CUser           GetUserUpdate();//��ȡ��ǰ���/ɾ��/�޸ĵ��û�
	void            SetCurSelUser(unsigned long dwConnID);//���õ�ǰѡ����û�
	CUser           GetCurSelUser();//��ȡ��ǰѡ����û�	
};

