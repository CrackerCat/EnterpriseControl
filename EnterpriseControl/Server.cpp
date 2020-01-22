#include "StdAfx.h"
#include "Server.h"
#include "MainBusiness.h"

CServer::CServer(void):m_pServer(this)
{
}


CServer::~CServer(void)
{
}

void  CServer::Start(USHORT usPort)
{
	m_pServer->Start(_T("0.0.0.0"), usPort);
}


EnHandleResult CServer::OnPrepareListen(ITcpServer* pSender, SOCKET soListen)
{
	TCHAR szAddress[50];
	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
	USHORT usPort;
	
	pSender->GetListenAddress(szAddress, iAddressLen, usPort);
	return HR_OK;
}

EnHandleResult CServer::OnAccept(ITcpServer* pSender, CONNID dwConnID, SOCKET soClient)
{	
	return HR_OK;
}


EnHandleResult CServer::OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	return HR_OK;
}

char* MyDecode(char *data,int len)
{
	for (int i = 0; i < len; i++)
	{
		data[i] += 0x86;
		data[i] ^= 0x19;
	}
	return data;
}

EnHandleResult CServer::OnReceive(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{	
	// ��������
	MyDecode((char*)pData,iLength);
	//ճ������
	memcpy(m_stPackBuf.pBuf + m_stPackBuf.nStartLen, pData, iLength);
	m_stPackBuf.nStartLen += iLength;
	if( m_stPackBuf.nStartLen >= HDR_SIZE )
	{		
		BYTE cPacketFlag[FLAG_SIZE]={0};//���ݰ���־
		int  nSize = 0;//�������ݰ���С
		BOOL bZilb = FALSE;//�Ƿ�Ҫ��ѹ
		int nUnCompressLength = 0;//ѹ���Ĵ�С

		memcpy((PBYTE) &cPacketFlag, m_stPackBuf.pBuf , FLAG_SIZE);
		m_stPackBuf.nStartLen -= FLAG_SIZE;
		memmove(m_stPackBuf.pBuf,  m_stPackBuf.pBuf+FLAG_SIZE, m_stPackBuf.nStartLen);

		memcpy((PBYTE) &nSize, m_stPackBuf.pBuf , sizeof(int));
		m_stPackBuf.nStartLen -= sizeof(int);
		memmove(m_stPackBuf.pBuf,  m_stPackBuf.pBuf+sizeof(int), m_stPackBuf.nStartLen);

		memcpy((PBYTE) &nUnCompressLength, m_stPackBuf.pBuf , sizeof(int));
		m_stPackBuf.nStartLen -= sizeof(int);
		memmove(m_stPackBuf.pBuf,  m_stPackBuf.pBuf+sizeof(int), m_stPackBuf.nStartLen);

		memcpy((PBYTE) &bZilb, m_stPackBuf.pBuf , sizeof(BOOL));
		m_stPackBuf.nStartLen -= sizeof(int);
		memmove(m_stPackBuf.pBuf,  m_stPackBuf.pBuf+sizeof(BOOL), m_stPackBuf.nStartLen);	
		int	nCompressLength = nSize - HDR_SIZE;//��ѹ�Ĵ�С(ȥ����ͷ��ģ����ݴ�С)		
		if(nCompressLength > 0)
		{
			BYTE*  pBuffer = NULL;
			if(nCompressLength < m_stPackBuf.nStartLen )//���ջ������� �ж���һ����
			{
				pBuffer = new BYTE[nCompressLength + 1]; 
				memset(pBuffer, 0, nCompressLength+1);
				memcpy(pBuffer, m_stPackBuf.pBuf , nCompressLength);
				m_stPackBuf.nStartLen -= nCompressLength;
				memmove(m_stPackBuf.pBuf,  m_stPackBuf.pBuf+nCompressLength, m_stPackBuf.nStartLen);
			}
			else if(nCompressLength == m_stPackBuf.nStartLen)//���ջ���������һ�������İ�
			{
				pBuffer = new BYTE[nCompressLength + 1]; 
				memset(pBuffer, 0, nCompressLength+1);
				memcpy(pBuffer, m_stPackBuf.pBuf, nCompressLength);
				m_stPackBuf.nStartLen = 0;
			}		
			else //���ջ�������  ��û��һ�������İ�, ֻ�а��Ĳ������ݡ�
			{
				if(nCompressLength + m_stPackBuf.nStartLen >= MAX_RECV_BUFFER)//�����ȱ��������ջ��������Ȼ�Ҫ��˵�������Ѿ����ˣ���Ҫ�������ӡ�
				{
					LOG(INFO) <<"�����ȱ��������ջ��������Ȼ�Ҫ��˵�������Ѿ����ˣ���Ҫ��������";
				}
				else
				{
					LOG(INFO) <<"��û��һ�������İ�";
				}
			}
			if( pBuffer != NULL )
			{
				if(bZilb == ZLIB_OK)   //������Ҫ��ѹ��
				{
					unsigned long	destLen = nUnCompressLength;
					PBYTE pDeCompressionData = new BYTE[nUnCompressLength];
					/*int nRet = uncompress(pDeCompressionData, &destLen, pBuffer, nCompressLength);
					if (nRet == Z_OK)
					{
						CMainBusiness::GetInstance()->DisposeBusiness(pSender, dwConnID, pDeCompressionData);
					}*/
					delete [] pDeCompressionData;
				}
				else
				{
					CMainBusiness::GetInstance()->DisposeBusiness(pSender, dwConnID, pBuffer);
				}
				delete []pBuffer;
			}
		}
	}
	else if( 0 < m_stPackBuf.nStartLen && m_stPackBuf.nStartLen < HDR_SIZE )
	{
		LOG(INFO) <<"��ͷ���ֶ�û������";
	}
	
	return HR_OK;
}

EnHandleResult CServer::OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	CMainBusiness::GetInstance()->Close(dwConnID);	
	return HR_OK;
}


EnHandleResult CServer::OnShutdown(ITcpServer* pSender)
{
	return HR_OK;
}

EnHandleResult  CServer::SendData(CONNID dwConnID, const BYTE* pData, int iLength)
{
	if(m_pServer->Send(dwConnID, pData, iLength))
		return HR_OK;
	return HR_ERROR;
}