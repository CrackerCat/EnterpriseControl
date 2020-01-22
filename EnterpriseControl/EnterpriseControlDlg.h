
// EnterpriseControlDlg.h : header file
//

#pragma once
#include "stdafx.h"
#include "MainBusiness.h"
#define CDialogSampleDlgBase CXTPDialogBase<CXTResizeDialog>
// CEnterpriseControlDlg dialog
class CEnterpriseControlDlg : public CDialogSampleDlgBase
{
// Construction
public:
	CEnterpriseControlDlg(CWnd* pParent = NULL);	// standard constructor
	void                   DelItemUserReal(CUser User2Rem);
	VOID OnRemoveUser(CUser User2Rem);

// Dialog Data
	enum { IDD = IDD_ENTERPRISECONTROL_DIALOG };

	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
public:
	HICON m_hIcon;
	//״̬��
	CXTPStatusBar          m_wndStatusBar;
	void                   InitStatusBar();
	void                   UpdateConnCount();
	//�˵���������
	void                   IntMenuAndToolBar();
	void                   OnMenuAndToolBarCommandRange(UINT nID);//�˵�������������¼�(��ĳID��ʼ��ĳID����)
	//��־
	CXTPDockingPaneManager m_paneManager;
	CEdit                  m_wndEdit;
	CFont                  m_fntEdit;
	void                   InitLog();
	void                   CreateLogEdit(CXTPDockingPane* pPane);//������־���ڵı༭��
	void                   AddLog(CString csData);
	//�б�	
	CImageList             m_imageList;	
	CXTPReportControl      m_wndReport;
	void                   InitReport();	
	void                   ReportGroupAddChild(CXTPReportRecord  *pRecord,CUser user);
	BOOL SortItemGroup(CXTPReportRecord  *pRecord);

	BOOL SortItemGroupEx();
	int SortMethod;
	int Sort_Down;
	CXTPReportRecord  *pRecordSort;

	void                   AddItemUser();
	void                   DelItemUser();
	//�ı䴰�����пؼ���λ��
	BOOL                   m_bInRepositionControls;
	BOOL                   m_bInitDone;
	void                   RepositionControls();


	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	afx_msg LRESULT OnDockingPaneNotify(WPARAM wParam, LPARAM lParam);//�зִ���֪ͨ�¼�
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	afx_msg LRESULT OnUpdatePort(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnUpdateReport(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnAddLogNew(WPARAM wParam, LPARAM lParam);
	afx_msg void OnClose();	
	afx_msg void OnReportColumnRClick(NMHDR * pNotifyStruct, LRESULT * result);
	afx_msg void OnReportItemRClick(NMHDR * pNotifyStruct, LRESULT * result);
	afx_msg void OnReportItemClick(NMHDR * pNotifyStruct, LRESULT * result);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()	
};
