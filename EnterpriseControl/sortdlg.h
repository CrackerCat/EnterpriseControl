#pragma once


// sortdlg �Ի���

class sortdlg : public CDialogEx
{
	DECLARE_DYNAMIC(sortdlg)

public:
	int* SortMethod;
	sortdlg(CWnd* pParent = nullptr);   // ��׼���캯��
	virtual ~sortdlg();
	BOOL OnInitDialog();
	CButton * NewMyButton(CString cstr, int nID, CRect rect, int nStyle);
	CButton *p_MyBut[12];

	// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_sortdlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
public:

	afx_msg void OnMybut1();
	afx_msg void OnMybut2();
	afx_msg void OnMybut3();
	afx_msg void OnMybut4();
	afx_msg void OnMybut5();
	afx_msg void OnMybut6();
	afx_msg void OnMybut7();
	afx_msg void OnMybut8();
	afx_msg void OnMybut9();
	afx_msg void OnMybut10();
	afx_msg void OnMybut11();
	afx_msg void OnMybut12();

	DECLARE_MESSAGE_MAP()
};
