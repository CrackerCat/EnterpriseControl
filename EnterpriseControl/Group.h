#pragma once
//��
#include "User.h"
#include<map>
class CGroup
{
public:
	CGroup(void);
	~CGroup(void);
public:
	map<unsigned long,CUser>m_mapUser;//keyΪidҲΪͨ�ŵ�connid
};

