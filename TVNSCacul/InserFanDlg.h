#pragma once
#include "afxwin.h"
#include "resource.h"

// InserFanDlg 对话框

class InserFanDlg : public CDialog
{
	DECLARE_DYNAMIC(InserFanDlg)

public:
	InserFanDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~InserFanDlg();

// 对话框数据
	enum { IDD = IDD_INSERTFAN_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_fanName;
	CString m_minQ;
	CString m_maxQ;
	CString m_minH;
	CString m_maxH;
	CString m_power;
	CComboBox m_methodCmBox;
	afx_msg void OnBnClickedOk();

protected:
	virtual BOOL OnInitDialog();
};
